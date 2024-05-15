#include "song.h"

Song::Song(QString name)
{
    title = name;
    liked = false;
    setfilePath();
}

void Song::setfilePath()
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char name[] = "/Data/Songs/";
    strcat_s(CurrentPath, name);

    filePath.assign(CurrentPath);
    filePath = filePath + title.toStdString() + ".mp3";

    qDebug() << filePath;
}

