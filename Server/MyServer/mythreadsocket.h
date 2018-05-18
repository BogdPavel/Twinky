#ifndef MYTHREADSOCKET_H
#define MYTHREADSOCKET_H

#include <QThread>
#include <QTcpSocket>

class MyThreadSocket : public QThread
{
    Q_OBJECT

public:
    MyThreadSocket(int socketDescriptor, QObject * parent = 0);
    ~MyThreadSocket();

private:
    int socketDescriptor;
    QTcpSocket * socket;
    void run();

private slots:
    void slotReadyRead();
    void slotDisconnected();
};

#endif // MYTHREADSOCKET_H
