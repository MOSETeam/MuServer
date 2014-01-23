#ifndef WELCOMEMESSAGE_H
#define WELCOMEMESSAGE_H

#include "mainserver.h"
#include "protocol/structs.h"

namespace MOSE {
namespace CONNECTSERVER {
namespace Protocol {

class WelcomeMessage
{
public:
    WelcomeMessage();
    void send(int index);
};

}
}
}

#endif // WELCOMEMESSAGE_H
