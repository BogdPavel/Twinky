#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::StartWindow), nextBlockSize(0) {
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 80);
    connect(socket, SIGNAL(connected()),
            this, SLOT(slotConnected()));
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));
    connect(socket, SIGNAL(disconnected()),
            this, SLOT(slotDisconnected()));
    connect(ui->logInButton, SIGNAL(clicked(bool)),
            this, SLOT(slotSendToServer()));
    connect(ui->signUpButton, SIGNAL(clicked(bool)),
            this, SLOT(onSignUpButtonClicked()));

}

StartWindow::~StartWindow() {
    delete ui;
    delete socket;
}

void StartWindow::slotConnected() {
    ui->answerLabel->setText("Connection established");
}

void StartWindow::slotDisconnected() {
    ui->answerLabel->setText("Disconnected");
}

void StartWindow::slotReadyRead() {
    qDebug() << "Read!";
    QDataStream serverReadStream(socket);
    serverReadStream.setVersion(QDataStream::Qt_4_5);
    qDebug() << "Before cycle" << nextBlockSize;
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
    if(!message.compare(CheckUsernameAndPassword + " " + "Ok")) {
        this->close();
        socket->disconnectFromHost();
        MyClient *window = new MyClient();
        window->show();
    }
    else {
        ui->answerLabel->setText(message.mid(3, message.length() - 3));
    }
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
        qDebug() << str;
        socket->write(arrBlock);
    }
}

void StartWindow::onSignUpButtonClicked() {
    this->close();
    socket->disconnectFromHost();
    SignUpWindow window;
    window.exec();

}
