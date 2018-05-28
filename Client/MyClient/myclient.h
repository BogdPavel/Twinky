#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QHostAddress>
#include <QTcpSocket>

const QString CheckUsernameAndPassword("11");
const QString SignUpNewUser("13");
const QString GetUserInformation("15");
const QString GetChatHistory("17");
const QString SendChatMessage("19");

enum MessageCode {
    SignIn = 11,
    SignUp = 13,
    GetUserInfo = 15,
    GetHistory = 17,
    SendMessage = 19
};

namespace Ui {
class MyClient;
}

class MyClient : public QMainWindow {
    Q_OBJECT

public:
    explicit MyClient(QWidget *parent = 0);
    MyClient(QString username, QWidget *parent = 0);
    MyClient(QString nameSurname, QString username, QString email, QWidget *parent = 0);
    ~MyClient();

private:
    Ui::MyClient *ui;
    QTcpSocket * socket;
    quint16 nextBlockSize;
    int messageCode;
    QString socketMessage;

private slots:
    void onAboutButtonClicked();
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
    void onSayButtonClicked();

    void constructor();

    void writeDownMessageInChat();
    void sendMessageFromUser();

    void getChatHistoryQuery();
    void writeDownHistory();

    void writeDownUserInformation();

    void sendToServer();
    void slotReadyRead();
};

#endif // MYCLIENT_H
