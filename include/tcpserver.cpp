#include "tcpserver.h"

namespace MOSE {
namespace TCPServer {

QMap<int, TCPClient*> clients;

// -----------------------------------------------------

TCPClient::TCPClient(QObject* parent, qintptr handle, int index, void (*onDisconnect)(int), void (*onReceive)(int, char*, int)) :
    QTcpSocket(parent), func_onDisconnect(onDisconnect), func_onReceive(onReceive), m_Index(index)
{
    if(this->setSocketDescriptor(handle) == false) {
        qDebug() << "[TCPClient]" << "Creating new client failed!";
        this->deleteLater();
        clients.remove(index);
    }
    else {
        connect(this, SIGNAL(disconnected()), this, SLOT(disconnect()));
        connect(this, SIGNAL(readyRead()), this, SLOT(receive()));
    }
}

void TCPClient::disconnect() {
    this->func_onDisconnect(this->m_Index);
    clients.remove(this->m_Index);
    this->deleteLater();
}

void TCPClient::close() {
    this->disconnect();
}

void TCPClient::receive() {
    char buffer[7024];
    int bufferSize;
    memset(buffer, 0x00, 7024);

    bufferSize = this->read((char*)buffer, 7024);
    this->func_onReceive(this->m_Index, buffer, bufferSize);
}

void TCPClient::send(QByteArray buffer) {
    if(this->isWritable() == true) {
        this->write(buffer);
        this->flush();
    }
}

// -----------------------------------------------------

TCPServer::TCPServer(QObject* parent, int port, int maxconnections) :
    QTcpServer(parent), m_MaxConnections(maxconnections)
{
    qDebug() << "[TCPSocket]" << "Preparing server to start";

    if(this->listen(QHostAddress::AnyIPv4, port) == true) {
        qDebug() << "[TCPServer]" << "Server is listening at port" << port << ", max connections:" << maxconnections;
    }
    else {
        qCritical() << "[TCPServer]" << "Server can not listen at port" << port;
    }
}

void TCPServer::incomingConnection(qintptr handle) {
    if(clients.size() == this->m_MaxConnections) {
        this->func_onMaxClients(handle);
        return;
    }

    for(int i=0; i<this->m_MaxConnections; i++) {
        if(clients.contains(i) == false) {
            clients.insert(i, new TCPClient(this, handle, i, this->func_onDisconnect, this->func_onReceive));
            this->func_onConnect(i);
            return;
        }
    }
}

void TCPServer::bind_onConnect(void (*pointer)(int)) {
    this->func_onConnect = pointer;
}

void TCPServer::bind_onDisconnect(void (*pointer)(int)) {
    this->func_onDisconnect = pointer;
}

void TCPServer::bind_onReceive(void (*pointer)(int, char*, int)) {
    this->func_onReceive = pointer;
}

void TCPServer::bind_onMaxClients(void (*pointer)(qintptr)) {
    this->func_onMaxClients = pointer;
}

// -----------------------------------------------------

TCPClient* getClient(int index) {
    if(clients.contains(index) == true) {
        return clients[index];
    }
    else {
        return NULL;
    }
}

}
}
