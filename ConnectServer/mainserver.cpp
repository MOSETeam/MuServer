#include "mainserver.h"

namespace MOSE {
namespace CONNECTSERVER {
namespace MainServer {

MOSE::TCPServer::TCPServer* server = NULL;

void main() {
    int port = MOSE::Configuration::getGlobal()->value("port").toInt();
    int maxclients = MOSE::Configuration::getGlobal()->value("maxclients").toInt();

    server = new MOSE::TCPServer::TCPServer(0, port, maxclients);

    server->bind_onConnect(onConnect);
    server->bind_onDisconnect(onDisconnect);
    server->bind_onReceive(onReceive);
    server->bind_onMaxClients(onMaxClients);
}

void onMaxClients(qintptr handle) {
    QTcpSocket* sock;
    sock = new QTcpSocket();
    sock->setSocketDescriptor(handle);
    sock->deleteLater();
    delete sock;
}

void onConnect(int index) {
    qDebug() << "[MainServer]" << "[ ID:" << index << "]" << "Client connected";
    MOSE::CONNECTSERVER::Protocol::WelcomeMessage().send(index);
}

void onDisconnect(int index) {
    qDebug() << "[MainServer]" << "[ ID:" << index << "]" << "Client disconnected";
}

void onReceive(int index, char* buffer, int size) {
    MOSE::CONNECTSERVER::Protocol::ProtocolCore(index, buffer, size);
}

void send(int index, QByteArray buffer) {
    if(MOSE::TCPServer::getClient(index) != NULL) {
        MOSE::TCPServer::getClient(index)->send(buffer);
    }
    else {
        qWarning() << "[MainServer]" << "Can not write to non exist client";
    }
}

void close(int index) {
    if(MOSE::TCPServer::getClient(index) != NULL) {
        MOSE::TCPServer::getClient(index)->close();
    }
    else {
        qWarning() << "[MainServer]" << "Can not close non exist client";
    }
}

}
}
}
