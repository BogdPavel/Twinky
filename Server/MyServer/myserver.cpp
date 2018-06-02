#include "myserver.h"

MyServer::MyServer(QObject * parent): QTcpServer(parent), nextBlockSize(0) {
    this->listen(QHostAddress::Any, 80);
    usersDB = QSqlDatabase::addDatabase("QSQLITE");
    usersDB.setDatabaseName("D:/Course Projects/4-th semestr/Twinky/Server/MyServer/chatDataBase.db");
    usersDB.open();
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
    messageCode = message.mid(0, 2).toInt();
    QString bufferUsername;
    int i = 3;
    while(i < message.length() && message.at(i) != ' ') {
        bufferUsername.append(message.at(i));
        i++;
    }
    switch(messageCode) {
    case SendMessage: sendChatMessageToUsers(bufferUsername); break;
    case SignIn: checkUserInDB(clientSocket); break;
    case SignUp: signUpNewUser(clientSocket); break;
    case GetUserInfo: getUserInfo(clientSocket, bufferUsername); break;
    case GetHistoryIndex: returnChatHistoryIndex(clientSocket); break;
    case GetHistoryUsername: returnChatHistoryUsername(clientSocket, bufferUsername); break;
    case GetChatPos: returnChatPosition(clientSocket, bufferUsername); break;
    }
}

void MyServer::sendChatMessageToUsers(QString username) {
    int i = 2;
    while(message.at(++i) != ' '); i++;
    QString time(QTime::currentTime().toString().mid(0, 8));

    QSqlQuery query;
    query.exec(QString("insert into userMessageHistory(username, time, message) values('%1', '%2', '%3')").
               arg(username).arg(time).arg(message.mid(i, message.length() - i - 1)));
    QString str(SendChatMessage + " " + username + " " + time + " " + " " +
                message.mid(i, message.length() - i) + "\n\n");
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    foreach(QTcpSocket* socket, clients)
        socket->write(arrBlock);

    qDebug() << str;
}

void MyServer::slotDisconnected() {
    qDebug() << "Disconnect";
}


void MyServer::returnChatHistoryIndex(QTcpSocket * clientSocket) {
    clients.insert(clientSocket);
    int position, i = 2;
    while(message.at(++i) != ' '); i++;
    position = message.mid(i, message.length() - i).toInt();
    message.clear();
    QSqlQuery query;
    query.exec("select max(id) from userMessageHistory"); query.next();
    int last = query.value(0).toInt();
    if(position < last) {
        query.exec("select * from userMessageHistory where id > " + QString::number(position));
        while(query.next()) {
            message.append(query.value(1).toString() + " ");
            message.append(query.value(2).toString() + " ");
            message.append(query.value(3).toString() + "\n");
        }
    }
    sendToClient(GetChatHistoryIndex, clientSocket);
}

void MyServer::returnChatHistoryUsername(QTcpSocket * clientSocket, QString username) {
    message.clear();
    QSqlQuery query;
    query.exec(QString("select start from userMessageHistoryInfo where username = '%1'").arg(username)); query.next();
    int position = query.value(0).toInt();
    query.exec("select * from userMessageHistory where id > " + QString::number(position));
    while(query.next()) {
        message.append(query.value(1).toString() + " ");
        message.append(query.value(2).toString() + " ");
        message.append(query.value(3).toString() + "\n");
    }
    sendToClient(GetChatHistoryUsername, clientSocket);
}

void MyServer::returnChatPosition(QTcpSocket * clientSocket, QString username) {
    clients.insert(clientSocket);
    message.clear();
    message.append(SendChatMessage + " ADMIN " + username + " joined the chat");
    QSqlQuery query;
    query.exec("select max(id) from userMessageHistory"); query.next();
    int last = query.value(0).toInt();
    query.exec(QString("insert into userMessageHistoryInfo (start, username) values (%1, '%2')").arg(last).arg(username));
    message.clear();
    message.append(QString::number(last));
    sendToClient(GetChatPosition, clientSocket);
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
    QSqlQuery query;
    query.exec("select username, password from user where username = \'" + bufferUsername + "\'");
    query.next();
    if(query.value(0).toString() == bufferUsername) {
        if(query.value(1).toString() == bufferPassword)
            message.append("Ok");
        else message.append("Incorrect password");
    }
    else message.append("Username error");
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
    QSqlQuery query;
    query.exec("select username from user where username = \'" + bufferUsername + "\'"); query.next();
    if(query.value(0).toString() != bufferUsername) {
        int j = message.length();
        while(message.at(--j) != ' ');
        QString bufferEmail(message.mid(j + 1, message.length() - j + 1));
        int z = --j;
        while(message.at(--j) != ' ');
        QString bufferPassword(message.mid(j + 1, z - j));
        QString bufferNameSurname(message.mid(i, j - i));
        query.exec(QString("insert into user (username, namesurname, password) values ('%1', '%2', '%3')").
                   arg(bufferUsername).arg(bufferNameSurname).arg(bufferPassword));
        query.exec(QString("insert into userinfo (username, email) values ('%1', '%2')").
                   arg(bufferUsername).arg(bufferEmail));
        message.clear();
        message.append("Ok");
    }
    else {
        message.clear();
        message.append("Username already occupied");
    }
    sendToClient(SignUpNewUser, clientSocket);
}

void MyServer::getUserInfo(QTcpSocket * clientSocket, QString bufferUsername) {
    QSqlQuery query;
    query.exec("select * from user where username = \'" + bufferUsername + "\'");
    query.next();
    message.clear();
    message.append(query.value(1).toString() + " ");
    query.exec("select * from userinfo where username = \'" + bufferUsername + "\'");
    query.next();
    message.append(query.value(1).toString() + " ");
    if(!query.value(2).toString().isEmpty())
        message.append(query.value(2).toString() + "! ");
    else message.append("?! ");
    if(!query.value(3).toString().isEmpty())
        message.append(query.value(3).toString());
    else message.append("0");
    sendToClient(GetUserInformation, clientSocket);
}

void MyServer::sendToClient(QString code, QTcpSocket * clientSocket) {
    QString str(code + " " + message);
    qDebug() << str;
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    clientSocket->write(arrBlock);
}
