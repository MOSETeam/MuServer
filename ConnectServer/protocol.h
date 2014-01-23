#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "mainserver.h"
#include "protocol/structs.h"
#include "protocol/welcomemessage.h"
#include "protocol/serverlist.h"

namespace MOSE {
namespace CONNECTSERVER {
namespace Protocol {

void ProtocolCore(int index, char* aRecv, int aSize);

}
}
}

#endif // PROTOCOL_H
