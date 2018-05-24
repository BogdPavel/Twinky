#include "myserver.h"

MyServer::MyServer(QObject * parent): QTcpServer(parent), nextBlockSize(0) {
    if(this->listen(QHostAddress::Any, 80)) {
        qDebug() << "Listening port " << this->serverPort();
    }
    else {
        qDebug() << "No Listening";
    }
    usersDB = QSqlDatabase::addDatabase("QMYSQL"); usersDB.setHostName("127.0.0.1");
    usersDB.setDatabaseName("chatusers"); usersDB.setUserName("root"); usersDB.setPassword("pavel");
    if(!usersDB.open()) {
        qDebug() << usersDB.lastError().text();
        //Send message with problem to clients
    }
    else qDebug() << "Success DB!";
}

void MyServer::incomingConnection(qintptr handle) {
    QTcpSocket * socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
}

void MyServer::slotReadyRead() {
    QTcpSocket * clientSocket = qobject_cast<QTcpSocket*>(sender());
    QDataStream clientReadStream(clientSocket);
    clientReadStream.setVersion(QDataStream::Qt_4_5);
    while(true) {
        if (!nextBlockSize) {
            if(clientSocket->bytesAvailable() < sizeof(quint16)) break;
            clientReadStream >> nextBlockSize;
        }
        if (clientSocket->bytesAvailable() < nextBlockSize) break;
        clientReadStream >> message;
        nextBlockSize = 0;
    }
    QString buffer(message.at(0));
    buffer += message.at(1);
    messageCode = buffer.toInt();
    switch(messageCode) {
    case SignIn: checkUserInDB(clientSocket); break;
    case SignUp: signUpNewUser(clientSocket); break;
    }
}

void MyServer::slotDisconnected() {
    qDebug() << "Disconnect";
}


void MyServer::checkUserInDB(QTcpSocket * clientSocket) {
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
    message.clear();
    QSqlQuery query = QSqlQuery(usersDB);
    query.exec("select username, password from user where Username = \'" + bufferUsername + "\'");
    query.next();
    if(query.value(0).toString() == bufferUsername) {
        if(query.value(1).toString() == bufferPassword)
            message.append("Ok");
        else message.append("Incorrect password");
    }
    else {
        message.append("Username error");
    }
    sendToClient(CheckUsernameAndPassword, clientSocket);
}

void MyServer::signUpNewUser(QTcpSocket * clientSocket) {
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
        query.exec("insert into user (Username, NameSurname, Password) values (\'" +
                   bufferUsername + "\',\'" + bufferNameSurname + "\',\'" + bufferPassword + "\')");
        query.exec("insert into userInfo (Username, Email) values (\'" +
                   bufferUsername + "\',\'" + bufferEmail + "\')");
        message.clear();
        message.append("Ok");
    }
    else {
        message.clear();
        message.append("Username already occupied");
    }
    sendToClient(SignUpNewUser, clientSocket);
}

void MyServer::sendToClient(QString code, QTcpSocket * clientSocket) {
    QString str(code + " " + message);
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    qDebug() << str;
    clientSocket->write(arrBlock);
    //clientSocket->disconnectFromHost();
}
