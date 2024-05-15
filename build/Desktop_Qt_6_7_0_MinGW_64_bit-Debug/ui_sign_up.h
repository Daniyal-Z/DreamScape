/********************************************************************************
** Form generated from reading UI file 'sign_up.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_UP_H
#define UI_SIGN_UP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sign_Up
{
public:
    QLabel *confirm_label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *validPass;
    QLabel *label_2;
    QPushButton *Sign_Up_2;
    QLineEdit *newPass;
    QLabel *validUser;
    QLabel *label;
    QCheckBox *confirmation;
    QPushButton *Sign_In;
    QLineEdit *newUser;
    QWidget *page_2;

    void setupUi(QDialog *Sign_Up)
    {
        if (Sign_Up->objectName().isEmpty())
            Sign_Up->setObjectName("Sign_Up");
        Sign_Up->resize(1175, 626);
        confirm_label = new QLabel(Sign_Up);
        confirm_label->setObjectName("confirm_label");
        confirm_label->setGeometry(QRect(520, 470, 121, 20));
        stackedWidget = new QStackedWidget(Sign_Up);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, -1, 1171, 631));
        page = new QWidget();
        page->setObjectName("page");
        validPass = new QLabel(page);
        validPass->setObjectName("validPass");
        validPass->setGeometry(QRect(510, 280, 191, 20));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 310, 121, 20));
        Sign_Up_2 = new QPushButton(page);
        Sign_Up_2->setObjectName("Sign_Up_2");
        Sign_Up_2->setGeometry(QRect(530, 390, 141, 29));
        newPass = new QLineEdit(page);
        newPass->setObjectName("newPass");
        newPass->setGeometry(QRect(510, 300, 191, 41));
        validUser = new QLabel(page);
        validUser->setObjectName("validUser");
        validUser->setGeometry(QRect(510, 180, 191, 20));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 210, 111, 20));
        confirmation = new QCheckBox(page);
        confirmation->setObjectName("confirmation");
        confirmation->setGeometry(QRect(500, 440, 211, 26));
        Sign_In = new QPushButton(page);
        Sign_In->setObjectName("Sign_In");
        Sign_In->setGeometry(QRect(0, 0, 161, 29));
        newUser = new QLineEdit(page);
        newUser->setObjectName("newUser");
        newUser->setGeometry(QRect(510, 200, 191, 41));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        stackedWidget->raise();
        confirm_label->raise();

        retranslateUi(Sign_Up);

        QMetaObject::connectSlotsByName(Sign_Up);
    } // setupUi

    void retranslateUi(QDialog *Sign_Up)
    {
        Sign_Up->setWindowTitle(QCoreApplication::translate("Sign_Up", "Dialog", nullptr));
        confirm_label->setText(QString());
        validPass->setText(QString());
        label_2->setText(QCoreApplication::translate("Sign_Up", "Enter a password:*", nullptr));
        Sign_Up_2->setText(QCoreApplication::translate("Sign_Up", "Sign Up", nullptr));
        validUser->setText(QString());
        label->setText(QCoreApplication::translate("Sign_Up", "Enter username:*", nullptr));
        confirmation->setText(QCoreApplication::translate("Sign_Up", "Confirm if you are a human", nullptr));
        Sign_In->setText(QCoreApplication::translate("Sign_Up", "Go back to Sign In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sign_Up: public Ui_Sign_Up {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_UP_H
