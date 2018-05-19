#ifndef MYSERVER_H
#define MYSERVER_H

#include <QDebug>
#include <QTcpServer>
#include "mythreadsocket.h"

class MyServer: public QTcpServer {
    Q_OBJECT

public:
    MyServer(QObject * parent = 0);
    void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

};

#endif // MYSERVER_H
