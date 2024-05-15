#ifndef ARTIST_H
#define ARTIST_H

#include "user.h"

class Artist : public User
{
public:
    Artist();

    Artist(const QString& username);

    void setUserFolderPath();


};

#endif // ARTIST_H
