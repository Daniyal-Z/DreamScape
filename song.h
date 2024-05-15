#ifndef SONG_H
#define SONG_H

#include <QString>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <QDebug>
using namespace std;

class Song
{
public:
    QString title;
    QString artist;
    qint64 duration;
    string filePath;
    bool liked;

    Song(QString name);

    void setfilePath();
};

#endif // SONG_H
