#ifndef MYTHREADSOCKET_H
#define MYTHREADSOCKET_H

#include <QThread>
#include <QTcpSocket>
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

class MyThreadSocket : public QThread {
    Q_OBJECT

public:
    MyThreadSocket(qintptr handle, QObject * parent = 0);
    ~MyThreadSocket();

protected:
    void run() Q_DECL_OVERRIDE;

private:
    quint16 nextBlockSize;
    qintptr myDescriptor;
    QString message;
    QTcpSocket * socket;
    int messageCode;
    QSqlDatabase usersDB;

private slots:
    void slotReadyRead();
    void slotDisconnected();
    void checkUserInDB();
    void signUpNewUser();
    void sendToClient(QString);
};

#endif // MYTHREADSOCKET_H
