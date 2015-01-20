#include "cserver.h"

CServer::CServer(QObject *parent) :
    QTcpServer(parent)
{
}

void CServer::startServer()
{
    if(listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server: started";
    }
    else
    {
        qDebug() << "Server: not started!";
    }
}

void CServer::incomingConnection(qintptr socketDescriptor)
{
    // At the incoming connection, make a client
    // and set the socket
    CClient *client = new CClient(this);
    client->setSocket(socketDescriptor);
}
