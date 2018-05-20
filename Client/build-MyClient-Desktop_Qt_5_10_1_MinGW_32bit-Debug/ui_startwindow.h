/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
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

class Ui_StartWindow
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *usernameLine;
    QLabel *label_3;
    QLineEdit *passwordLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *answerLabel;
    QPushButton *logInButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QPushButton *signUpButton;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QStringLiteral("StartWindow"));
        StartWindow->resize(210, 360);
        StartWindow->setMinimumSize(QSize(210, 360));
        StartWindow->setMaximumSize(QSize(210, 360));
        StartWindow->setStyleSheet(QStringLiteral(""));
        groupBox = new QGroupBox(StartWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 190, 340));
        layoutWidget = new QWidget(StartWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 174, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(170, 170));
        label->setMaximumSize(QSize(170, 170));

        verticalLayout->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(10);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 20));
        label_2->setMaximumSize(QSize(50, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        usernameLine = new QLineEdit(layoutWidget);
        usernameLine->setObjectName(QStringLiteral("usernameLine"));
        usernameLine->setMinimumSize(QSize(110, 20));
        usernameLine->setMaximumSize(QSize(110, 20));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameLine);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 20));
        label_3->setMaximumSize(QSize(50, 20));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        passwordLine = new QLineEdit(layoutWidget);
        passwordLine->setObjectName(QStringLiteral("passwordLine"));
        passwordLine->setMinimumSize(QSize(110, 20));
        passwordLine->setMaximumSize(QSize(110, 20));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLine);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 5, -1);
        answerLabel = new QLabel(layoutWidget);
        answerLabel->setObjectName(QStringLiteral("answerLabel"));
        answerLabel->setMargin(2);

        horizontalLayout_2->addWidget(answerLabel);

        logInButton = new QPushButton(layoutWidget);
        logInButton->setObjectName(QStringLiteral("logInButton"));
        logInButton->setMinimumSize(QSize(45, 23));
        logInButton->setMaximumSize(QSize(45, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        logInButton->setFont(font);
        logInButton->setLayoutDirection(Qt::LeftToRight);
        logInButton->setStyleSheet(QStringLiteral("border: none; color: grey; text-align: right;"));

        horizontalLayout_2->addWidget(logInButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(169, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, -1, -1, -1);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(120, 20));
        label_4->setMaximumSize(QSize(120, 20));

        horizontalLayout->addWidget(label_4);

        signUpButton = new QPushButton(layoutWidget);
        signUpButton->setObjectName(QStringLiteral("signUpButton"));
        signUpButton->setMinimumSize(QSize(45, 23));
        signUpButton->setMaximumSize(QSize(45, 23));
        signUpButton->setFont(font);
        signUpButton->setStyleSheet(QStringLiteral("border: none; color: grey;"));

        horizontalLayout->addWidget(signUpButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "Twinky", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("StartWindow", "<html><head/><body><p><img src=\":/img/logo.png\" width=\"170\" height=\"170\"/></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("StartWindow", "Username", nullptr));
        label_3->setText(QApplication::translate("StartWindow", "Password", nullptr));
        answerLabel->setText(QString());
        logInButton->setText(QApplication::translate("StartWindow", "Log in", nullptr));
        label_4->setText(QApplication::translate("StartWindow", "Don't have an account?", nullptr));
        signUpButton->setText(QApplication::translate("StartWindow", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
