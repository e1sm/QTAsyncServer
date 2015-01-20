#include "cclient.h"

CClient::CClient(QObject *parent) :
    QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(5);
}

void CClient::setSocket(qintptr descriptor)
{
    // make a new socket
    socket = new QTcpSocket(this);

    qDebug() << "A new socket created!";

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    socket->setSocketDescriptor(descriptor);

    qDebug() << " Client connected at " << descriptor;
}


// asynchronous - runs separately from the thread we created
void CClient::connected()
{
    qDebug() << "Client connected event";
}

// asynchronous
void CClient::disconnected()
{
    qDebug() << "Client disconnected";
}

// Our main thread of execution
// This happening via main thread
// Our code running in our current thread not in another QThread
// That's why we're getting the thread from the pool

void CClient::readyRead()
{
    qDebug() << "MyClient::readyRead()";
    qDebug() << socket->readAll();

    // Time consumer
    CTask *task = new CTask();
    task->setAutoDelete(true);

    // using queued connection
    connect(task, SIGNAL(Result(int)), this, SLOT(TaskResult(int)), Qt::QueuedConnection);

    qDebug() << "Starting a new task using a thread from the QThreadPool";

    // QThreadPool::globalInstance() returns global QThreadPool instance
    QThreadPool::globalInstance()->start(task);

}

// After a task performed a time consuming task,
// we grab the result here, and send it to client
void CClient::TaskResult(int Number)
{
    QByteArray Buffer;
    Buffer.append("\r\nTask result = ");
    Buffer.append(QString::number(Number));

    socket->write(Buffer);
}
