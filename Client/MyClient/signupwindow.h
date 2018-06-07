#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>
#include <QHostAddress>
#include <QMessageAuthenticationCode>
#include <QTcpSocket>
#include <QDebug>
#include "smtp.h"
#include "myclient.h"

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QDialog {
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = 0);
    ~SignUpWindow();
    QString getUsername();
    QString getNameSurname();
    QString getEmail();

private:
    Ui::SignUpWindow *ui;
    QTcpSocket *socket;
    QString secretCode;
    QString message;
    quint16 nextBlockSize;
    QString address;

    QString username;
    QString nameSurname;
    QString email;

private slots:
    void slotConnected();
    void slotSendToServer();
    void slotReadyRead();
    //void slotError(QAbstractSocket::SocketError);
    void onGetKeyButtonClicked();
    void slotMailSent(QString );
    void slotDisconnected();
};

#endif // SIGNUPWINDOW_H
