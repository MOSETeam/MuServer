#include "welcomemessage.h"

namespace MOSE {
namespace CONNECTSERVER {
namespace Protocol {

WelcomeMessage::WelcomeMessage() {
}

void WelcomeMessage::send(int index) {
    qDebug() << "[Protocol]" << "[ ID:" << index << "]" << "WelcomeMessage::send";

    MSG_HELLO pMsg;
    pMsg.header.type = 0xC1;
    pMsg.header.size = sizeof(pMsg);
    pMsg.header.protocol = 0x00;
    pMsg.result = 0x01;

    MOSE::CONNECTSERVER::MainServer::send(index, QByteArray((char*)&pMsg, sizeof(pMsg)));
}

}
}
}
