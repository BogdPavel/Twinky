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

const QString CheckUsernameAndPassword("11");
const QString SignUpNewUser("13");

enum MessageCode {
    SignIn = 11,
    SignUp = 13
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

private slots:
    void slotReadyRead();
    void slotDisconnected();
    void checkUserInDB(QTcpSocket * );
    void signUpNewUser(QTcpSocket * );
    void sendToClient(QString, QTcpSocket * );

};

#endif // MYSERVER_H
