#ifndef MAINSERVER_H
#define MAINSERVER_H

#include "../include/tcpserver.h"
#include "../include/configuration.h"
#include "protocol.h"

namespace MOSE {
namespace CONNECTSERVER {
namespace MainServer {

void main();
void onMaxClients(qintptr handle);
void onConnect(int index);
void onDisconnect(int index);
void onReceive(int index, char* buffer, int size);
void send(int index, QByteArray buffer);
void close(int index);

}
}
}

#endif // MAINSERVER_H
