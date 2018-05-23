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

private:
    Ui::StartWindow *ui;
    QTcpSocket * socket;
    quint16 nextBlockSize;
    QString message;

private slots:
    void onSignUpButtonClicked();
    void slotSendToServer();
    void slotConnected();
    void slotReadyRead();
    void slotDisconnected();
    void reconnect();

};

#endif // STARTWINDOW_H
