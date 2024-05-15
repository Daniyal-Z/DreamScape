#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <QDebug>
#include "song.h"
#include <QtMultimedia>
using namespace std;

class Playlist
{
public:
    QString playlistName;
    string filePath;
    QList<Song*> songs;
    QString username;

    Playlist(QString name, QString username);

    void addSong(Song* song);

    void removeSong(Song* song);

    void setPlaylistFilePath(QString username);

    void setSongs();

    bool newSong(Song* song);

    bool removeFromPlaylist(Song* song);

    // bool setLiked(Song* song, bool likedNew);

    // int findSong(Song* song);
};

#endif // PLAYLIST_H
