#include "myclient.h"
#include "ui_myclient.h"

MyClient::MyClient(QString username, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MyClient), nextBlockSize(0) {
    ui->setupUi(this);
    this->username = username;
    ui->usernameButton->setText(username);
    constructor();

    socketMessage.append(GetUserInformation + " " + username);
    sendToServer();

    QTimer::singleShot(500, this, SLOT(downloadHistoryFromDB()));

}

MyClient::MyClient(QString nameSurname, QString username, QString email, QWidget *parent):
    QMainWindow(parent), ui(new Ui::MyClient), nextBlockSize(0) {
    ui->setupUi(this);
    this->username = username;
    ui->nameSurnameButton->setText(nameSurname);
    ui->usernameButton->setText(username);
    ui->emailButton->setText(email);
    constructor();
    socketMessage.append(GetChatPosition + " " + username);
    sendToServer();
}

void MyClient::constructor() {
    address = "93.125.49.244";

    socket = new QTcpSocket(this);
    socket->connectToHost(address, 80);

    historyDB = QSqlDatabase::addDatabase("QSQLITE");
    historyDB.setDatabaseName(QCoreApplication::applicationDirPath() + "/chathistory.db");
    historyDB.open();

    connect(socket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(ui->messageLine, SIGNAL(returnPressed()), this, SLOT(sendMessageFromUser()));
    connect(ui->aboutButton, SIGNAL(clicked(bool)), this, SLOT(onAboutButtonClicked()));
    connect(ui->sayButton, SIGNAL(clicked(bool)), this, SLOT(sendMessageFromUser()));
}

void MyClient::slotDisconnected() {
    QSqlQuery query;
    query.exec("delete from currentUser");
    query.exec(QString("insert into currentUser(currentUser) values('%1')").arg(username));
}

MyClient::~MyClient() {    
    delete ui;
    delete socket;

}

/*void MyClient::onSayButtonClicked() {

}

void MyClient::onAboutButtonClicked() {

}

void MyClient::onSettingsButtonClicked() {

}

void MyClient::onLogOutButtonClicked() {

}

void MyClient::onNumberOfUsersButtonClicked() {

}

void MyClient::onSearchMessagesButtonClicked() {

}

void MyClient::onSetPhotoButtonClicked() {

}

void MyClient::onNightModeButtonClicked() {

}

void MyClient::onNotificationsButtonClicked() {

}

void MyClient::onClearHistoryButtonClicked() {

}

void MyClient::onNameSurnameButtonClicked() {

}

void MyClient::onUsernameButtonClicked() {

}

void MyClient::onEmailButtonClicked() {

}

void MyClient::onMobileButtonClicked() {

}

void MyClient::onBioButtonClicked() {

}*/

void MyClient::getChatHistoryQueryIndex(int position) {
   socketMessage.clear();
   socketMessage.append(GetChatHistoryIndex + " " + username + " " + QString::number(position));
   sendToServer();
}

void MyClient::getChatHistoryQueryUsername() {
    socketMessage.clear();
    socketMessage.append(GetChatHistoryUsername + " " + username);
    sendToServer();
}

void MyClient::sendToServer() {
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << quint16(0) << socketMessage;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    socket->write(arrBlock);
}

void MyClient::slotReadyRead() {
    qDebug() << "Read!";
    QDataStream serverReadStream(socket);
    serverReadStream.setVersion(QDataStream::Qt_4_5);
    while(true) {
        if (!nextBlockSize) {
            if (socket->bytesAvailable() < sizeof(quint16))
                break;
            serverReadStream >> nextBlockSize;
        }
        if (socket->bytesAvailable() < nextBlockSize) {
            break;
        }
        serverReadStream >> socketMessage;
        qDebug() << socketMessage;
        nextBlockSize = 0;
    }
    messageCode = socketMessage.mid(0, 2).toInt();
    switch(messageCode) {
    case SendMessage: writeDownMessageInChat(); break;
    case GetUserInfo: writeDownUserInformation(); break;
    case GetHistoryIndex: writeDownHistory(); break;
    case GetHistoryUsername: writeDownHistory(); break;
    case GetChatPos: welcomeInChat(); break;
    }
}

void MyClient::writeDownUserInformation() {
    int j = socketMessage.length() - 1;
    if(socketMessage.at(j) != "0") {
        while(socketMessage.at(--j) != '!');
        ui->bioButton->setText(socketMessage.mid(j + 2, socketMessage.length() - j + 1));
    }
    else j -= 3;
    int z = j;
    if(socketMessage.at(j) != "?") {
        while(socketMessage.at(--j) != ' ');
        ui->mobileButton->setText(socketMessage.mid(j + 1, socketMessage.length() - z - 2));
    }
    else j -= 2;
    z = j;
    qDebug() << j;
    while(socketMessage.at(--j) != " ");
        ui->emailButton->setText(socketMessage.mid(j, z - j));
    ui->nameSurnameButton->setText(socketMessage.mid(3, j - 3));

}

void MyClient::sendMessageFromUser() {
    if(!ui->messageLine->text().isEmpty()) {
        socketMessage.clear();
        socketMessage.append(SendChatMessage + " " + this->username + " " + ui->messageLine->text());
        sendToServer();
        ui->messageLine->setText("");
        ui->messageLine->setFocus();
    }
}

void MyClient::writeDownMessageInChat() {
    ui->chat->insertPlainText(socketMessage.mid(3, socketMessage.length() - 3));
}

void MyClient::writeDownHistory() {
    int i = 3, z, j;
    QString username, time, message;
    QSqlQuery query;
    while(i < socketMessage.length()) {
        z = i;
        while(socketMessage.at(++i) != ' ');
        username = socketMessage.mid(z, i - z);
        time = socketMessage.mid(++i, 8);
        i += 9; j = i;
        while(socketMessage.at(++i) != "\n");
        message = socketMessage.mid(j, i - j);
        query.exec(QString("insert into history(username, time, message) values('%1', '%2', '%3')").arg(username).arg(time).arg(message));
        i++;
    }
    query.exec("select * from history");
    while(query.next()) {
        username = query.value(1).toString();
        time = query.value(2).toString();
        message = query.value(3).toString();
        ui->chat->insertPlainText(username + " " + time + " " + message + "\n\n");
    }
}

void MyClient::downloadHistoryFromDB() {
   QSqlQuery query;

   query.exec("select max(id) from history"); query.next();
   int i = query.value(0).toInt();

   query.exec("select * from currentUser"); query.next();
   QString currentUser = query.value(0).toString();

   if(currentUser == username) {
       getChatHistoryQueryIndex(i);
   }
   else {
      query.exec(QString("delete from history where id <= %1").arg(i));
      getChatHistoryQueryUsername();
   }

}

void MyClient::welcomeInChat() {
    int position, i = 3;
    position = socketMessage.mid(i, socketMessage.length() - i).toInt();
    QString time = QTime::currentTime().toString().mid(0, 8);
    QSqlQuery query;
    query.exec("delete from history");
    query.exec(QString("insert into history(id, username, time, message) values(%1, 'ADMIN', '%2', 'Welcome in chat!')").
               arg(QString::number(position)).arg(time));
    ui->chat->insertPlainText("ADMIN " + time + " Welcome in chat!\n\n");
}
