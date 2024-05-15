/********************************************************************************
** Form generated from reading UI file 'forgotpassword.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTPASSWORD_H
#define UI_FORGOTPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ForgotPassword
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *newPass;

    void setupUi(QDialog *ForgotPassword)
    {
        if (ForgotPassword->objectName().isEmpty())
            ForgotPassword->setObjectName("ForgotPassword");
        ForgotPassword->resize(400, 300);
        gridLayout = new QGridLayout(ForgotPassword);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(ForgotPassword);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        username = new QLineEdit(ForgotPassword);
        username->setObjectName("username");

        horizontalLayout->addWidget(username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(ForgotPassword);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        password = new QLineEdit(ForgotPassword);
        password->setObjectName("password");

        horizontalLayout_2->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        newPass = new QPushButton(ForgotPassword);
        newPass->setObjectName("newPass");

        gridLayout->addWidget(newPass, 2, 1, 1, 1);


        retranslateUi(ForgotPassword);

        QMetaObject::connectSlotsByName(ForgotPassword);
    } // setupUi

    void retranslateUi(QDialog *ForgotPassword)
    {
        ForgotPassword->setWindowTitle(QCoreApplication::translate("ForgotPassword", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ForgotPassword", "Enter Username:", nullptr));
        label_2->setText(QCoreApplication::translate("ForgotPassword", "New Password: ", nullptr));
        newPass->setText(QCoreApplication::translate("ForgotPassword", "Set New Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgotPassword: public Ui_ForgotPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTPASSWORD_H
