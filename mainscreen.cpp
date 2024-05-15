#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "initialwindow.h"
#include "newplaylist.h"

#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <iostream>
#include <time.h>

#include <QMessageBox>

MainScreen::MainScreen(User** user, const QString& username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScreen), user(user)                 // user that we get from our login is initialised
{
    ui->setupUi(this);

    ui->userDetails->setText(username);

    // for shuffling; rand() was used
    srand(time(0));

    baby = new Listener(username);

    user[0] = baby;
    user[0]->setUserFolderPath();       // essentially the core function call for Listener that sets it up rather than the constructor doing it

    // audio to be played
    audioPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    audioPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);

    // meta data extractor
    metaDataExtractor = new QMediaPlayer(this);

    // connection for play_pause button
    connect(ui->play_pause, &QPushButton::clicked, this, &MainScreen::on_play_pause_clicked);

    ui->Volume->setSliderPosition(99);

    // connection for seek bar
    connect(audioPlayer, &QMediaPlayer::durationChanged, ui->Seek_Bar, &QSlider::setMaximum);
    connect(audioPlayer, &QMediaPlayer::positionChanged, ui->Seek_Bar, &QSlider::setValue);
    connect(ui->Seek_Bar, &QSlider::sliderMoved, audioPlayer, &QMediaPlayer::setPosition);

    // connection for volume
    connect(audioOutput, &QAudioOutput::volumeChanged, this, &MainScreen::updateVolumeSlider);
    connect(ui->Volume, &QSlider::sliderMoved, this, &MainScreen::setVolume);

    // connection for volume/mute button
    connect(ui->Volume_Mute, &QPushButton::clicked, this, &MainScreen::on_Volume_Mute_clicked);

    // connection for power button
    connect(ui->powerButton, &QPushButton::clicked, this, &MainScreen::on_powerButton_clicked);

    // Total Time Duration
    connect(audioPlayer, &QMediaPlayer::durationChanged, this, &MainScreen::SetDuration);

    // Current/Elapsed Time
    connect(audioPlayer, &QMediaPlayer::positionChanged, this, &MainScreen::SetCurrentTime);

    // Liked Button
    //connect(ui->Liked, &QPushButton::clicked, this, &MainScreen::on_Liked_clicked);

    // shuffle default state
    shuffle = false;

    // column title
    QStringList headers = {"Song Title", "Artist", "Duration"};

    // playlists view model
    playlistModel = new QStandardItemModel(this);
    ui->playlistView->setModel(playlistModel);

    // songs view model
    songModel = new QStandardItemModel(this);
    songModel->setHorizontalHeaderLabels(headers);
    ui->songView->setModel(songModel);

    // differentiate between search results and songs of playlists
    shiftFlag = false;

    // connection for search bar
    connect(ui->searchBar, &QLineEdit::textChanged, this, &MainScreen::onSearchTextChanged);

    // to load the playlists in the model
    updatePlaylistView();

    // initial song view model
    InitialView();

    // connection for playlist and song view
    connect(ui->playlistView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainScreen::onPlaylistSelected);
    connect(ui->songView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainScreen::onSongSelected);

    // connection for automatic play of the next song in line
    connect(audioPlayer, &QMediaPlayer::mediaStatusChanged, this, &MainScreen::songFinished);
}

MainScreen::~MainScreen()
{
    delete audioPlayer;
    delete audioOutput;
    delete ui;
}

void MainScreen::on_play_pause_clicked(bool checked)
{
    //qDebug() << "Button clicked, checked: " << checked;
    if (checked)
    {
        audioPlayer->play();
    }
    else
    {
        audioPlayer->pause();
    }
}

void MainScreen::SetDuration(qint64 durationMilliseconds)
{
    QTime duration(0, 0, 0);
    duration = duration.addMSecs(durationMilliseconds); // Convert to QTime format

    // Format the duration as HH:MM:SS
    QString formattedDuration = duration.toString("mm:ss");

    // Set the text of the QLabel
    ui->Total_Time->setText(formattedDuration);
}

