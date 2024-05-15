/********************************************************************************
** Form generated from reading UI file 'initialwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIALWINDOW_H
#define UI_INITIALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitialWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *Listener;
    QPushButton *Artist;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QWidget *page_2;

    void setupUi(QMainWindow *InitialWindow)
    {
        if (InitialWindow->objectName().isEmpty())
            InitialWindow->setObjectName("InitialWindow");
        InitialWindow->resize(1180, 654);
        centralwidget = new QWidget(InitialWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        stackWidget = new QStackedWidget(centralwidget);
        stackWidget->setObjectName("stackWidget");
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Listener = new QPushButton(page);
        Listener->setObjectName("Listener");

        horizontalLayout->addWidget(Listener);

        Artist = new QPushButton(page);
        Artist->setObjectName("Artist");

        horizontalLayout->addWidget(Artist);


        gridLayout_2->addLayout(horizontalLayout, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(page);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        stackWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackWidget->addWidget(page_2);

        gridLayout->addWidget(stackWidget, 0, 0, 1, 1);

        InitialWindow->setCentralWidget(centralwidget);

        retranslateUi(InitialWindow);

        stackWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InitialWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InitialWindow)
    {
        InitialWindow->setWindowTitle(QCoreApplication::translate("InitialWindow", "MainWindow", nullptr));
        Listener->setText(QCoreApplication::translate("InitialWindow", "Listener", nullptr));
        Artist->setText(QCoreApplication::translate("InitialWindow", "Artist", nullptr));
        label->setText(QCoreApplication::translate("InitialWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Log In as</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitialWindow: public Ui_InitialWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIALWINDOW_H
