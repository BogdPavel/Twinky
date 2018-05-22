/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindow
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *nameSurnameLine;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *usernameLine;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *passwordLine;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLineEdit *emailLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *errorLabel;
    QLabel *label_8;
    QPushButton *getKeyButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLineEdit *keyLine;
    QHBoxLayout *horizontalLayout_8;
    QLabel *errorSignUpLabel;
    QPushButton *signUpButton;

    void setupUi(QDialog *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName(QStringLiteral("SignUpWindow"));
        SignUpWindow->resize(210, 305);
        SignUpWindow->setMinimumSize(QSize(210, 305));
        SignUpWindow->setMaximumSize(QSize(210, 305));
        groupBox = new QGroupBox(SignUpWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 192, 285));
        groupBox->setMinimumSize(QSize(192, 285));
        groupBox->setMaximumSize(QSize(192, 285));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 174, 281));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(170, 30));
        label_2->setMaximumSize(QSize(170, 30));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(170, 30));
        label->setMaximumSize(QSize(170, 30));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 10));
        label_3->setMaximumSize(QSize(50, 10));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_3);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(50, 10));
        label_6->setMaximumSize(QSize(50, 10));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_6);


        horizontalLayout_7->addLayout(verticalLayout_2);

        nameSurnameLine = new QLineEdit(layoutWidget);
        nameSurnameLine->setObjectName(QStringLiteral("nameSurnameLine"));
        nameSurnameLine->setMinimumSize(QSize(110, 20));
        nameSurnameLine->setMaximumSize(QSize(110, 20));
        nameSurnameLine->setStyleSheet(QStringLiteral(""));

        horizontalLayout_7->addWidget(nameSurnameLine);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(50, 20));
        label_4->setMaximumSize(QSize(50, 20));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_4);

        usernameLine = new QLineEdit(layoutWidget);
        usernameLine->setObjectName(QStringLiteral("usernameLine"));
        usernameLine->setMinimumSize(QSize(110, 20));
        usernameLine->setMaximumSize(QSize(110, 20));

        horizontalLayout_6->addWidget(usernameLine);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(50, 20));
        label_5->setMaximumSize(QSize(50, 20));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        passwordLine = new QLineEdit(layoutWidget);
        passwordLine->setObjectName(QStringLiteral("passwordLine"));
        passwordLine->setMinimumSize(QSize(110, 20));
        passwordLine->setMaximumSize(QSize(110, 20));

        horizontalLayout_5->addWidget(passwordLine);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setAutoExclusive(false);

        horizontalLayout_4->addWidget(checkBox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(50, 20));
        label_10->setMaximumSize(QSize(50, 20));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_10);

        emailLine = new QLineEdit(layoutWidget);
        emailLine->setObjectName(QStringLiteral("emailLine"));
        emailLine->setMinimumSize(QSize(110, 20));
        emailLine->setMaximumSize(QSize(110, 20));

        horizontalLayout_2->addWidget(emailLine);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        errorLabel = new QLabel(layoutWidget);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setMinimumSize(QSize(60, 23));
        errorLabel->setMaximumSize(QSize(60, 23));

        horizontalLayout_3->addWidget(errorLabel);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(75, 23));
        label_8->setMaximumSize(QSize(75, 23));
        label_8->setStyleSheet(QStringLiteral("text-align: right;"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_8);

        getKeyButton = new QPushButton(layoutWidget);
        getKeyButton->setObjectName(QStringLiteral("getKeyButton"));
        getKeyButton->setMinimumSize(QSize(35, 23));
        getKeyButton->setMaximumSize(QSize(35, 23));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        getKeyButton->setFont(font);
        getKeyButton->setStyleSheet(QStringLiteral("border: none; color: grey;"));

        horizontalLayout_3->addWidget(getKeyButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(50, 20));
        label_9->setMaximumSize(QSize(50, 20));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_9);

        keyLine = new QLineEdit(layoutWidget);
        keyLine->setObjectName(QStringLiteral("keyLine"));
        keyLine->setMinimumSize(QSize(110, 20));
        keyLine->setMaximumSize(QSize(110, 20));

        horizontalLayout->addWidget(keyLine);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, -1, 4, -1);
        errorSignUpLabel = new QLabel(layoutWidget);
        errorSignUpLabel->setObjectName(QStringLiteral("errorSignUpLabel"));
        errorSignUpLabel->setMinimumSize(QSize(117, 0));
        errorSignUpLabel->setMaximumSize(QSize(117, 16777215));
        errorSignUpLabel->setSizeIncrement(QSize(0, 0));

        horizontalLayout_8->addWidget(errorSignUpLabel);

        signUpButton = new QPushButton(layoutWidget);
        signUpButton->setObjectName(QStringLiteral("signUpButton"));
        signUpButton->setMinimumSize(QSize(50, 23));
        signUpButton->setMaximumSize(QSize(50, 23));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        signUpButton->setFont(font1);
        signUpButton->setStyleSheet(QStringLiteral("border: none; color: grey; text-align: left;"));
        signUpButton->setFlat(true);

        horizontalLayout_8->addWidget(signUpButton);


        verticalLayout_3->addLayout(horizontalLayout_8);


        retranslateUi(SignUpWindow);

        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QDialog *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QApplication::translate("SignUpWindow", "Twinky", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("SignUpWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Twinky</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("SignUpWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Join us right now</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("SignUpWindow", "Name and", nullptr));
        label_6->setText(QApplication::translate("SignUpWindow", "surname", nullptr));
        label_4->setText(QApplication::translate("SignUpWindow", "Username", nullptr));
        label_5->setText(QApplication::translate("SignUpWindow", "Password", nullptr));
        checkBox->setText(QApplication::translate("SignUpWindow", "Show symbols", nullptr));
        label_10->setText(QApplication::translate("SignUpWindow", "Email", nullptr));
        errorLabel->setText(QString());
        label_8->setText(QApplication::translate("SignUpWindow", "Activation key", nullptr));
        getKeyButton->setText(QApplication::translate("SignUpWindow", "Get", nullptr));
        label_9->setText(QApplication::translate("SignUpWindow", "Your key", nullptr));
        errorSignUpLabel->setText(QString());
        signUpButton->setText(QApplication::translate("SignUpWindow", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
