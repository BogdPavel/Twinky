#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTimer>
#include <QTime>
#include <QHostAddress>
#include "startwindow.h"

const QString CheckUsernameAndPassword("11");
const QString SignUpNewUser("13");
const QString GetUserInformation("15");
const QString GetChatHistoryIndex("17");
const QString GetChatHistoryUsername("18");
const QString SendChatMessage("19");
const QString GetChatPosition("21");

enum MessageCode {
    SignIn = 11,
    SignUp = 13,
    GetUserInfo = 15,
    GetHistoryIndex = 17,
    GetHistoryUsername = 18,
    SendMessage = 19,
    GetChatPos = 21
};

namespace Ui {
class MyClient;
}

class MyClient : public QMainWindow {
    Q_OBJECT

public:
    MyClient(QWidget *parent = 0);
    ~MyClient();

private:
    Ui::MyClient *ui;
    QTcpSocket * socket;
    quint16 nextBlockSize;
    int messageCode;
    QString socketMessage;
    QSqlDatabase historyDB;
    QString address;
    QString username;

private slots:
    /*void onAboutButtonClicked();
    void onSettingsButtonClicked();
    void onLogOutButtonClicked();
    void onNumberOfUsersButtonClicked();
    void onSearchMessagesButtonClicked();
    void onSetPhotoButtonClicked();
    void onNightModeButtonClicked();
    void onNotificationsButtonClicked();
    void onClearHistoryButtonClicked();
    void onNameSurnameButtonClicked();
    void onUsernameButtonClicked();
    void onEmailButtonClicked();
    void onMobileButtonClicked();
    void onBioButtonClicked();
    void onSayButtonClicked();*/

    void constructor();

    void writeDownMessageInChat();
    void sendMessageFromUser();

    void getChatHistoryQueryUsername();
    void getChatHistoryQueryIndex(int );
    void writeDownHistory();

    void downloadHistoryFromDB();
    void writeDownUserInformation();
    void welcomeInChat();

    void sendToServer();
    void slotReadyRead();
    void slotDisconnected();
};

#endif // MYCLIENT_H
