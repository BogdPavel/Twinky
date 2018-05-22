#include "startwindow.h"
#include "signupwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignUpWindow window;
    window.show();
    return a.exec();
}
