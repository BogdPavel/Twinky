#include "mythreadsocket.h"

MyThreadSocket::MyThreadSocket(qintptr handle, QObject * parent):
    QThread(parent), myDescriptor(handle), nextBlockSize(0) {
    usersDB = QSqlDatabase::addDatabase("QMYSQL");
    usersDB.setHostName("127.0.0.1");
    usersDB.setDatabaseName("chatusers");
    usersDB.setUserName("root");
    usersDB.setPassword("pavel");
    if(!usersDB.open()) {
        qDebug() << usersDB.lastError().text();
    }
    else qDebug() << "Success DB!";
}

MyThreadSocket::~MyThreadSocket() {
    delete socket;
}

void MyThreadSocket::run() {
    socket = new QTcpSocket();
    socket->setSocketDescriptor(myDescriptor);
    qDebug() << "Socket descriptor - " << myDescriptor;
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),
            this, SLOT(slotDisconnected()), Qt::DirectConnection);
    exec();
}

void MyThreadSocket::slotReadyRead() {
    getMessage();
    QString buffer(message.at(0));
    buffer += message.at(1);
    messageCode = buffer.toInt();
    qDebug() << messageCode;
    switch(messageCode) {
        case 0: qDebug() << "Convert Error"; break;
        case SignIn: checkInDB(); break;
    }
    socket->disconnectFromHost();
}

void MyThreadSocket::slotDisconnected()
{
    socket->close();
    quit();
}

void MyThreadSocket::getMessage() {
    QDataStream clientReadStream(socket);
    clientReadStream.setVersion(QDataStream::Qt_5_5);
    while(true) {
        if (!nextBlockSize) {
            if (socket->bytesAvailable() < sizeof(quint16)) // are size data available
                break;
            clientReadStream >> nextBlockSize;
        }
        if (socket->bytesAvailable() < nextBlockSize) {
            break;
        }
        clientReadStream >> message;
        qDebug() << message;
        nextBlockSize = 0;
    }
}

void MyThreadSocket::checkInDB() {

}


