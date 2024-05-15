/********************************************************************************
** Form generated from reading UI file 'newplaylist.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPLAYLIST_H
#define UI_NEWPLAYLIST_H

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

class Ui_NewPlaylist
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *newPlay;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *create;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *NewPlaylist)
    {
        if (NewPlaylist->objectName().isEmpty())
            NewPlaylist->setObjectName("NewPlaylist");
        NewPlaylist->resize(346, 240);
        gridLayout = new QGridLayout(NewPlaylist);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(NewPlaylist);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Nunito")});
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(NewPlaylist);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        newPlay = new QLineEdit(NewPlaylist);
        newPlay->setObjectName("newPlay");

        verticalLayout->addWidget(newPlay);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        cancel = new QPushButton(NewPlaylist);
        cancel->setObjectName("cancel");

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        create = new QPushButton(NewPlaylist);
        create->setObjectName("create");

        horizontalLayout->addWidget(create);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);


        retranslateUi(NewPlaylist);

        QMetaObject::connectSlotsByName(NewPlaylist);
    } // setupUi

    void retranslateUi(QDialog *NewPlaylist)
    {
        NewPlaylist->setWindowTitle(QCoreApplication::translate("NewPlaylist", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NewPlaylist", "<html><head/><body><p align=\"center\">Create a New Playlist</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("NewPlaylist", "<html><head/><body><p align=\"center\">Give your playlist a name</p></body></html>", nullptr));
        cancel->setText(QCoreApplication::translate("NewPlaylist", "Cancel", nullptr));
        create->setText(QCoreApplication::translate("NewPlaylist", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewPlaylist: public Ui_NewPlaylist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPLAYLIST_H
