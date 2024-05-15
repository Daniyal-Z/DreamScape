#include "UserPass.h"
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <QDebug>
using namespace std;

bool checkUsername(const string& username)
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char name[] = "/Data/Users";
    strcat_s(CurrentPath, name);
    strcat_s(CurrentPath, "/");
    strcat_s(CurrentPath, "userData.txt");

    if (username == "")
    {
        return 0;
    }

    ifstream userpass;
    userpass.open(CurrentPath, ios::in);

    if (!userpass)
    {
        cout << "File does not exist";

        return 0;
    }
    else
    {
        string userN;

        while (userpass >> userN)
        {
            if (userN == username)
            {
                userpass.close();
                return 1;
            }

            userpass >> userN;               // since usernames and passwords are stored together we skip the password
        }

        userpass.close();
        return 0;
    }
}

bool checkPassword(const string& username, const string& password)
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char name[] = "/Data/Users/";
    strcat_s(CurrentPath, name);
    strcat_s(CurrentPath, "/");
    strcat_s(CurrentPath, "userData.txt");

    if (password == "")
    {
        return 0;
    }

    ifstream userpass;
    userpass.open(CurrentPath, ios::in);

    if (!userpass)
    {
        cout << "File does not exist";

        return 0;
    }
    else
    {
        string passW;

        while (userpass >> passW)
        {
            if (passW == username)
            {
                userpass >> passW;

                if (passW == password)
                {
                    userpass.close();
                    return 1;
                }
            }
            userpass >> passW;                    // since usernames and passwords are stored together we skip the username
        }

        userpass.close();
        return 0;
    }
}

int newUser(const string& username, const string& password)
{
    // get path for file
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char name[] = "/Data/Users/";
    strcat_s(CurrentPath, name);
    strcat_s(CurrentPath, "/");
    strcat_s(CurrentPath, "userData.txt");

    // verification
    if (!checkUsername(username) && username != "" && password != "")      // omg dy see this big brain move that I just made; I just used the checkUsername function originally made for the Sign In
    {
        ofstream userpass;

        userpass.open(CurrentPath, ios::app);      // open file to append username and password at the end of the file (obv we could organise it but no need for it)

        if (!userpass)
        {
            cout << "File does not exist";
        }
        else
        {
            userpass << username << endl;
            userpass << password << endl;
        }

        userpass.close();

        // new path
        char CurrentPath2[_MAX_PATH];
        _getcwd(CurrentPath2, _MAX_PATH);   // current path of directory
        strcat_s(CurrentPath2, name);
        strcat_s(CurrentPath2, username.c_str());

        // create a new folder for new user
        if (_mkdir(CurrentPath2) != 0)
        {
            cout << "Username already exists or can't create new folder\n";
        }
        else
        {
            cout << "Created successfully!\n";
        }

        // update path to create new txt file for playlist data
        strcat_s(CurrentPath2, "/playlistData.txt");

        // create new txt file
        userpass.open(CurrentPath2, ios::out);

        userpass.close();

        return 1;      // new user created
    }
    else if (username == "")
    {
        return 3;      // username not entered
    }
    else if (password == "")
    {
        return 4;      //password not entered
    }
    else
    {
        return 2;      // username exists
    }
}

bool forgotPassword(const string& username, const string& newPassword)
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char name[] = "/Data/Users/";
    strcat_s(CurrentPath, name);
    strcat_s(CurrentPath, "userData.txt");

    char tempPath[_MAX_PATH];
    _getcwd(tempPath, 260);
    strcat_s(tempPath, name);
    strcat_s(tempPath, "tempFile.txt");

    cout << CurrentPath << endl;
    cout << tempPath << endl;

    ofstream tempFile;
    tempFile.open(tempPath, ios::out);

    ifstream userpass;

    userpass.open(CurrentPath);

    if (!userpass)
    {
        cout << "File does not exist";
        return 0;
    }

    if (!tempFile)
    {
        cout << "Temp file not created";
        return 0;
    }

    string line;

    while(userpass >> line)
    {
        if(line == username)
        {
            userpass >> line;
        }
        else
        {
            tempFile << line << endl;
        }
    }

    userpass.close();
    tempFile.close();

    if (remove(CurrentPath) != 0)
    {
        qDebug() << "Error deleting the original file";
        return false;
    }

    if (rename(tempPath, CurrentPath) != 0)
    {
        qDebug() << "Error renaming the temporary file";
        return false;
    }

    ofstream userpass2;

    userpass2.open(CurrentPath, ios::app);      // open file to append username and password at the end of the file (obv we could organise it but no need for it)

    if (!userpass2)
    {
        cout << "File does not exist";
    }
    else
    {
        userpass2 << username << endl;
        userpass2 << newPassword << endl;
    }

    userpass2.close();

    return 1;
}



