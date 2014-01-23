#include "serverlist.h"

namespace MOSE {
namespace CONNECTSERVER {
namespace Protocol {

ServerList::ServerList() {
    strcpy(this->m_ServerList[0].servers[0].address, MOSE::Configuration::getGlobal()->value(QString("servers")).toObject().value(QString("0")).toObject().value(QString("0")).toObject().value(QString("address")).toString().toStdString().c_str());
    this->m_ServerList[0].servers[0].port = MOSE::Configuration::getGlobal()->value(QString("servers")).toObject().value(QString("0")).toObject().value(QString("0")).toObject().value(QString("port")).toInt();
}

void ServerList::recv(int index) {
    qDebug() << "[Protocol]" << "[ ID:" << index << "]" << "ServerList::recv";
    this->send(index);
}

void ServerList::send(int index) {
    qDebug() << "[Protocol]" << "[ ID:" << index << "]" << "ServerList::send - todo..";
    this->select(index, 0x00, 0x00);
}

void ServerList::select(int index, char Group, char Server) {
    MSG_SERVERINFO pMsg;
    pMsg.header.type = 0xC1;
    pMsg.header.size = sizeof(pMsg);
    pMsg.header.protocol = 0xF4;
    pMsg.subprotocol = 0x03;
    memset(pMsg.address, 0x00, sizeof(pMsg.address));

    strcpy(pMsg.address, this->m_ServerList[(int)Group].servers[(int)Server].address);
    pMsg.port = this->m_ServerList[(int)Group].servers[(int)Server].port;

    qDebug() << "[Protocol]" << "[ ID:" << index << "]" << "ServerList::select -" << pMsg.address << ":" << pMsg.port;

    MOSE::CONNECTSERVER::MainServer::send(index, QByteArray((char*)&pMsg, sizeof(pMsg)));
}

}
}
}
