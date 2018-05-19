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

private slots:
    void onSignUpButtonClicked();
    //void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected();
    void slotReadyRead();

private:
    Ui::StartWindow *ui;
    QTcpSocket * socket;
    quint16 nextBlockSize;
};

#endif // STARTWINDOW_H
