#ifndef LISTENER_H
#define LISTENER_H

#include "user.h"

class Listener : public User
{
public:
    Listener();

    QList<Playlist*> playlists;
    QList<Song*> all_Songs;
    //string songFolderPath;

    Listener(const QString& username);

    void addPlaylist(Playlist* playlist);

    void removePlaylist(Playlist* playlist);

    void setUserFolderPath();

    void setPlaylists();

    void setAllSongs();

    bool newPlaylist(Playlist* playlist);

    bool existSong(Song* song);

    //void setSongFolderPath();

    Playlist* getPlaylist(QString name);
};

#endif // LISTENER_H
