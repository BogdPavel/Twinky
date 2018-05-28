#include "myclient.h"
#include "ui_myclient.h"

MyClient::MyClient(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MyClient), nextBlockSize(0) {
    ui->setupUi(this);

    //getChatHistoryQuery();
}

MyClient::MyClient(QString username, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MyClient), nextBlockSize(0) {
    ui->setupUi(this);
    ui->usernameButton->setText(username);
    constructor();
    socketMessage.append(GetUserInformation + " " + username);
    sendToServer();

    //getChatHistoryQuery();
}

MyClient::MyClient(QString nameSurname, QString username, QString email, QWidget *parent):
    QMainWindow(parent), ui(new Ui::MyClient), nextBlockSize(0) {
    ui->setupUi(this);
    ui->nameSurnameButton->setText(nameSurname);
    ui->usernameButton->setText(username);
    ui->emailButton->setText(email);
    constructor();

    //getChatHistoryQuery();
}

void MyClient::constructor() {
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 80);
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(ui->messageLine, SIGNAL(returnPressed()), this, SLOT(sendMessageFromUser()));
    connect(ui->aboutButton, SIGNAL(clicked(bool)), this, SLOT(onAboutButtonClicked()));
    connect(ui->sayButton, SIGNAL(clicked(bool), this, SLOT(sendMessageFromUser()));
}

MyClient::~MyClient() {
    delete ui;
    delete socket;
}

void MyClient::onSayButtonClicked() {

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

}

void MyClient::getChatHistoryQuery() {
   socketMessage.clear();
   socketMessage.append(GetChatHistory + " " + ui->usernameButton->text());
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
    QString buffer(socketMessage.at(0));
    buffer += socketMessage.at(1);
    messageCode = buffer.toInt();
    switch(messageCode) {
    case SendMessage: writeDownMessageInChat(); break;
    case GetUserInfo: writeDownUserInformation(); break;
    case GetHistory: writeDownHistory(); break;
    }
}

void MyClient::writeDownUserInformation() {
    int j = socketMessage.length() - 1;
    if(socketMessage.at(j) != "0") {
        while(socketMessage.at(--j) != '!');
        ui->bioButton->setText(socketMessage.mid(j + 2, socketMessage.length() - j + 1));
    }
    else j -= 2; int z = j;
    if(socketMessage.at(j) != "0") {
        while(socketMessage.at(--j) != ' ');
        ui->mobileButton->setText(socketMessage.mid(j + 1, socketMessage.length() - z + 1));
    }
    else j -= 2; z = j;
    qDebug() << j;
    while(socketMessage.at(--j) != " ")
        ui->emailButton->setText(socketMessage.mid(j, z - j));
    ui->nameSurnameButton->setText(socketMessage.mid(3, j - 3));

}

void MyClient::sendMessageFromUser() {
    if(!ui->messageLine->text().isEmpty()) {
        socketMessage.clear();
        socketMessage.append(SendChatMessage + " " + ui->messageLine->text());
        sendToServer();
        ui->messageLine->setText("");
        ui->messageLine->setFocus();
    }
}

void MyClient::writeDownMessageInChat() {
    ui->chat->append(socketMessage.mid(3, socketMessage.length() - 3));
}

void MyClient::writeDownHistory() {

}