void MainScreen::SetCurrentTime()
{
    QTime duration(0, 0, 0);
    duration = duration.addMSecs(audioPlayer->position()); // Convert to QTime format

    // Format the duration as HH:MM:SS
    QString formattedDuration = duration.toString("mm:ss");

    // Set the text of the QLabel
    ui->Current_Time->setText(formattedDuration);
}

void MainScreen::updateVolumeSlider(qreal volume)
{
    ui->Volume->setValue(static_cast<int>(volume * ui->Volume->maximum()));
}

void MainScreen::setVolume(int value)
{
    qreal volume = static_cast<qreal>(value) / ui->Volume->maximum();
    audioOutput->setVolume(volume);
}

void MainScreen::on_actionLog_Out_triggered()
{
    audioPlayer->stop();
    this->close();
    InitialWindow* newU = new InitialWindow(this);
    newU->show();
}

void MainScreen::on_Volume_Mute_clicked(bool checked)
{
    if (checked)
    {
        audioOutput->setVolume(0);
    }
    else
    {
        audioOutput->setVolume(100);
    }
}

void MainScreen::on_powerButton_clicked(bool checked)
{
    if (checked)
    {
        audioPlayer->stop();
        this->close();
    }
}

//------------------------------------------SLOTS FOR MODELS------------------------------------------------//

void MainScreen::InitialView()            // displays the first 10 songs in songData.txt
{
    songModel->clear();

    QStringList headers = {"Song Title", "Artist", "Duration"};
    songModel->setHorizontalHeaderLabels(headers);

    for(int i = 0; i < 3; i++)
    {
        ui->songView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
    }

    int i = 0;

    for (Song* song: baby->all_Songs)
    {
        if (i < 10)
        {
            // song title
            QStandardItem* item = new QStandardItem(song->title);
            item->setData(QVariant::fromValue(song), Qt::UserRole);

            // song's meta data
            metaDataExtractor->setSource(QUrl::fromLocalFile(QString((song->filePath).c_str())));

            qDebug() << QString((song->filePath).c_str());

            QMediaMetaData metaData = metaDataExtractor->metaData();

            // artist name
            // QVariant artist = metaData.value(QMediaMetaData::AlbumArtist);

            // QStandardItem* item2;

            // if (artist.isNull())
            // {
            //     artist = metaData.value(QMediaMetaData::ContributingArtist);

            //     if(artist.isNull())
            //     {
            //         item2 = new QStandardItem("Unknown");

            //         artist = "Unknown";
            //     }
            //     else
            //     {
            //         item2 = new QStandardItem(artist.toString());
            //     }
            // }
            // else
            // {
            //     item2 = new QStandardItem(artist.toString());
            // }

            // song->artist = artist.toString();

            // qDebug() << artist.toString();

            QStandardItem* item2 = new QStandardItem(song->artist);
            item2->setData(QVariant::fromValue(song), Qt::UserRole);

            // duration
            qint64 durationMilliseconds = metaDataExtractor->duration();

            QTime duration(0, 0, 0);
            duration = duration.addMSecs(durationMilliseconds); // Convert to QTime format

            // Format the duration as HH:MM:SS
            QString formattedDuration = duration.toString("mm:ss");

            QStandardItem* item3 = new QStandardItem(formattedDuration);

            songModel->appendRow({item, item2, item3});

            i++;
        }
    }
}

void MainScreen::onPlaylistSelected(const QItemSelection& selected, const QItemSelection& deselected)
{
    Q_UNUSED(deselected);

    QModelIndex current = ui->playlistView->selectionModel()->currentIndex();

    if (current.isValid())
    {
        Playlist* playlist = current.data(Qt::UserRole).value<Playlist*>();        // for the current index selected in the playlist model, the playlist selected is loaded in the song model
        shiftFlag = true;
        currentPlaylist = current.row();
        updateSongView(playlist->songs);
    }
}

