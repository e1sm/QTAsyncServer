//bug557
#include <QCoreApplication>
#include "cserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create an instance of a server and then start it.
    CServer server;
    server.startServer();

    return a.exec();
}
