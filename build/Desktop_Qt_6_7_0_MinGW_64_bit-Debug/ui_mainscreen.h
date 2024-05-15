/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QAction *actionLog_Out;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFrame *line_2;
    QGridLayout *ControlGrid;
    QHBoxLayout *stateController;
    QVBoxLayout *verticalLayout_2;
    QPushButton *songName;
    QPushButton *artistName;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *Shuffle;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Previous;
    QPushButton *play_pause;
    QPushButton *Next;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Repeat;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *Liked;
    QPushButton *Volume_Mute;
    QSlider *Volume;
    QHBoxLayout *songDetails;
    QLabel *Current_Time;
    QSlider *Seek_Bar;
    QLabel *Total_Time;
    QComboBox *addToPlaylist;
    QFrame *line;
    QHBoxLayout *userArea;
    QLineEdit *searchBar;
    QSpacerItem *horizontalSpacer;
    QPushButton *powerButton;
    QPushButton *userDetails;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QListView *playlistView;
    QHBoxLayout *horizontalLayout;
    QTableView *songView;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *newPlaylist;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_3;
    QMenuBar *menubar;
    QMenu *menu_User;

    void setupUi(QMainWindow *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName("MainScreen");
        MainScreen->resize(1268, 708);
        actionLog_Out = new QAction(MainScreen);
        actionLog_Out->setObjectName("actionLog_Out");
        centralwidget = new QWidget(MainScreen);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_2, 0, 1, 1, 1);

        ControlGrid = new QGridLayout();
        ControlGrid->setObjectName("ControlGrid");
        ControlGrid->setContentsMargins(0, -1, 0, -1);
        stateController = new QHBoxLayout();
        stateController->setObjectName("stateController");
        stateController->setContentsMargins(10, -1, 10, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        songName = new QPushButton(centralwidget);
        songName->setObjectName("songName");
        songName->setCheckable(true);

        verticalLayout_2->addWidget(songName);

        artistName = new QPushButton(centralwidget);
        artistName->setObjectName("artistName");
        artistName->setCheckable(true);

        verticalLayout_2->addWidget(artistName);


        stateController->addLayout(verticalLayout_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        stateController->addItem(horizontalSpacer_11);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        stateController->addItem(horizontalSpacer_9);

        Shuffle = new QPushButton(centralwidget);
        Shuffle->setObjectName("Shuffle");
        Shuffle->setStyleSheet(QString::fromUtf8("border-radius: 200px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/shuffle_i.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/Images/shuffle_p.png"), QSize(), QIcon::Normal, QIcon::On);
        Shuffle->setIcon(icon);
        Shuffle->setIconSize(QSize(30, 30));
        Shuffle->setCheckable(true);

        stateController->addWidget(Shuffle);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        stateController->addItem(horizontalSpacer_3);

        Previous = new QPushButton(centralwidget);
        Previous->setObjectName("Previous");
        Previous->setStyleSheet(QString::fromUtf8("border-radius: 200px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/back_i.png"), QSize(), QIcon::Normal, QIcon::Off);
        Previous->setIcon(icon1);
        Previous->setIconSize(QSize(40, 40));

        stateController->addWidget(Previous);

        play_pause = new QPushButton(centralwidget);
        play_pause->setObjectName("play_pause");
        play_pause->setStyleSheet(QString::fromUtf8("border-radius: 200px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/play_i.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/Images/play_p.png"), QSize(), QIcon::Normal, QIcon::On);
        play_pause->setIcon(icon2);
        play_pause->setIconSize(QSize(65, 65));
        play_pause->setCheckable(true);

        stateController->addWidget(play_pause);

        Next = new QPushButton(centralwidget);
        Next->setObjectName("Next");
        Next->setStyleSheet(QString::fromUtf8("border-radius: 200px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/forward_i.png"), QSize(), QIcon::Normal, QIcon::On);
        Next->setIcon(icon3);
        Next->setIconSize(QSize(40, 40));

        stateController->addWidget(Next);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        stateController->addItem(horizontalSpacer_4);

        Repeat = new QPushButton(centralwidget);
        Repeat->setObjectName("Repeat");
        Repeat->setStyleSheet(QString::fromUtf8("border-radius: 200px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/repeat_i.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/Images/repeat_p.png"), QSize(), QIcon::Normal, QIcon::On);
        Repeat->setIcon(icon4);
        Repeat->setIconSize(QSize(30, 30));
        Repeat->setCheckable(true);

        stateController->addWidget(Repeat);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        stateController->addItem(horizontalSpacer_10);

        Liked = new QPushButton(centralwidget);
        Liked->setObjectName("Liked");
        Liked->setAutoFillBackground(false);
        Liked->setStyleSheet(QString::fromUtf8("border-radius: 100px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Images/icon3.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/Images/icon4.png"), QSize(), QIcon::Normal, QIcon::On);
        Liked->setIcon(icon5);
        Liked->setIconSize(QSize(25, 25));
        Liked->setCheckable(true);

        stateController->addWidget(Liked);

        Volume_Mute = new QPushButton(centralwidget);
        Volume_Mute->setObjectName("Volume_Mute");
        Volume_Mute->setStyleSheet(QString::fromUtf8("border-radius: 60px\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Images/icon5.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/Images/icon6.png"), QSize(), QIcon::Normal, QIcon::On);
        Volume_Mute->setIcon(icon6);
        Volume_Mute->setIconSize(QSize(23, 23));
        Volume_Mute->setCheckable(true);

        stateController->addWidget(Volume_Mute);

        Volume = new QSlider(centralwidget);
        Volume->setObjectName("Volume");
        Volume->setOrientation(Qt::Horizontal);

        stateController->addWidget(Volume);


        ControlGrid->addLayout(stateController, 1, 1, 1, 1);

        songDetails = new QHBoxLayout();
        songDetails->setObjectName("songDetails");
        songDetails->setContentsMargins(170, -1, 50, -1);
        Current_Time = new QLabel(centralwidget);
        Current_Time->setObjectName("Current_Time");

        songDetails->addWidget(Current_Time);

        Seek_Bar = new QSlider(centralwidget);
        Seek_Bar->setObjectName("Seek_Bar");
        Seek_Bar->setEnabled(true);
        Seek_Bar->setMinimum(0);
        Seek_Bar->setOrientation(Qt::Horizontal);

        songDetails->addWidget(Seek_Bar);

        Total_Time = new QLabel(centralwidget);
        Total_Time->setObjectName("Total_Time");

        songDetails->addWidget(Total_Time);

        addToPlaylist = new QComboBox(centralwidget);
        addToPlaylist->setObjectName("addToPlaylist");

        songDetails->addWidget(addToPlaylist);


        ControlGrid->addLayout(songDetails, 0, 1, 1, 1);


        gridLayout_2->addLayout(ControlGrid, 12, 1, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line, 7, 1, 1, 1);

        userArea = new QHBoxLayout();
        userArea->setObjectName("userArea");
        searchBar = new QLineEdit(centralwidget);
        searchBar->setObjectName("searchBar");
        QFont font;
        font.setItalic(true);
        searchBar->setFont(font);

        userArea->addWidget(searchBar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        userArea->addItem(horizontalSpacer);

        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName("powerButton");
        powerButton->setStyleSheet(QString::fromUtf8("border-radius: 100px\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Images/iconSpecial.png"), QSize(), QIcon::Normal, QIcon::Off);
        powerButton->setIcon(icon7);
        powerButton->setIconSize(QSize(25, 25));
        powerButton->setCheckable(true);

        userArea->addWidget(powerButton);

        userDetails = new QPushButton(centralwidget);
        userDetails->setObjectName("userDetails");

        userArea->addWidget(userDetails);


        gridLayout_2->addLayout(userArea, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        playlistView = new QListView(centralwidget);
        playlistView->setObjectName("playlistView");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font1.setPointSize(14);
        playlistView->setFont(font1);

        verticalLayout->addWidget(playlistView);


        gridLayout->addLayout(verticalLayout, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        songView = new QTableView(centralwidget);
        songView->setObjectName("songView");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font2.setPointSize(10);
        songView->setFont(font2);

        horizontalLayout->addWidget(songView);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("DejaVu Sans")});
        label->setFont(font3);

        horizontalLayout_7->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        newPlaylist = new QPushButton(centralwidget);
        newPlaylist->setObjectName("newPlaylist");
        newPlaylist->setCheckable(true);

        horizontalLayout_7->addWidget(newPlaylist);


        gridLayout->addLayout(horizontalLayout_7, 0, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font3);

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 10, 1, 1, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_3, 11, 1, 1, 1);

        MainScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScreen);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1268, 25));
        menubar->setLayoutDirection(Qt::RightToLeft);
        menu_User = new QMenu(menubar);
        menu_User->setObjectName("menu_User");
        MainScreen->setMenuBar(menubar);

        menubar->addAction(menu_User->menuAction());
        menu_User->addAction(actionLog_Out);

        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *MainScreen)
    {
        MainScreen->setWindowTitle(QCoreApplication::translate("MainScreen", "MainWindow", nullptr));
        actionLog_Out->setText(QCoreApplication::translate("MainScreen", "Log Out", nullptr));
        songName->setText(QString());
        artistName->setText(QString());
        Shuffle->setText(QString());
        Previous->setText(QString());
        play_pause->setText(QString());
        Next->setText(QString());
        Repeat->setText(QString());
        Liked->setText(QString());
        Volume_Mute->setText(QString());
        Current_Time->setText(QString());
        Total_Time->setText(QString());
        addToPlaylist->setPlaceholderText(QCoreApplication::translate("MainScreen", "Add to Playlist", nullptr));
        searchBar->setPlaceholderText(QCoreApplication::translate("MainScreen", "What do you want to play?", nullptr));
        powerButton->setText(QString());
        userDetails->setText(QString());
        label->setText(QCoreApplication::translate("MainScreen", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Your Personalised Playlists</span></p></body></html>", nullptr));
        newPlaylist->setText(QCoreApplication::translate("MainScreen", "Create New Playlist", nullptr));
        label_2->setText(QCoreApplication::translate("MainScreen", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">PlayArea</span></p></body></html>", nullptr));
        menu_User->setTitle(QCoreApplication::translate("MainScreen", "User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
