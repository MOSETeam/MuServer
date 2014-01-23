#ifndef SERVERLIST_H
#define SERVERLIST_H

#include "mainserver.h"
#include "protocol/structs.h"
#include "../include/configuration.h"

namespace MOSE {
namespace CONNECTSERVER {
namespace Protocol {

class ServerList
{
public:
    ServerList();
    void recv(int index);
    void send(int index);
    void select(int index, char Group, char Server);

private:
    LIST_GROUP m_ServerList[19];
};

}
}
}

#endif // SERVERLIST_H