void MainScreen::onSongSelected(const QItemSelection& selected, const QItemSelection& deselected)
{
    audioPlayer->stop();
    Q_UNUSED(deselected);

    QModelIndex current = ui->songView->selectionModel()->currentIndex();

    if (current.isValid() && current.column() == 0)
    {
        audioPlayer->stop();               // pichla wala rokna hei
        ui->play_pause->setChecked(true);   // play pause button ko bhi qabu mei rakhna hei

        Song* song = current.data(Qt::UserRole).value<Song*>();                         // for the current index selected in the song model, the song selected is loaded and played
        audioPlayer->setSource(QUrl::fromLocalFile(QString((song->filePath).c_str())));
        audioPlayer->play();

        // set the name on the play bar
        ui->songName->setText(song->title);
        ui->artistName->setText(song->artist);

        currentSong = new Song(song->title);         // current song is assigned the title of the local Song var
        currentSong->artist = song->artist;
        //currentSong->liked = song->liked;

        //ui->Liked->setChecked(baby->playlists[currentPlaylist]->songs[baby->playlists[currentPlaylist]->findSong(song)]->liked);
    }
    else if (current.isValid() && current.column() == 3)
    {
        Song* songRemove = baby->playlists[currentPlaylist]->songs[current.row()];

        if(baby->playlists[currentPlaylist]->removeFromPlaylist(songRemove))
        {
            QMessageBox::information(this, "Remove Song", "Song removed from Playlist successfully");
        }
        else
        {
            QMessageBox::information(this, "Remove Song", "Song could not be removed");
        }

        updateSongView(baby->playlists[currentPlaylist]->songs);
    }
}

void MainScreen::onSearchTextChanged(const QString& query)
{
    if (query != "")
    {
        searchSongs(query);           // this is just for searching and it stores the search results(songs only for now) in Song* var
        shiftFlag = false;
        updateSongView(searchResults);        // this replaces the songModel with the search results
    }
    else
    {
        InitialView();
    }

    ui->playlistView->clearSelection();
}

void MainScreen::on_newPlaylist_clicked()
{
    NewPlaylist* newPlaylist = new NewPlaylist(this);
    newPlaylist->show();

    connect(newPlaylist, &NewPlaylist::playlistCreated, this, &MainScreen::newPlaylistSlot);

    ui->newPlaylist->setChecked(false);
}

void MainScreen::on_addToPlaylist_currentIndexChanged(int index)
{
    //user->playlists[index]->addSong(currentSong);        // I think it is very evident what this does; Also the currentSong data member
                                                         // exists because Add to Playlist had to be done for the current song being played
    // Okay so the above function already exists within the function neeche

    if (index != -1)
    {
        if(!(baby->playlists[index]->newSong(currentSong)))        // Here once again youd need to implement checks so that it doesnt duplicate the songs
        {
            QMessageBox::information(this, "Add to Playlist", "Song already exists in the playlist");
        }
    }

    ui->addToPlaylist->setCurrentIndex(-1);
}

void MainScreen::newPlaylistSlot(QString name)
{
    Playlist* new_Playlist = new Playlist(name, baby->username);      // to make a new playlist make a Playlist* var to be passed as a para
    if (baby->newPlaylist(new_Playlist))
    {
        //updatePlaylistView();    // update the view or it wont show the new playlist

        QStandardItem* item = new QStandardItem(name);
        item->setData(QVariant::fromValue(new_Playlist), Qt::UserRole);
        playlistModel->appendRow(item);

        // update the combo box asw; this is for adding a song to a playlist
        ui->addToPlaylist->addItem(name);
    }
    else
    {
        QMessageBox::information(this, "New Playlist", "Playlist with this name already exists");
    }

}

