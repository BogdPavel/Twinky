/********************************************************************************
** Form generated from reading UI file 'myclient.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLIENT_H
#define UI_MYCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClient
{
public:
    QAction *actionfghngf;
    QWidget *centralwidget;
    QPushButton *logOutButton;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *membersNumberButton;
    QLineEdit *lineEdit;
    QPushButton *searchMessagesButton;
    QLabel *label_9;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *setProfilePhotoButton;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QPushButton *nightModeButton;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QPushButton *usernameButton;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QPushButton *emailButton;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QPushButton *bioButton;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QPushButton *mobileButton;
    QWidget *layoutWidget_9;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPushButton *nameSurnameButton;
    QLabel *label_11;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QPushButton *notificationsButton;
    QPushButton *clearHistoryButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *settingsButton;
    QPushButton *aboutButton;

    void setupUi(QMainWindow *MyClient)
    {
        if (MyClient->objectName().isEmpty())
            MyClient->setObjectName(QStringLiteral("MyClient"));
        MyClient->resize(800, 500);
        MyClient->setStyleSheet(QStringLiteral(""));
        actionfghngf = new QAction(MyClient);
        actionfghngf->setObjectName(QStringLiteral("actionfghngf"));
        centralwidget = new QWidget(MyClient);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        logOutButton = new QPushButton(centralwidget);
        logOutButton->setObjectName(QStringLiteral("logOutButton"));
        logOutButton->setGeometry(QRect(730, 1, 55, 20));
        logOutButton->setMinimumSize(QSize(55, 20));
        logOutButton->setMaximumSize(QSize(55, 20));
        QFont font;
        font.setPointSize(10);
        logOutButton->setFont(font);
        logOutButton->setStyleSheet(QLatin1String("border: none;\n"
"color: grey;"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 20, 760, 460));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(150, 0, 460, 60));
        groupBox_3->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(groupBox_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 441, 43));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(440, 0));
        label_10->setMaximumSize(QSize(440, 16777215));
        label_10->setStyleSheet(QStringLiteral("background: none"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(4);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        membersNumberButton = new QPushButton(widget);
        membersNumberButton->setObjectName(QStringLiteral("membersNumberButton"));
        membersNumberButton->setMinimumSize(QSize(70, 20));
        membersNumberButton->setMaximumSize(QSize(70, 20));
        QFont font1;
        font1.setUnderline(true);
        membersNumberButton->setFont(font1);
        membersNumberButton->setStyleSheet(QLatin1String("border: none;\n"
"color: grey;"));

        horizontalLayout_7->addWidget(membersNumberButton);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(130, 20));
        lineEdit->setMaximumSize(QSize(130, 20));

        horizontalLayout_7->addWidget(lineEdit);

        searchMessagesButton = new QPushButton(widget);
        searchMessagesButton->setObjectName(QStringLiteral("searchMessagesButton"));
        searchMessagesButton->setMinimumSize(QSize(50, 20));
        searchMessagesButton->setMaximumSize(QSize(50, 20));
        searchMessagesButton->setStyleSheet(QLatin1String("color:white;\n"
"border-radius: 10px;\n"
"background-color: grey;"));

        horizontalLayout_7->addWidget(searchMessagesButton);


        verticalLayout_3->addLayout(horizontalLayout_7);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1, 178, 149, 10));
        label_9->setStyleSheet(QStringLiteral("background-color: white;"));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(150, 60, 460, 340));
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(150, 400, 461, 60));
        groupBox_5->setStyleSheet(QStringLiteral("background-color: white"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(620, 10, 130, 130));
        label_13->setMinimumSize(QSize(130, 130));
        label_13->setMaximumSize(QSize(130, 130));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(620, 150, 130, 20));
        label_14->setMinimumSize(QSize(130, 20));
        label_14->setMaximumSize(QSize(130, 20));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(620, 182, 131, 81));
        label_15->setStyleSheet(QStringLiteral("background-color: white"));
        label_15->setAlignment(Qt::AlignCenter);
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 134, 163));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(130, 130));
        label->setMaximumSize(QSize(130, 130));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(40, 20));
        label_3->setMaximumSize(QSize(40, 20));
        label_3->setStyleSheet(QStringLiteral("color:blue;"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        setProfilePhotoButton = new QPushButton(layoutWidget_2);
        setProfilePhotoButton->setObjectName(QStringLiteral("setProfilePhotoButton"));
        setProfilePhotoButton->setMinimumSize(QSize(90, 20));
        setProfilePhotoButton->setMaximumSize(QSize(90, 20));
        setProfilePhotoButton->setStyleSheet(QLatin1String("color:white;\n"
"border-radius: 10px;\n"
"background-color:blue;"));

        horizontalLayout->addWidget(setProfilePhotoButton);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget_4 = new QWidget(groupBox_2);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(11, 357, 118, 22));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(70, 20));
        label_8->setMaximumSize(QSize(70, 20));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_8);

        nightModeButton = new QPushButton(layoutWidget_4);
        nightModeButton->setObjectName(QStringLiteral("nightModeButton"));
        nightModeButton->setMinimumSize(QSize(40, 20));
        nightModeButton->setMaximumSize(QSize(40, 20));
        nightModeButton->setStyleSheet(QLatin1String("color:white;\n"
"border-radius: 10px;\n"
"background-color:grey;"));

        horizontalLayout_6->addWidget(nightModeButton);

        layoutWidget_5 = new QWidget(groupBox_2);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(12, 244, 132, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(60, 20));
        label_4->setMaximumSize(QSize(60, 20));

        horizontalLayout_5->addWidget(label_4);

        usernameButton = new QPushButton(layoutWidget_5);
        usernameButton->setObjectName(QStringLiteral("usernameButton"));
        usernameButton->setMinimumSize(QSize(70, 20));
        usernameButton->setMaximumSize(QSize(70, 20));
        usernameButton->setStyleSheet(QLatin1String("color:blue;\n"
"border:none;\n"
"text-align:left;"));

        horizontalLayout_5->addWidget(usernameButton);

        layoutWidget_6 = new QWidget(groupBox_2);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(12, 300, 132, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(36, 20));
        label_6->setMaximumSize(QSize(36, 20));

        horizontalLayout_3->addWidget(label_6);

        emailButton = new QPushButton(layoutWidget_6);
        emailButton->setObjectName(QStringLiteral("emailButton"));
        emailButton->setMinimumSize(QSize(94, 20));
        emailButton->setMaximumSize(QSize(94, 20));
        emailButton->setStyleSheet(QLatin1String("color:blue;\n"
"border:none;\n"
"text-align:left;"));

        horizontalLayout_3->addWidget(emailButton);

        layoutWidget_7 = new QWidget(groupBox_2);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(12, 328, 136, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(20, 20));
        label_7->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(label_7);

        bioButton = new QPushButton(layoutWidget_7);
        bioButton->setObjectName(QStringLiteral("bioButton"));
        bioButton->setMinimumSize(QSize(109, 20));
        bioButton->setMaximumSize(QSize(109, 20));
        bioButton->setStyleSheet(QLatin1String("color:blue;\n"
"border:none;\n"
"text-align:left;"));

        horizontalLayout_2->addWidget(bioButton);

        layoutWidget_8 = new QWidget(groupBox_2);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(12, 272, 132, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_8);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(40, 20));
        label_5->setMaximumSize(QSize(40, 20));

        horizontalLayout_4->addWidget(label_5);

        mobileButton = new QPushButton(layoutWidget_8);
        mobileButton->setObjectName(QStringLiteral("mobileButton"));
        mobileButton->setMinimumSize(QSize(90, 20));
        mobileButton->setMaximumSize(QSize(90, 20));
        mobileButton->setStyleSheet(QLatin1String("color:blue;\n"
"border:none;\n"
"text-align:left;"));

        horizontalLayout_4->addWidget(mobileButton);

        layoutWidget_9 = new QWidget(groupBox_2);
        layoutWidget_9->setObjectName(QStringLiteral("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(12, 192, 135, 48));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_9);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_9);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(130, 20));
        label_2->setMaximumSize(QSize(130, 20));

        verticalLayout_2->addWidget(label_2);

        nameSurnameButton = new QPushButton(layoutWidget_9);
        nameSurnameButton->setObjectName(QStringLiteral("nameSurnameButton"));
        nameSurnameButton->setMinimumSize(QSize(90, 20));
        nameSurnameButton->setMaximumSize(QSize(90, 20));
        QFont font2;
        font2.setUnderline(false);
        nameSurnameButton->setFont(font2);
        nameSurnameButton->setAutoFillBackground(false);
        nameSurnameButton->setStyleSheet(QLatin1String("color:blue;\n"
"border:none;\n"
"text-align:left;"));
        nameSurnameButton->setIconSize(QSize(90, 20));

        verticalLayout_2->addWidget(nameSurnameButton);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1, 389, 149, 10));
        label_11->setStyleSheet(QStringLiteral("background-color: white;"));
        layoutWidget_10 = new QWidget(groupBox_2);
        layoutWidget_10->setObjectName(QStringLiteral("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(620, 320, 112, 22));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_10);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(70, 20));
        label_12->setMaximumSize(QSize(70, 20));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_12);

        notificationsButton = new QPushButton(layoutWidget_10);
        notificationsButton->setObjectName(QStringLiteral("notificationsButton"));
        notificationsButton->setMinimumSize(QSize(40, 20));
        notificationsButton->setMaximumSize(QSize(40, 20));
        notificationsButton->setStyleSheet(QLatin1String("color:white;\n"
"border-radius: 10px;\n"
"background-color:grey;"));

        horizontalLayout_9->addWidget(notificationsButton);

        clearHistoryButton = new QPushButton(groupBox_2);
        clearHistoryButton->setObjectName(QStringLiteral("clearHistoryButton"));
        clearHistoryButton->setGeometry(QRect(630, 295, 110, 20));
        clearHistoryButton->setMinimumSize(QSize(110, 20));
        clearHistoryButton->setMaximumSize(QSize(110, 20));
        clearHistoryButton->setFont(font2);
        clearHistoryButton->setAutoFillBackground(false);
        clearHistoryButton->setStyleSheet(QLatin1String("color: grey;\n"
"border:none;"));
        clearHistoryButton->setIconSize(QSize(90, 20));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(640, 271, 115, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setSpacing(3);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(20, 20));
        label_16->setMaximumSize(QSize(20, 20));

        horizontalLayout_8->addWidget(label_16);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(90, 20));
        label_17->setMaximumSize(QSize(90, 20));

        horizontalLayout_8->addWidget(label_17);

        settingsButton = new QPushButton(centralwidget);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        settingsButton->setGeometry(QRect(19, 1, 55, 20));
        settingsButton->setMinimumSize(QSize(55, 20));
        settingsButton->setMaximumSize(QSize(55, 20));
        settingsButton->setFont(font);
        settingsButton->setStyleSheet(QLatin1String("border: none;\n"
"color: grey;"));
        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));
        aboutButton->setGeometry(QRect(70, 1, 55, 20));
        aboutButton->setMinimumSize(QSize(55, 20));
        aboutButton->setMaximumSize(QSize(55, 20));
        aboutButton->setFont(font);
        aboutButton->setStyleSheet(QLatin1String("border: none;\n"
"color: grey;"));
        MyClient->setCentralWidget(centralwidget);

        retranslateUi(MyClient);

        QMetaObject::connectSlotsByName(MyClient);
    } // setupUi

    void retranslateUi(QMainWindow *MyClient)
    {
        MyClient->setWindowTitle(QApplication::translate("MyClient", "Stream", nullptr));
        actionfghngf->setText(QApplication::translate("MyClient", "fghngf", nullptr));
        logOutButton->setText(QApplication::translate("MyClient", "Log out", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        label_10->setText(QApplication::translate("MyClient", "Chat name", nullptr));
        membersNumberButton->setText(QApplication::translate("MyClient", "10 members", nullptr));
        searchMessagesButton->setText(QApplication::translate("MyClient", "Search", nullptr));
        label_9->setText(QString());
        groupBox_4->setTitle(QString());
        groupBox_5->setTitle(QString());
        label_13->setText(QApplication::translate("MyClient", "<html><head/><body><p><img src=\":/img/logo.png\" width=\"130\" height=\"130\" /></p></body></html>", nullptr));
        label_14->setText(QApplication::translate("MyClient", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Chat info</span></p></body></html>", nullptr));
        label_15->setText(QApplication::translate("MyClient", "Chat info", nullptr));
        label->setText(QApplication::translate("MyClient", "<html><head/><body><p><img src=\":/img/human1.jpg\" width=\"130\" height=\"130\"/>TextLabel</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("MyClient", "online", nullptr));
        setProfilePhotoButton->setText(QApplication::translate("MyClient", "Set profile photo", nullptr));
        label_8->setText(QApplication::translate("MyClient", "Night mode", nullptr));
        nightModeButton->setText(QApplication::translate("MyClient", "On", nullptr));
        label_4->setText(QApplication::translate("MyClient", "Username:", nullptr));
        usernameButton->setText(QApplication::translate("MyClient", "username", nullptr));
        label_6->setText(QApplication::translate("MyClient", "Email:", nullptr));
        emailButton->setText(QApplication::translate("MyClient", "email", nullptr));
        label_7->setText(QApplication::translate("MyClient", "Bio:", nullptr));
        bioButton->setText(QApplication::translate("MyClient", "bio", nullptr));
        label_5->setText(QApplication::translate("MyClient", "Mobile:", nullptr));
        mobileButton->setText(QApplication::translate("MyClient", "mobile", nullptr));
        label_2->setText(QApplication::translate("MyClient", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Info</span></p></body></html>", nullptr));
        nameSurnameButton->setText(QApplication::translate("MyClient", "Name Surname", nullptr));
        label_11->setText(QString());
        label_12->setText(QApplication::translate("MyClient", "Mute", nullptr));
        notificationsButton->setText(QApplication::translate("MyClient", "On", nullptr));
        clearHistoryButton->setText(QApplication::translate("MyClient", "Clear chat history", nullptr));
        label_16->setText(QApplication::translate("MyClient", "IP:", nullptr));
        label_17->setText(QApplication::translate("MyClient", "192.168.x.xxx", nullptr));
        settingsButton->setText(QApplication::translate("MyClient", "Settings", nullptr));
        aboutButton->setText(QApplication::translate("MyClient", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyClient: public Ui_MyClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLIENT_H
