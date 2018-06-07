#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::StartWindow), nextBlockSize(0) {
    ui->setupUi(this);
    this->username.clear();
    address = "93.125.49.244";
    socket = new QTcpSocket(this);
    socket->connectToHost(address, 4200);
    connect(socket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(ui->logInButton, SIGNAL(clicked(bool)), this, SLOT(slotSendToServer()));
    connect(ui->signUpButton, SIGNAL(clicked(bool)), this, SLOT(onSignUpButtonClicked()));
}

StartWindow::~StartWindow() {
    delete ui;
    delete socket;
}

QString StartWindow::getUsername() {
    return username;
}

QString StartWindow::getNameSurname() {
    return nameSurname;
}

QString StartWindow::getEmail() {
    return email;
}

void StartWindow::slotConnected() {
    ui->answerLabel->setText("Connection established");
}

void StartWindow::slotReadyRead() {
    qDebug() << "Read!";
    QDataStream serverReadStream(socket);
    serverReadStream.setVersion(QDataStream::Qt_4_5);
    while(true) {
        if (!nextBlockSize) {
            if (socket->bytesAvailable() < sizeof(quint16)) break;
            serverReadStream >> nextBlockSize;
        }
        if (socket->bytesAvailable() < nextBlockSize) break;
        serverReadStream >> message;
        nextBlockSize = 0;
    }
    if(!message.compare(CheckUsernameAndPassword + " " + "Ok")) {
        socket->disconnectFromHost();
        username = ui->usernameLine->text();
        this->close();
    }
    else ui->answerLabel->setText(message.mid(3, message.length() - 3));
}

void StartWindow::slotSendToServer() {
    if(!ui->usernameLine->text().isEmpty() && !ui->passwordLine->text().isEmpty()) {
        QString str(CheckUsernameAndPassword + " " + ui->usernameLine->text() + " " + ui->passwordLine->text());
        QByteArray arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_5);
        out << quint16(0) << str;
        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));
        socket->write(arrBlock);
    }
}

void StartWindow::onSignUpButtonClicked() {
    this->close();
    socket->disconnectFromHost();
    SignUpWindow window; window.exec();
    this->username = window.getUsername();
    this->nameSurname = window.getNameSurname();
    this->email = window.getEmail();
}