//--------------------------------------------------------------------------------------------------------//

//-------------------------------------------PRIVATE FUNCS FOR MODELS---------------------------------------------------//


void MainScreen::updatePlaylistView()
{
    playlistModel->clear();
    for (Playlist* playlist : baby->playlists)
    {
        //cout << playlist->playlistName;
        qDebug() << "before";
        qDebug() << (playlist->playlistName).toStdString();
        qDebug() << "after";
        QStandardItem* item = new QStandardItem(playlist->playlistName);
        item->setData(QVariant::fromValue(playlist), Qt::UserRole);
        playlistModel->appendRow(item);

        // update the combo box asw; this is for adding a song to a playlist
        ui->addToPlaylist->addItem(playlist->playlistName);
    }
}

void MainScreen::updateSongView(const QList<Song*>& songs)
{
    songModel->clear();

    QStringList headers = {"Song Title", "Artist", "Duration", ""};      // LESS GOO IT WORKED
    songModel->setHorizontalHeaderLabels(headers);

    //QHeaderView* horizontalHeader = ui->songView->horizontalHeader();

    ui->songView->setColumnWidth(3, 150);

    for(int i = 0; i < 4; i++)
    {
        ui->songView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
    }

    for (Song* song : songs)
    {
        if ((baby->existSong(song)))
        {
            // song title
            QStandardItem* item = new QStandardItem(song->title);
            item->setData(QVariant::fromValue(song), Qt::UserRole);

            // song's meta data
            metaDataExtractor->setSource(QUrl::fromLocalFile(QString((song->filePath).c_str())));

            qDebug() << QString((song->filePath).c_str());

            QMediaMetaData metaData = metaDataExtractor->metaData();

            QStandardItem* item2 = new QStandardItem(song->artist);
            item2->setData(QVariant::fromValue(song), Qt::UserRole);

            // duration
            qint64 durationMilliseconds = metaDataExtractor->duration();

            QTime duration(0, 0, 0);
            duration = duration.addMSecs(durationMilliseconds); // Convert to QTime format

            // Format the duration as HH:MM:SS
            QString formattedDuration = duration.toString("mm:ss");

            QStandardItem* item3 = new QStandardItem(formattedDuration);

            if (shiftFlag)
            {
                QStandardItem* item4 = new QStandardItem("Remove from Playlist");

                songModel->appendRow({item, item2, item3, item4});
            }
            else
            {
                songModel->appendRow({item, item2, item3});
            }
        }
    }
}

void MainScreen::searchSongs(const QString& query)
{
    // also the logic here could be made a bit better ig; this one just looks for any subsequence that exists in both

    searchResults.clear();
    if (query != "")
    {
        for (Song* song : baby->all_Songs)
        {
            if ((song->title.contains(query, Qt::CaseInsensitive) ||
                 song->artist.contains(query, Qt::CaseInsensitive)))
            {
                searchResults.append(song);
            }
        }
    }

    // well this might come in handy in the future when you might want to search for the names of the playlists themselves
    // but do keep in mind that searchResults is of Song type and cannot entertain playlist type variables
    // so I guess things would have to be tweaked a little bit
    // I would suggest making another searchResults type of variable
    //
    // for (Playlist* play : user->playlists)
    // {
    //     if (play->playlistName.contains(query, Qt::CaseInsensitive))
    //     {
    //         searchResults.append(play);
    //     }
    // }
}


//--------------------------------------------------------------------------------------------------------//

void MainScreen::songFinished(QMediaPlayer::MediaStatus status)
{
    // get the duration of the current song playing and match it with the current duration of the song
    if(status == audioPlayer->EndOfMedia)
    {
        if (shuffle)
        {
            shuffledPlay();
        }
        else
        {
            on_Next_clicked();     // play the next song in line
        }
    }
}

