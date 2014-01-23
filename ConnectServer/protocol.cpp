#include "protocol.h"
#include <stdio.h>

namespace MOSE {
namespace CONNECTSERVER {
namespace Protocol {

void ProtocolCore(int index, char* aRecv, int aSize) {
    if(aRecv[1] != (char)aSize) {
        qDebug() << "[Protocol]" << "[ ID:" << index << "]" << "ProtocolCore - invalid packet size";
        return;
    }

    switch(aRecv[3]) {

        case 0x06:
            ServerList().recv(index);
            break;

        case 0x03:
            ServerList().select(index, aRecv[4], aRecv[5]);
            break;

        default:
            qDebug() << "[Protocol]" << "[ ID:" << index << "]" << "ProtocolCore - invalid packet";
            break;

    }
}

}
}
}
