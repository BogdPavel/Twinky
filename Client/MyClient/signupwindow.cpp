#include "signupwindow.h"
#include "ui_signupwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::SignUpWindow) {
    ui->setupUi(this);
    this->username.clear();
    address = "93.125.49.244";
    socket = new QTcpSocket(this);
    socket->connectToHost(address, 4200);
    connect(ui->getKeyButton, SIGNAL(clicked(bool)),
            this, SLOT(onGetKeyButtonClicked()));
    connect(ui->signUpButton, SIGNAL(clicked(bool)),
            this, SLOT(slotSendToServer()));
    connect(socket, SIGNAL(connected()),
            this, SLOT(slotConnected()));
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));
}

SignUpWindow::~SignUpWindow() {
    delete ui;
    delete socket;
}

void SignUpWindow::slotConnected() {
    ui->errorLabel->setText("Connected");
    qDebug() << "Connected";
}

void SignUpWindow::slotDisconnected() {
    qDebug() << "Disconnected";
}

QString SignUpWindow::getUsername()
{
    return username;
}

QString SignUpWindow::getNameSurname()
{
    return nameSurname;
}

QString SignUpWindow::getEmail()
{
    return email;
}

void SignUpWindow::slotSendToServer() {
    if(ui->keyLine->text() == "key") {
        QString str(SignUpNewUser + " " + ui->usernameLine->text() + " " + ui->nameSurnameLine->text() + " " +
                    ui->passwordLine->text() + " " + ui->emailLine->text());
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

void SignUpWindow::slotReadyRead() {
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
        serverReadStream >> message;
        nextBlockSize = 0;
    }
    if(!message.compare(SignUpNewUser + " " + "Ok")) {
        socket->disconnectFromHost();
        this->nameSurname = ui->nameSurnameLine->text();
        this->username = ui->usernameLine->text();
        this->email = ui->emailLine->text();
        this->close();
    }
    else ui->errorSignUpLabel->setText(message.mid(3, message.length() - 3));
}

void SignUpWindow::onGetKeyButtonClicked() {
    if(!ui->nameSurnameLine->text().isEmpty() && !ui->usernameLine->text().isEmpty()  &&
        !ui->passwordLine->text().isEmpty() ) {
        QByteArray code = QMessageAuthenticationCode::hash(ui->usernameLine->text().toLocal8Bit(),
                                         QString::number(qrand() % 100 + 999).toLocal8Bit(),
                                         QCryptographicHash::Md5).toHex();
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






