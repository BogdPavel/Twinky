#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QHostAddress>
#include <QTcpSocket>

const QString CheckUsernameAndPassword("11");
const QString SignUpNewUser("13");

namespace Ui {
class MyClient;
}

class MyClient : public QMainWindow {
    Q_OBJECT

public:
    explicit MyClient(QWidget *parent = 0);
    ~MyClient();

private:
    Ui::MyClient *ui;
    QTcpSocket * socket;
    quint16 nextBlockSize;

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

    void slotReadyRead();
    void clotConnected();
};

#endif // MYCLIENT_H
