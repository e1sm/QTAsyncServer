#include "ctask.h"
#include "cserver.h"
#include <QDebug>

CTask::CTask(QObject *parent)
{
    this->parent = parent;
}

// When the thread pool kicks up
// it's going to hit this run, and it's going to do this time consuming task.
// After it's done, we're going to send the results back to our main thread.
// This runs in the separate thread, and we do not have any control over this thread,
// but Qt does.
// This may just stay in the queue for several ms depending on how busy the server is.

void CTask::run()
{
    // time consumer
    QMutexLocker locker(&mutex);
    CServer *srv = (CServer *)parent;
    qDebug() << " 22 " << srv->tm;
    srv->tm = 5;

    qDebug() << "CTask()";

    qDebug() << "Task started";

    int iNumber = 0;
    for(int i = 0; i < 100; i++)
    {
        iNumber += 1;
    }

    qDebug() << "Task done";
    emit Result(iNumber);
}
