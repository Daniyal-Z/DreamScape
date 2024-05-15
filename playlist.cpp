#include "playlist.h"
#include <iostream>
using namespace std;

Playlist::Playlist(QString name, QString username)
{
    qDebug() << name;
    playlistName = name;
    this->username = username;
    qDebug() << playlistName;
    setPlaylistFilePath(username);
    setSongs();
}

void Playlist::addSong(Song* song)
{
    songs.append(song);
}

void Playlist::removeSong(Song* song)
{
    songs.removeOne(song);
}

void Playlist::setPlaylistFilePath(QString username)
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char name[] = "/Data/Users/";
    strcat_s(CurrentPath, name);

    filePath.assign(CurrentPath);

    //qDebug() << playlistName;
    filePath = filePath + username.toStdString() + "/" + playlistName.toStdString() + ".txt";
}

bool Playlist::newSong(Song* song)
{
    for (Song* songTemp : songs)
    {
        if (song->title == songTemp->title)
        {
            return 0;
        }
    }

    ofstream playData;
    playData.open(filePath, ios::app);

    if(!playData)
    {
        qDebug() << "playlist File does not exist";
    }
    else
    {
        playData << (song->title).toStdString() << ", " << (song->artist).toStdString() << endl;

        playData.close();

        addSong(song);
    }

    return 1;
}

bool Playlist::removeFromPlaylist(Song *song)
{
    bool found = false;

    for (Song* songTemp : songs)
    {
        if (song->title == songTemp->title)
        {
            found = true;
            break;
        }
    }

    if(found)
    {
        ifstream playData;
        playData.open(filePath, ios::in);

        char CurrentPath[_MAX_PATH];
        _getcwd(CurrentPath, 260);   // current path of directory

        char name[] = "/Data/Users/";
        strcat_s(CurrentPath, name);

        string f2;

        f2.assign(CurrentPath);

        //qDebug() << playlistName;
        f2 = f2 + username.toStdString() + "/" + "temp_playlist.txt";

        ofstream tempFile;
        tempFile.open(f2, ios::out);

        if(!playData)
        {
            qDebug() << "playlist File does not exist";
        }
        else
        {
            string line;

            while(getline(playData, line))
            {
                string songLine = (song->title).toStdString() + ", " + (song->artist).toStdString();

                if(songLine != line)
                {
                    tempFile << line << endl;
                }
            }

            playData.close();
            tempFile.close();

            if (remove(filePath.c_str()) != 0)
            {
                qDebug() << "Error deleting the original file";
                return false;
            }

            if (rename(f2.c_str(), filePath.c_str()) != 0)
            {
                qDebug() << "Error renaming the temporary file";
                return false;
            }

            removeSong(song);
            return 1;
        }
    }
    return 0;
}

void Playlist::setSongs()
{
    ifstream playlistData;
    playlistData.open(filePath, ios::in);

    if (!playlistData)
    {
        qDebug() << filePath;
        qDebug() << "set Songs File does not exist";
    }
    else
    {
        string Sname;

        while (getline(playlistData, Sname))
        {
            size_t pos = Sname.find(',');
            if (pos == std::string::npos) continue; // skip invalid lines
            //size_t secondComma = Sname.find(',', pos + 1);
            //if (secondComma == std::string::npos) continue; // skip invalid lines

            string songName = Sname.substr(0, pos);
            string artistName = Sname.substr(pos + 2);
            //string likedS = Sname.substr(secondComma + 2);

            QString qSname = QString::fromStdString(songName);
            Song* s1 = new Song(qSname);

            s1->artist = QString::fromStdString(artistName);
            //s1->liked = (likedS == "1");
            addSong(s1);
        }

        playlistData.close();
    }
}

// bool Playlist::setLiked(Song* song, bool likedNew)
// {
//     ifstream playData;
//     playData.open(filePath, ios::in);

//     char CurrentPath[_MAX_PATH];
//     _getcwd(CurrentPath, 260);   // current path of directory

//     char name[] = "/Data/Users/";
//     strcat_s(CurrentPath, name);

//     string f2;

//     f2.assign(CurrentPath);

//     //qDebug() << playlistName;
//     f2 = f2 + username.toStdString() + "/" + "temp_playlist.txt";

//     ofstream tempFile;
//     tempFile.open(f2, ios::out);

//     if(!playData)
//     {
//         qDebug() << "playlist File does not exist";
//     }
//     else
//     {
//         string line;

//         while (getline(playData, line))
//         {
//             size_t pos = line.find(song->title.toStdString() + ", " + song->artist.toStdString() + ",");
//             if (pos == string::npos)
//             {
//                 // Copy unchanged lines to temporary file
//                 tempFile << line << endl;
//             }
//             else
//             {
//                 // Modify liked status
//                 string lik;
//                 if (likedNew == 1)
//                 {
//                     lik = "1";
//                 }
//                 else
//                 {
//                     lik = "0";
//                 }

//                 tempFile << song->title.toStdString() << ", " << song->artist.toStdString() << ", " << lik << endl;
//             }
//         }

//         tempFile.close();
//         playData.close();

//         if (remove(filePath.c_str()) != 0)
//         {
//             qDebug() << "Error deleting the original file";
//             return false;
//         }

//         if (rename(f2.c_str(), filePath.c_str()) != 0)
//         {
//             qDebug() << "Error renaming the temporary file";
//             return false;
//         }

//         song->liked = likedNew;  // i swear to God if this was the one creating that error
//         return 1;
//     }
//     return 0;
// }

// int Playlist::findSong(Song* song)
// {
//     int i = 0;
//     for (Song* songTemp : songs)
//     {
//         if (song->title == songTemp->title)
//         {
//             return i;
//         }
//         i++;
//     }
// }
