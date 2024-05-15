#include "listener.h"

Listener::Listener(const QString &username) : User(username)
{
    // call the setUserFolderPath on yo own ig
    // setPlaylists();
    // setAllSongs();
}

void Listener::addPlaylist(Playlist *playlist)
{
    playlists.append(playlist);
}

void Listener::removePlaylist(Playlist *playlist)
{
    playlists.removeOne(playlist);
}

void Listener::setUserFolderPath()
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char path[] = "/Data/Users/";
    strcat_s(CurrentPath, path);

    userFolderPath.assign(CurrentPath);
    userFolderPath = userFolderPath + username.toStdString();

    //added these over here from the constructor so that when userFolderpath func is called; this gets called in sequence
    setPlaylists();
    setAllSongs();
}

void Listener::setPlaylists()
{
    string play = userFolderPath + "/playlistData.txt";
    qDebug() << "Playlist file path:" << QString::fromStdString(play);

    ifstream playlistData;
    playlistData.open(play, ios::in);
    qDebug() << "Playlist file opened successfully?" << playlistData.is_open();

    if (!playlistData)
    {
        qDebug() << "setPlaylists File does not exist";
    }
    else
    {
        string name;

        while (getline(playlistData, name))
        {
            qDebug() << "Playlist name:" << QString::fromStdString(name);
            QString qname = QString::fromStdString(name);
            Playlist *p1 = new Playlist(qname, username); // Allocate memory dynamically; IM AN IDIOT I TRIED TO SEND AN OBJECT CREATED WITHIN LOCAL SCOPE INTO A FUNCTION: FRICKING OBV IT WILL GET DESTROYED; IT DESTROYED MY MENTAL PEACE
            addPlaylist(p1);
        }

        playlistData.close();
    }
}

void Listener::setAllSongs()
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char path[] = "/Data/Songs/songsData.txt";
    strcat_s(CurrentPath, path);

    ifstream allSongs;
    allSongs.open(CurrentPath, ios::in);
    qDebug() << "File opened successfully?" << allSongs.is_open();

    if(!allSongs)
    {
        qDebug() << "File does not exist";
    }
    else
    {
        string name;

        while (getline(allSongs, name))
        {
            size_t pos = name.find(',');

            string songName = name.substr(0, pos);

            string artistName = name.substr(pos + 2);

            qDebug() << "Song name:" << QString::fromStdString(songName);
            QString qname = QString::fromStdString(songName);
            QString artName = QString::fromStdString(artistName);

            Song* searchSong = new Song(qname);
            searchSong->artist = artName;

            all_Songs.append(searchSong);
        }

        allSongs.close();
    }
}

bool Listener::newPlaylist(Playlist *playlist)
{
    for (Playlist* playlistTemp : playlists)
    {
        if (playlist->playlistName == playlistTemp->playlistName)
        {
            return 0;
        }
    }

    string play = userFolderPath + "/playlistData.txt";

    ofstream playlistData;

    playlistData.open(play, ios::app);

    if (!playlistData)
    {
        qDebug() << "File does not exist";
    }
    else
    {
        playlistData << playlist->playlistName.toStdString() << endl;

        playlistData.close();

        ofstream playlistFile;

        string playName = userFolderPath + "/" + playlist->playlistName.toStdString() + ".txt";
        playlistFile.open(playName, ios::out);

        playlistFile.close();

        addPlaylist(playlist);
    }

    return 1;
}

bool Listener::existSong(Song *song)
{
    for (Song* songTemp : all_Songs)
    {
        if (songTemp->title == song->title)
        {
            return true;
        }
    }
    return false;
}

// void Listener::setSongFolderPath()
// {

//     char CurrentPath[_MAX_PATH];
//     _getcwd(CurrentPath, 260);   // current path of directory

//     char name[] = "/Data/Songs/";
//     strcat_s(CurrentPath, name);

//     songFolderPath.assign(CurrentPath);
//     songFolderPath = songFolderPath + title.toStdString() + ".mp3";

//     qDebug() << songFolderPath;
// }

Playlist *Listener::getPlaylist(QString name)
{
    for (Playlist* playlist : playlists)
    {
        if (playlist->playlistName == name)
        {
            return playlist;
        }
    }

    return nullptr;
}
