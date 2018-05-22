#include "signupwindow.h"
#include "ui_signupwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::SignUpWindow) {
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 2323);
    connect(ui->getKeyButton, SIGNAL(clicked(bool)),
            this, SLOT(onGetKeyButtonClicked()));
    connect(ui->signUpButton, SIGNAL(clicked(bool)),
            this, SLOT(slotSendToServer()));
    connect(socket, SIGNAL(connected()),
            this, SLOT(slotConnected()));
}

SignUpWindow::~SignUpWindow() {
    delete ui;
    delete socket;
}

void SignUpWindow::slotConnected() {
    ui->errorLabel->setText("Connected");
}

void SignUpWindow::slotSendToServer() {
    if(ui->keyLine->text() == secretCode) {
        QString str(SignUpNewUser + " " + ui->usernameLine->text() + " " + ui->nameSurnameLine->text() + " " +
                    ui->passwordLine->text() + " " + ui->emailLine->text());
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

void SignUpWindow::slotReadyRead() {
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
    if(message.compare(SignUpNewUser + " " + "Ok")) {
        ui->errorSignUpLabel->setText(message);
    }
    else ui->errorSignUpLabel->setText(message);
}

void SignUpWindow::onGetKeyButtonClicked() {
    if(!ui->nameSurnameLine->text().isEmpty() && !ui->usernameLine->text().isEmpty()  &&
        !ui->passwordLine->text().isEmpty() ) {
        QByteArray code = QMessageAuthenticationCode::hash(ui->usernameLine->text().toLocal8Bit(),
                                         QString::number(qrand() % 100 + 999).toLocal8Bit(),
                                         QCryptographicHash::Sha1).toHex();
        secretCode.append(code);
        qDebug() << secretCode;
        Smtp * smtp = new Smtp("pavel.bogdevich1998@gmail.com", "pavelprostopavel", "smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(slotMailSent(QString)));
        smtp->sendMail("pavel.bogdevich1998@gmail.com", ui->emailLine->text() , "Page activation", secretCode);
    }
}

void SignUpWindow::slotMailSent(QString status) {
    if(status == "Message sent")
        ui->errorLabel->setText("Sent");
    else ui->errorLabel->setText("Error");
}






