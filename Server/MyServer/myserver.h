#ifndef MYSERVER_H
#define MYSERVER_H

#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDataStream>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>

const QString CheckUsernameAndPassword("11");
const QString SignUpNewUser("13");
const QString GetUserInformation("15");
const QString GetChatHistory("17");

enum MessageCode {
    SignIn = 11,
    SignUp = 13,
    GetUserInfo = 15,
    GetHistory = 17
};

class MyServer: public QTcpServer {
    Q_OBJECT

public:
    MyServer(QObject * parent = 0);
    void incomingConnection(qintptr handle);

private:
    quint16 nextBlockSize;
    qintptr myDescriptor;
    QString message;
    int messageCode;
    QSqlDatabase usersDB;
    QSqlDatabase historyDB;

    QSet<QTcpSocket *> clients;
    QMap<QTcpSocket *, QString> users;

private slots:
    void slotReadyRead();
    void slotDisconnected();
    void checkUserInDB(QTcpSocket * );
    void signUpNewUser(QTcpSocket * );
    void getUserInfo(QTcpSocket * , QString);
    void sendToClient(QString, QTcpSocket * );
    void returnChatHistory(QTcpSocket * );

};

#endif // MYSERVER_H
