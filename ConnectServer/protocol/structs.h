#ifndef STRUCTS_H
#define STRUCTS_H

namespace MOSE {
namespace CONNECTSERVER {
namespace Protocol {

struct LIST_SERVER {
    char address[16];
    unsigned short port;
};

struct LIST_GROUP {
    LIST_SERVER servers[19];
};

struct MSG_HEADER {
    char type;
    char size;
    char protocol;
};

struct MSG_HELLO {
    MSG_HEADER header;
    char result;
};

struct MSG_SERVERINFO {
    MSG_HEADER header;
    char subprotocol;
    char address[16];
    unsigned short port;
};

}
}
}

#endif // STRUCTS_H
