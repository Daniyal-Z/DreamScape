/********************************************************************************
** Form generated from reading UI file 'artistlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTISTLOGIN_H
#define UI_ARTISTLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_artistLogin
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QLineEdit *username_2;
    QLineEdit *password_2;
    QPushButton *goBack_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *user_2;
    QLabel *validUser_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pass_2;
    QLabel *validPass_2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Sign_In_2;
    QPushButton *Sign_Up_2;
    QWidget *widget3;
    QVBoxLayout *verticalLayout;
    QCheckBox *confirmation_2;
    QLabel *confirm_label_2;
    QWidget *page_4;

    void setupUi(QMainWindow *artistLogin)
    {
        if (artistLogin->objectName().isEmpty())
            artistLogin->setObjectName("artistLogin");
        artistLogin->resize(1207, 677);
        centralwidget = new QWidget(artistLogin);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-10, 0, 1211, 671));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        username_2 = new QLineEdit(page_3);
        username_2->setObjectName("username_2");
        username_2->setGeometry(QRect(450, 190, 241, 41));
        password_2 = new QLineEdit(page_3);
        password_2->setObjectName("password_2");
        password_2->setGeometry(QRect(450, 290, 241, 41));
        goBack_2 = new QPushButton(page_3);
        goBack_2->setObjectName("goBack_2");
        goBack_2->setGeometry(QRect(0, 0, 121, 29));
        widget = new QWidget(page_3);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(450, 150, 241, 42));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        user_2 = new QLabel(widget);
        user_2->setObjectName("user_2");

        horizontalLayout->addWidget(user_2);

        validUser_2 = new QLabel(widget);
        validUser_2->setObjectName("validUser_2");

        horizontalLayout->addWidget(validUser_2);

        widget1 = new QWidget(page_3);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(450, 250, 241, 42));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pass_2 = new QLabel(widget1);
        pass_2->setObjectName("pass_2");

        horizontalLayout_2->addWidget(pass_2);

        validPass_2 = new QLabel(widget1);
        validPass_2->setObjectName("validPass_2");

        horizontalLayout_2->addWidget(validPass_2);

        widget2 = new QWidget(page_3);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(484, 350, 169, 31));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Sign_In_2 = new QPushButton(widget2);
        Sign_In_2->setObjectName("Sign_In_2");

        horizontalLayout_3->addWidget(Sign_In_2);

        Sign_Up_2 = new QPushButton(widget2);
        Sign_Up_2->setObjectName("Sign_Up_2");

        horizontalLayout_3->addWidget(Sign_Up_2);

        widget3 = new QWidget(page_3);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(490, 390, 211, 55));
        verticalLayout = new QVBoxLayout(widget3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        confirmation_2 = new QCheckBox(widget3);
        confirmation_2->setObjectName("confirmation_2");

        verticalLayout->addWidget(confirmation_2);

        confirm_label_2 = new QLabel(widget3);
        confirm_label_2->setObjectName("confirm_label_2");

        verticalLayout->addWidget(confirm_label_2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget->addWidget(page_4);
        artistLogin->setCentralWidget(centralwidget);

        retranslateUi(artistLogin);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(artistLogin);
    } // setupUi

    void retranslateUi(QMainWindow *artistLogin)
    {
        artistLogin->setWindowTitle(QCoreApplication::translate("artistLogin", "MainWindow", nullptr));
        goBack_2->setText(QCoreApplication::translate("artistLogin", "Go back", nullptr));
        user_2->setText(QCoreApplication::translate("artistLogin", "Username", nullptr));
        validUser_2->setText(QCoreApplication::translate("artistLogin", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
        pass_2->setText(QCoreApplication::translate("artistLogin", "Password", nullptr));
        validPass_2->setText(QCoreApplication::translate("artistLogin", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
        Sign_In_2->setText(QCoreApplication::translate("artistLogin", "Sign In", nullptr));
        Sign_Up_2->setText(QCoreApplication::translate("artistLogin", "Sign Up", nullptr));
        confirmation_2->setText(QCoreApplication::translate("artistLogin", "Confirm if you are a human", nullptr));
        confirm_label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class artistLogin: public Ui_artistLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTISTLOGIN_H
