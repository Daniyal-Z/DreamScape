/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_Login
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *goBack;
    QPushButton *forgotPassword;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *user;
    QLabel *validUser;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pass;
    QLabel *validPass;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Sign_In;
    QPushButton *Sign_Up;
    QWidget *widget3;
    QVBoxLayout *verticalLayout;
    QCheckBox *confirmation;
    QLabel *confirm_label;
    QWidget *page_2;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(1241, 685);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1241, 681));
        page = new QWidget();
        page->setObjectName("page");
        username = new QLineEdit(page);
        username->setObjectName("username");
        username->setGeometry(QRect(450, 175, 231, 41));
        password = new QLineEdit(page);
        password->setObjectName("password");
        password->setGeometry(QRect(450, 275, 231, 41));
        goBack = new QPushButton(page);
        goBack->setObjectName("goBack");
        goBack->setGeometry(QRect(11, 11, 80, 29));
        forgotPassword = new QPushButton(page);
        forgotPassword->setObjectName("forgotPassword");
        forgotPassword->setGeometry(QRect(500, 323, 131, 21));
        QFont font;
        font.setPointSize(8);
        forgotPassword->setFont(font);
        forgotPassword->setStyleSheet(QString::fromUtf8(""));
        forgotPassword->setCheckable(true);
        widget = new QWidget(page);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(450, 135, 231, 42));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        user = new QLabel(widget);
        user->setObjectName("user");

        horizontalLayout->addWidget(user);

        validUser = new QLabel(widget);
        validUser->setObjectName("validUser");

        horizontalLayout->addWidget(validUser);

        widget1 = new QWidget(page);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(450, 235, 231, 42));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pass = new QLabel(widget1);
        pass->setObjectName("pass");

        horizontalLayout_2->addWidget(pass);

        validPass = new QLabel(widget1);
        validPass->setObjectName("validPass");

        horizontalLayout_2->addWidget(validPass);

        widget2 = new QWidget(page);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(480, 350, 171, 31));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Sign_In = new QPushButton(widget2);
        Sign_In->setObjectName("Sign_In");

        horizontalLayout_3->addWidget(Sign_In);

        Sign_Up = new QPushButton(widget2);
        Sign_Up->setObjectName("Sign_Up");

        horizontalLayout_3->addWidget(Sign_Up);

        widget3 = new QWidget(page);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(480, 400, 211, 55));
        verticalLayout = new QVBoxLayout(widget3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        confirmation = new QCheckBox(widget3);
        confirmation->setObjectName("confirmation");

        verticalLayout->addWidget(confirmation);

        confirm_label = new QLabel(widget3);
        confirm_label->setObjectName("confirm_label");

        verticalLayout->addWidget(confirm_label);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        goBack->setText(QCoreApplication::translate("Login", "Go back", nullptr));
        forgotPassword->setText(QCoreApplication::translate("Login", "Forgot Password?", nullptr));
        user->setText(QCoreApplication::translate("Login", "Username", nullptr));
        validUser->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
        pass->setText(QCoreApplication::translate("Login", "Password", nullptr));
        validPass->setText(QCoreApplication::translate("Login", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
        Sign_In->setText(QCoreApplication::translate("Login", "Sign In", nullptr));
        Sign_Up->setText(QCoreApplication::translate("Login", "Sign Up", nullptr));
        confirmation->setText(QCoreApplication::translate("Login", "Confirm if you are a human", nullptr));
        confirm_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
