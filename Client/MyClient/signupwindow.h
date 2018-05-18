#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = 0);
    ~SignUpWindow();

private:
    Ui::SignUpWindow *ui;
};

#endif // SIGNUPWINDOW_H