void MainScreen::shuffledPlay()
{
    int index;
    index = rand() % (songModel->rowCount());

    // make some good logic for shuffle
    // maybe make negative indexes asw; try with that

    qDebug() << index;

    on_Next_clicked(index);
}

void MainScreen::on_Next_clicked(int index)          // default value of 1 passed so that it normally (linearly) traverses through the playlist
{                                                                                       // index used so that shuffle can be used by passing random index
    QModelIndex currentIndex = ui->songView->selectionModel()->currentIndex();

    // Move the selection to the next index
    QModelIndex nextIndex = currentIndex.sibling(currentIndex.row() + index, currentIndex.column());

    // Check if the next index is valid
    if (nextIndex.isValid())
    {
        // Set the new selection
        ui->songView->selectionModel()->setCurrentIndex(nextIndex, QItemSelectionModel::ClearAndSelect);

        // Get the Song* object associated with the new selection
        Song* nextSong = nextIndex.data(Qt::UserRole).value<Song*>();

        // Set the QMediaPlayer to play the next song
        audioPlayer->setSource(QUrl::fromLocalFile(QString(nextSong->filePath.c_str())));
        audioPlayer->play();
    }
    else
    {
        // If the next index is not valid, reset the selection to the first song
        QModelIndex firstIndex = songModel->index(0, 0);
        ui->songView->selectionModel()->setCurrentIndex(firstIndex, QItemSelectionModel::ClearAndSelect);

        // Get the Song* object associated with the first song
        Song* firstSong = firstIndex.data(Qt::UserRole).value<Song*>();

        // Set the QMediaPlayer to play the first song
        audioPlayer->setSource(QUrl::fromLocalFile(QString(firstSong->filePath.c_str())));
        audioPlayer->play();
    }
}

void MainScreen::on_Previous_clicked()
{
    QModelIndex currentIndex = ui->songView->selectionModel()->currentIndex();

    // Move the selection to the prev index
    QModelIndex prevIndex = currentIndex.sibling(currentIndex.row() - 1, currentIndex.column());

    // Check if the prev index is valid
    if (prevIndex.isValid())
    {
        // Set the new selection
        ui->songView->selectionModel()->setCurrentIndex(prevIndex, QItemSelectionModel::ClearAndSelect);

        // Get the Song* object associated with the new selection
        Song* nextSong = prevIndex.data(Qt::UserRole).value<Song*>();

        // Set the QMediaPlayer to play the next song
        audioPlayer->setSource(QUrl::fromLocalFile(QString(nextSong->filePath.c_str())));
        audioPlayer->play();
    }
    else
    {
        // Last song in the playlist
        int lastRow = songModel->rowCount() - 1;

        // If the prev index is not valid, reset the selection to the first song
        QModelIndex lastIndex = songModel->index(lastRow, 0);
        ui->songView->selectionModel()->setCurrentIndex(lastIndex, QItemSelectionModel::ClearAndSelect);

        // Get the Song* object associated with the first song
        Song* lastSong = lastIndex.data(Qt::UserRole).value<Song*>();

        // Set the QMediaPlayer to play the first song
        audioPlayer->setSource(QUrl::fromLocalFile(QString(lastSong->filePath.c_str())));
        audioPlayer->play();
    }
}

void MainScreen::on_Repeat_clicked(bool checked)
{
    qDebug() << checked;

    if (checked)
    {
        audioPlayer->setLoops(-1);
    }
    else
    {
        audioPlayer->setLoops(1);
    }
}

void MainScreen::on_Shuffle_clicked(bool checked)
{
    if(checked)
    {
        shuffle = true;
    }
    else
    {
        shuffle = false;
    }
}

// void MainScreen::on_Liked_clicked(bool checked)
// {
//     qDebug() << "Liked button clicked, Checked:" << checked;
//     qDebug() << "Current song liked status:" << currentSong->liked;

//     baby->playlists[currentPlaylist]->setLiked(currentSong, checked);
// }

