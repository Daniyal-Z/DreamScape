/********************************************************************************
** Form generated from reading UI file 'artistwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTISTWINDOW_H
#define UI_ARTISTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArtistWindow
{
public:
    QAction *actionLog_Out;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLCDNumber *songNumber;
    QLabel *label_3;
    QTableWidget *tableSongs;
    QPushButton *ok;
    QLabel *label_5;
    QLabel *label_2;
    QListWidget *songsList;
    QLabel *label;
    QPushButton *addSong;
    QLineEdit *removeSong;
    QPushButton *artist;
    QMenuBar *menubar;
    QMenu *menuUser;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ArtistWindow)
    {
        if (ArtistWindow->objectName().isEmpty())
            ArtistWindow->setObjectName("ArtistWindow");
        ArtistWindow->resize(1191, 701);
        actionLog_Out = new QAction(ArtistWindow);
        actionLog_Out->setObjectName("actionLog_Out");
        actionLog_Out->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(ArtistWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        songNumber = new QLCDNumber(centralwidget);
        songNumber->setObjectName("songNumber");
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font.setPointSize(13);
        font.setBold(true);
        songNumber->setFont(font);

        gridLayout->addWidget(songNumber, 1, 4, 1, 2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 3, 1, 1);

        tableSongs = new QTableWidget(centralwidget);
        if (tableSongs->columnCount() < 3)
            tableSongs->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableSongs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableSongs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableSongs->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableSongs->setObjectName("tableSongs");

        gridLayout->addWidget(tableSongs, 2, 0, 3, 1);

        ok = new QPushButton(centralwidget);
        ok->setObjectName("ok");

        gridLayout->addWidget(ok, 5, 5, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 5, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Fixedsys")});
        font1.setPointSize(20);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 2, 1, 2);

        songsList = new QListWidget(centralwidget);
        songsList->setObjectName("songsList");

        gridLayout->addWidget(songsList, 3, 2, 1, 4);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 3, 1, 1);

        addSong = new QPushButton(centralwidget);
        addSong->setObjectName("addSong");

        gridLayout->addWidget(addSong, 4, 5, 1, 1);

        removeSong = new QLineEdit(centralwidget);
        removeSong->setObjectName("removeSong");

        gridLayout->addWidget(removeSong, 5, 3, 1, 2);

        artist = new QPushButton(centralwidget);
        artist->setObjectName("artist");

        gridLayout->addWidget(artist, 0, 5, 1, 1);

        ArtistWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ArtistWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1191, 25));
        menubar->setLayoutDirection(Qt::RightToLeft);
        menuUser = new QMenu(menubar);
        menuUser->setObjectName("menuUser");
        ArtistWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ArtistWindow);
        statusbar->setObjectName("statusbar");
        ArtistWindow->setStatusBar(statusbar);

        menubar->addAction(menuUser->menuAction());
        menuUser->addAction(actionLog_Out);

        retranslateUi(ArtistWindow);

        QMetaObject::connectSlotsByName(ArtistWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ArtistWindow)
    {
        ArtistWindow->setWindowTitle(QCoreApplication::translate("ArtistWindow", "MainWindow", nullptr));
        actionLog_Out->setText(QCoreApplication::translate("ArtistWindow", "Log Out", nullptr));
        label_4->setText(QCoreApplication::translate("ArtistWindow", "Your Songs", nullptr));
        label_3->setText(QCoreApplication::translate("ArtistWindow", "Add A Song", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableSongs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ArtistWindow", "S/No", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableSongs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ArtistWindow", "Artist Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableSongs->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ArtistWindow", "Song Name", nullptr));
        ok->setText(QCoreApplication::translate("ArtistWindow", "ok", nullptr));
        label_5->setText(QCoreApplication::translate("ArtistWindow", "Remove Song", nullptr));
        label_2->setText(QCoreApplication::translate("ArtistWindow", "Number of Owned Songs", nullptr));
        label->setText(QCoreApplication::translate("ArtistWindow", "All Available Songs", nullptr));
        addSong->setText(QCoreApplication::translate("ArtistWindow", "+", nullptr));
        artist->setText(QString());
        menuUser->setTitle(QCoreApplication::translate("ArtistWindow", "User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArtistWindow: public Ui_ArtistWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTISTWINDOW_H
