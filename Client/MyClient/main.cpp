#include "startwindow.h"
#include "signupwindow.h"
#include "myclient.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyClient window;
    //window.show();
    return a.exec();
}
