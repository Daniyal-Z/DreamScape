#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include <QPushButton>
#include <QtMultimedia>
#include <QProgressBar>
#include <QStandardItem>
#include <QSlider>
#include <QTime>
#include "user.h"
#include "listener.h"

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(User** user, const QString& username, QWidget *parent = nullptr);
    ~MainScreen();

private slots:
    void on_play_pause_clicked(bool checked);
    void SetDuration(qint64 durationMilliseconds);
    void SetCurrentTime();
    void updateVolumeSlider(qreal volume);
    void setVolume(int value);
    void on_actionLog_Out_triggered();

    void on_Volume_Mute_clicked(bool checked);

    void on_powerButton_clicked(bool checked);

    void InitialView();

    void onPlaylistSelected(const QItemSelection& selected, const QItemSelection& deselected);                  //, const QModelIndex& previous);

    void onSongSelected(const QItemSelection& selected, const QItemSelection& deselected);                      //, const QModelIndex& previous);

    void onSearchTextChanged(const QString& query);

    void on_newPlaylist_clicked();

    void on_addToPlaylist_currentIndexChanged(int index);

    void newPlaylistSlot(QString name);

    void songFinished(QMediaPlayer::MediaStatus status);

    void shuffledPlay();

    void on_Next_clicked(int index = 1);

    void on_Previous_clicked();

    void on_Repeat_clicked(bool checked);

    void on_Shuffle_clicked(bool checked);

    void on_Liked_clicked(bool checked);

private:
    Ui::MainScreen *ui;
    QStandardItemModel* playlistModel;
    User** user;                        //for polymorphism purposes
    QStandardItemModel* songModel;
    QMediaPlayer* audioPlayer;
    QAudioOutput* audioOutput;
    QList<Song*> searchResults;
    Song* currentSong;
    QMediaPlayer* metaDataExtractor;
    Listener* baby;
    bool shuffle;
    bool shiftFlag;
    int currentPlaylist;

    void updatePlaylistView();

    void updateSongView(const QList<Song*>& songs);

    void searchSongs(const QString& query);
};

#endif // MAINSCREEN_H
