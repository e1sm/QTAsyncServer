#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include "cclient.h"

class CServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit CServer(QObject *parent = 0);
    void startServer();

protected:
    void incomingConnection(qintptr socketDescriptor);

signals:

public slots:

};

#endif // CSERVER_H
