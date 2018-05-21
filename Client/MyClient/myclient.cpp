#include "myclient.h"
#include "ui_myclient.h"

MyClient::MyClient(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MyClient), nextBlockSize(0) {
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 2323);

}

MyClient::~MyClient() {
    delete ui;
    delete socket;
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

void MyClient::slotReadyRead() {

}

void MyClient::clotConnected() {

}


