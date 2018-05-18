#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

const QString CheckUsernameAndPassword("11");

namespace Ui {
class MyClient;
}

class MyClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyClient(QWidget *parent = 0);
    ~MyClient();

private:
    Ui::MyClient *ui;
    QTcpSocket * socket;

private slots:
    /*void onAboutButtonClicked();
    void onSettingsButtonClicked();
    void onLogOutButtonClicked();
    void onNumberOfUsersButtonClicked();
    void onSearchButtonClicked();
    void onSetPhotoButtonClicked();
    void onEditInfoBttonClicked();
    void onNightModeButtonClicked();
    void onNotificationsButtonClicked();
    void onClearHistoryButtonClicked();

    void slotReadyRead();
    void clotConnected();*/
};

#endif // MYCLIENT_H
