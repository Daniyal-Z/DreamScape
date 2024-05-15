#include "artist.h"

Artist::Artist(const QString &username) : User(username)
{}

void Artist::setUserFolderPath()
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char path[] = "/Data/Artists/";
    strcat_s(CurrentPath, path);

    userFolderPath.assign(CurrentPath);
}
