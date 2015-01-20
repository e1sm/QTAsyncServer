#ifndef CCLIENT_H
#define CCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>
#include "ctask.h"

class CClient : public QObject
{
    Q_OBJECT
public:
    explicit CClient(QObject *parent = 0);
    void setSocket(qintptr Descriptor);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();

    // make the server fully ascynchronous
    // by doing time consuming task
    void TaskResult(int Number);

private:
    QTcpSocket *socket;

};

#endif // CCLIENT_H
