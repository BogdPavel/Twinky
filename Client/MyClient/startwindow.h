#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include "signupwindow.h"
#include "myclient.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog {
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();
    QString getUsername();
    QString getNameSurname();
    QString getEmail();

private:
    Ui::StartWindow *ui;
    QTcpSocket * socket;
    quint16 nextBlockSize;
    QString message;
    QString address;

    QString username;
    QString nameSurname;
    QString email;

private slots:
    void onSignUpButtonClicked();
    void slotSendToServer();
    void slotConnected();
    void slotReadyRead();

};

#endif // STARTWINDOW_H
