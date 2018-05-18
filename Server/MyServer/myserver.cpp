#include "myserver.h"

MyServer::MyServer(QObject * parent):
    QTcpServer(parent)
{
    if(listen(QHostAddress::Any, 80)) {

    }
    else {

    }
}

void MyServer::incomingConnection(int handle)
{
    MyThreadSocket * threadSocket = new MyThreadSocket(handle);
    connect(threadSocket, SIGNAL(finished()),
            threadSocket, SLOT(deleteLater()));
    threadSocket->start();
}
