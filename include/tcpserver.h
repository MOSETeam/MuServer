#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>

namespace MOSE {
namespace TCPServer {

class TCPClient : public QTcpSocket {
    Q_OBJECT
public:
    explicit TCPClient(QObject* parent = 0, qintptr handle = 0, int index = 0, void (*onDisconnect)(int) = 0, void (*onReceive)(int, char*, int) = 0);
    void close();
    void send(QByteArray buffer);

private:
    void (*func_onDisconnect)(int);
    void (*func_onReceive)(int, char*, int);
    int m_Index;

signals:
    //

public slots:
    //

private slots:
    void disconnect();
    void receive();

};

// -----------------------------------------------------

class TCPServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = 0, int port = 0, int maxconnections = 0);
    void bind_onConnect(void (*pointer)(int));
    void bind_onDisconnect(void (*pointer)(int));
    void bind_onReceive(void (*pointer)(int, char*, int));
    void bind_onMaxClients(void (*pointer)(qintptr));

private:
    int m_MaxConnections;
    void (*func_onConnect)(int);
    void (*func_onDisconnect)(int);
    void (*func_onReceive)(int, char*, int);
    void (*func_onMaxClients)(qintptr);

    void incomingConnection(qintptr handle);

signals:
    //

public slots:
    //

};

// -----------------------------------------------------

TCPClient* getClient(int index);

}
}

#endif // TCPSERVER_H
