#include "artistlogin.h"
#include "ui_artistlogin.h"

#include "user.h"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <io.h>
#include <direct.h>
#include <Qfile>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

#include "artistwindow.h"

artistLogin::artistLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::artistLogin)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
}

artistLogin::~artistLogin()
{
    delete ui;
}

void artistLogin::on_goBack_2_clicked()
{
    emit initialWindowClicked();
}

QString usern, pass;

bool artistLogin::signUp(const string& username, const string& password)
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char name[] = "/Data/Artists/artistsData.txt";
    strcat_s(CurrentPath, name);

    // Check if username already exists
    if (usernameExists(username))
    {
        cout << "Username already exists!" << endl;
        QMessageBox::information(this,"Sign Up","Username Already Exists");
        return false;
    }

    // Create a new artist file
    QFile file(CurrentPath);

    if (file.open(QFile::Append | QFile::Text))
    {
        QTextStream out(&file);
        QString q1 = QString::fromStdString(username);
        QString q2 = QString::fromStdString(password);
        out << q1 << "|" << q2 << "\n";
        file.close();
        cout << "Sign-up successful!" << endl;
        QMessageBox::information(this, "Sign Up", "Sign Up Successful");
        return true;
    }
    else
    {
        cout << "Error creating file!" << endl;
    }

    return false;
}

bool artistLogin::signIn(const string& username, const string& password)
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char name[] = "/Data/Artists/artistsData.txt";
    strcat_s(CurrentPath, name);

    // Read the artist file
    QFile file(CurrentPath);

    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split("|");
            if (parts.size() >= 2 && parts[0].toStdString() == username && parts[1].toStdString() == password)
            {
                cout << "Sign-in successful!" << endl;

                //this->username = username;                     //stores the user name for signed in artist
                //this->password = password;                     //stores the user password for the signed in artist
                return true;
            }
        }
        file.close();
    }

    cout << "Invalid username or password!" << endl;
    return false;
}

bool artistLogin::usernameExists(const string& username)
{
    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char name[] = "/Data/Artists/artistsData.txt";
    strcat_s(CurrentPath, name);

    // Read the artist file
    QFile file(CurrentPath);

    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split("|");
            if (parts.size() >= 1 && parts[0].toStdString() == username)
            {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void artistLogin::receiveUser(User **user)
{
    this->user = user;
}

void artistLogin::on_Sign_In_2_clicked()
{
    usern = ui->username_2->text();
    pass = ui->password_2->text();

    string user1 = usern.toStdString();
    string pass1 = pass.toStdString();

    //Artist art;
    //cout<<user1<<"       pass"<<pass1;
    bool flag = signIn(user1, pass1);

    if(flag)
    {
        QMessageBox::information(this,"Login","UserName/Password Approved");
        this->close();
        ArtistWindow *aWindow =  new ArtistWindow(user, usern, this);
        //aWindow->username = user1;
        //aWindow->mainSetup();
        aWindow->show();
    }
    else
    {
        QMessageBox::information(this,"Login","incorrect UserName/Password");
    }
}

void artistLogin::on_Sign_Up_2_clicked()
{   
    usern = ui->username_2->text();
    pass = ui->password_2->text();

    string user1 = usern.toStdString();
    string pass1 = pass.toStdString();

    bool flag = signUp(user1, pass1);

    if(flag)
    {
        char CurrentPath[_MAX_PATH];
        _getcwd(CurrentPath, 260);   // current path of directory

        char name[] = "/Data/Artists/";
        strcat_s(CurrentPath, name);
        strcat_s(CurrentPath, user1.c_str());
        strcat_s(CurrentPath, ".txt");

        fstream file;
        file.open(CurrentPath, ios::out);
        file.close();
    }
}

