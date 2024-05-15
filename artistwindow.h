#ifndef ARTISTWINDOW_H
#define ARTISTWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "artist.h"

namespace Ui {
class ArtistWindow;
}

class ArtistWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArtistWindow(User** user, const QString& username, QWidget *parent = nullptr);
    ~ArtistWindow();

    void populateListWidget();

    int songNum(const QString&);

    void populateSongTable();

    void mainSetup();

    void removeSong();

private slots:
    void on_addSong_clicked();

    void on_ok_clicked();

    void on_actionLog_Out_triggered();

private:
    Ui::ArtistWindow *ui;
    User** user;
    Artist* artist;
    bool flag_reWritten; //if file has been rewritten
};

#endif // ARTISTWINDOW_H
