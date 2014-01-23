#include "connectserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    MOSE::Logger::main("ConnectServer");

    MOSE::Configuration::loadGlobal("connectserver");

    MOSE::CONNECTSERVER::MainServer::main();

    return app.exec();
}
