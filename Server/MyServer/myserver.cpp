#include "myserver.h"

MyServer::MyServer(QObject * parent): QTcpServer(parent) {
    if(this->listen(QHostAddress::Any, 2323)) {
        qDebug() << "Listening port " << this->serverPort();
    }
    else {
        qDebug() << "No Listening";
    }
}

void MyServer::incomingConnection(qintptr handle) {
    qDebug() << "User has ben connected";
    MyThreadSocket * threadSocket = new MyThreadSocket(handle);
    connect(threadSocket, SIGNAL(finished()),
            threadSocket, SLOT(deleteLater()));
    threadSocket->start();
}
