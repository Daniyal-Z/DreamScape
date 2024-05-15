#include "newplaylist.h"
#include "ui_newplaylist.h"

NewPlaylist::NewPlaylist(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewPlaylist)
{
    ui->setupUi(this);

    connect(this, &NewPlaylist::finished, [this](){
        emit playlistCreated(ui->newPlay->text());
    });
}

NewPlaylist::~NewPlaylist()
{
    delete ui;
}

void NewPlaylist::on_create_clicked()
{
    if (ui->newPlay->text() != "")   // I think this is where another check can be implemented for duplication of playlists
    {                                // (wont make an empty name playlist; also similar names playlist for the same user problem hasnt been addressed)
        close();
    }
}


void NewPlaylist::on_cancel_clicked()
{
    close();
}

