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

enum MessageCode {
    SignIn = 11
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
    void getMessage();
    void checkInDB();

private slots:
    void slotReadyRead();
    void slotDisconnected();
};

#endif // MYTHREADSOCKET_H
