#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::StartWindow) {
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 2323);
    connect(socket, SIGNAL(connected()),
            this, SLOT(slotConnected()));
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));
    //connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));
    connect(ui->logInButton, SIGNAL(clicked(bool)),
            this, SLOT(slotSendToServer()));
    connect(ui->signUpButton, SIGNAL(clicked(bool)),
            this, SLOT(onSignUpButtonClicked()));

}

StartWindow::~StartWindow() {
    delete ui;
}

void StartWindow::slotConnected() {
    ui->answerLabel->setText("Connection established");
}

void StartWindow::slotReadyRead() {
    qDebug() << "Read!";
    QDataStream serverReadStream(socket);
    serverReadStream.setVersion(QDataStream::Qt_5_5);
    while(true) {
        if (!nextBlockSize) {
            if (socket->bytesAvailable() < sizeof(quint16))
                break;
            serverReadStream >> nextBlockSize;
        }
        if (socket->bytesAvailable() < nextBlockSize) {
            break;
        }
        serverReadStream >> message;
        qDebug() << message;
        nextBlockSize = 0;
    }
    if(message.compare(CheckUsernameAndPassword + " " + "Ok")) {
//        MyClient window;
//        window.show();
        ui->answerLabel->setText(message);
    }
    else {
        ui->answerLabel->setText(message);
    }
}

void StartWindow::slotSendToServer() {
    if(!ui->usernameLine->text().isEmpty() && !ui->passwordLine->text().isEmpty()) {
        QString str(CheckUsernameAndPassword + " " + ui->usernameLine->text() + " " + ui->passwordLine->text());
        QByteArray arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_5);
        out << quint16(0) << str;
        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));
        qDebug() << str;
        socket->write(arrBlock);
    }
}

void StartWindow::onSignUpButtonClicked() {
    SignUpWindow window;
    window.exec();
}
