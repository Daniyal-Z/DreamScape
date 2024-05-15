#ifndef USER_H
#define USER_H

#include <QString>
#include "playlist.h"
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <QDebug>
using namespace std;

class User
{
public:
    User();

    QString username;
    string userFolderPath;

    User(const QString& username);

    virtual void setUserFolderPath() = 0;
};

#endif // USER_H
