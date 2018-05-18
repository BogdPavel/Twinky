#include "mythreadsocket.h"

MyThreadSocket::MyThreadSocket(int socketDescriptor, QObject * parent):
    QThread(parent)
{
    this->socketDescriptor = socketDescriptor;
}

MyThreadSocket::~MyThreadSocket()
{
    delete socket;
}

void MyThreadSocket::run()
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),
            this, SLOT(slotDisconnected()), Qt::DirectConnection);
    exec();
}

void MyThreadSocket::slotReadyRead()
{
    //
    socket->disconnectFromHost();
}

void MyThreadSocket::slotDisconnected()
{
    socket->close();
    quit();
}


