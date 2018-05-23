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
    qDebug() << socket->currentReadChannel();
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),
            this, SLOT(slotDisconnected()), Qt::DirectConnection);
    exec();
}

void MyThreadSocket::slotReadyRead() {
    qDebug() << "ReadyRead";
    QDataStream clientReadStream(socket);
    clientReadStream.setVersion(QDataStream::Qt_5_5);
    while(true) {
        if (!nextBlockSize) {
            if(socket->bytesAvailable() < sizeof(quint16))
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
    QString buffer(message.at(0));
    buffer += message.at(1);
    messageCode = buffer.toInt();
    qDebug() << messageCode;
    switch(messageCode) {
    case 0: qDebug() << "Convert Error"; break;
    case SignIn: checkUserInDB(); break;
    case SignUp: signUpNewUser(); break;
    }
}

void MyThreadSocket::slotDisconnected() {
    qDebug() << "Disconnected";
    socket->close();
    quit();
}


void MyThreadSocket::checkUserInDB() {
    QString bufferUsername;
    QString bufferPassword;
    int i = 3;
    while(true) {
        if(message.at(i) == ' ') {
            i++;
            break;
        }
        bufferUsername.append(message.at(i));
        i++;
    }
    bufferPassword.append(message.mid(i, message.length() - i));
    qDebug() << bufferUsername;
    qDebug() << bufferPassword;
    message.clear();
    QSqlQuery query = QSqlQuery(usersDB);
    if(query.exec("select Username, Password from user where Username = \'" + bufferUsername + "\'")) {
        qDebug() << query.value("Password").toString();
        if(query.value("Password").toString() == bufferPassword)
            message.append("Ok");
        else message.append("Incorrect password");
    }
    else {
        message.append("Username error");
    }
    sendToClient(CheckUsernameAndPassword);
}

void MyThreadSocket::signUpNewUser() {
    QString bufferUsername;
    int i = 3;
    while(true) {
        if(message.at(i) == ' ') {
            i++;
            break;
        }
        bufferUsername.append(message.at(i));
        i++;
    }
    QSqlQuery query = QSqlQuery(usersDB);
    if(!query.exec("select Username from user where Username = \'" + bufferUsername + "\'")) {
        int j = message.length();
        while(message.at(--j) != ' ');
        QString bufferEmail(message.mid(j + 1, message.length() - j + 1));
        int z = --j;
        while(message.at(--j) != ' ');
        QString bufferPassword(message.mid(j + 1, z - j));
        QString bufferNameSurname(message.mid(i, j - i));
        qDebug() << bufferUsername;
        qDebug() << bufferPassword;
        qDebug() << bufferNameSurname;
        qDebug() << bufferEmail;
        query.exec("insert into user (Username, NameSurname, Password) values (\'" +
                   bufferUsername + "\',\'" + bufferNameSurname + "\',\'" + bufferPassword + "\')");
        qDebug() << query.lastError().text();
        query.exec("insert into userInfo (Username, Email) values (\'" +
                   bufferUsername + "\',\'" + bufferEmail + "\')");
        qDebug() << query.lastError().text();
        message.clear();
        message.append("Ok");
    }
    else {
        message.clear();
        message.append("Username already occupied");
    }
    sendToClient(SignUpNewUser);
}

void MyThreadSocket::sendToClient(QString code) {
    QString str(code + " " + message);
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    qDebug() << str;
    socket->write(arrBlock);
}


