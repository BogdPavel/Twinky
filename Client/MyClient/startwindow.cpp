#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow) {

    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost("localhost", 4200);
    connect(socket, SIGNAL(connected()),
            this, SLOT(slotConnected()));
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(slotError(QAbstractSocket::SocketError)));
    connect(ui->logInButton, SIGNAL(clicked(bool)),
            this, SLOT(slotSendToServer()));

}

StartWindow::~StartWindow() {
    delete ui;
}

void StartWindow::slotConnected() {
    ui->answerLabel->setText("Connection established");
}

void StartWindow::slotReadyRead() {
    QDataStream in(socket);
    while(true) {
        if(!nextBlockSize) {
            if(socket->bytesAvailable() < sizeof(quint16))
                break;
            in >> nextBlockSize;
        }
        if(socket->bytesAvailable() < nextBlockSize)
            break;
    }
    QString str;
    in >> str;
    if(str != "Ok")
        ui->answerLabel->setText(str);
    else {
        SignUpWindow * window = new SignUpWindow();
        window->show();
    }
}

void StartWindow::slotSendToServer() {
    if(!ui->usernameLine->text().isEmpty() && !ui->passwordLine->text().isEmpty()) {
        QString str(CheckUsernameAndPassword + ui->usernameLine->text() + " " + ui->passwordLine->text());
        QByteArray arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out << quint16(0) << str;
        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));
        socket->write(arrBlock);
    }
}

void StartWindow::onSignUpButtonClicked() {
    SignUpWindow * window = new SignUpWindow();
    window->show();
}
