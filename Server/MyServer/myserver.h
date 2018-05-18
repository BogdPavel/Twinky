#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QString>
#include "mythreadsocket.h"

class MyServer : public QTcpServer
{

    Q_OBJECT

public:
    MyServer(QObject * parent = 0);

private:
    void incomingConnection(int handle);

};

#endif // MYSERVER_H
