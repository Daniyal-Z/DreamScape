#include <windows.h>  // this one right here
#include "artistwindow.h"
#include "ui_artistwindow.h"
#include "initialwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

//#include <stdio.h>
// #include <io.h>
// #include <direct.h>

ArtistWindow::ArtistWindow(User** user, const QString& username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ArtistWindow), user(user)
{
    ui->setupUi(this);

    artist = new Artist(username);

    ui->artist->setText(username);

    user[0] = artist;
    user[0]->setUserFolderPath();

    mainSetup();
}

ArtistWindow::~ArtistWindow()
{
    delete ui;
}

void ArtistWindow::mainSetup()
{
    string aFile;

    aFile.assign(artist->userFolderPath);
    string uName = (artist->username).toStdString() + ".txt";

    aFile.append(uName);

    QString qFile = QString::fromStdString(aFile);

    //cout << "User   : " << (artist->username).toStdString() << endl;

    int songCount;
    songCount = songNum(qFile);

    populateListWidget();
    ui->songNumber->display(songCount);
    populateSongTable();
}

void ArtistWindow::on_addSong_clicked()
{
    QFileDialog fileDialog(this);

    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setNameFilter(tr("Audio Files (*.mp3 *.wav)"));

    if (fileDialog.exec())
    {
        // Get the path of the selected file
        QString songFilePath = fileDialog.selectedFiles().first();

        // Extract the base name of the file (without the path and extension)
        QString songName = QFileInfo(songFilePath).completeBaseName();             // now it can extract the entire name

        // Check if song name already exists in both files
        bool existsInUsernameFile = false;
        bool existsInSongsDataFile = false;

        // path to artist
        string aFile;

        aFile.assign(artist->userFolderPath);
        string uName = (artist->username).toStdString() + ".txt";

        aFile.append(uName);

        QString qFile = QString::fromStdString(aFile);

        // Open the artist's file
        QFile artistFile(qFile);
        if (artistFile.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&artistFile);
            // Check if the song name exists in the artist's file
            while (!in.atEnd()) {
                QString existingSongName = in.readLine();
                if (existingSongName == songName)
                {
                    existsInUsernameFile = true;
                    break;
                }
            }
            artistFile.close();
        }

        // Open songsData.txt
        char CurrentPath[_MAX_PATH];
        _getcwd(CurrentPath, 260);   // current path of directory

        char path[] = "/Data/Songs/songsData.txt";
        strcat_s(CurrentPath, path);

        string pFile;
        pFile.assign(CurrentPath);
        QString fName = QString::fromStdString(pFile);

        QFile songsDataFile(fName);

        // Check if the song name exists in songsData.txt
        if (songsDataFile.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&songsDataFile);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split(",");
                if (parts.first() == songName)
                {
                    existsInSongsDataFile = true;
                    break;
                }
            }
            songsDataFile.close();
        }

        // If the song name exists in either file, show an error message
        if (existsInUsernameFile || existsInSongsDataFile)
        {
            // we can include two diff output errors
            QMessageBox::information(this, "Song already exists", "This song is already in your library.");
            return;
        }

        // If the song doesn't exist in either file, add it to both files
        if (artistFile.open(QFile::Append | QFile::Text))
        {
            QTextStream out(&artistFile);
            out << songName << "\n";
            artistFile.close();
        }


        if (songsDataFile.open(QFile::Append | QFile::Text))
        {
            QTextStream out(&songsDataFile);
            out << songName << ", " << artist->username << "\n";
            songsDataFile.close();
        }

        string songFile = songFilePath.toStdString();

        // source path where the song file exists
        wstring wideSource(songFile.begin(), songFile.end());
        LPCWSTR source = wideSource.c_str();

        // destination path; Songs directory where it will now be copied to
        char CurrentPath2[_MAX_PATH];
        _getcwd(CurrentPath2, 260);   // current path of directory

        char path2[] = "/Data/Songs/";
        strcat_s(CurrentPath2, path2);

        string copyFile;
        copyFile.assign(CurrentPath2);
        copyFile.append(songName.toStdString());
        copyFile.append(".mp3");

        wstring wideDestination(copyFile.begin(), copyFile.end());
        LPCWSTR destination = wideDestination.c_str();

        BOOL result = CopyFile(source, destination, TRUE);
        if (result != 0)
        {
            // Copy successful
            printf("File copied successfully.\n");
        }
        else
        {
            // Error handling
            DWORD error = GetLastError();
            printf("Failed to copy file. Error code: %lu\n", error);
        }
    }

    // update the UI
    mainSetup();
}

void ArtistWindow::populateListWidget()
{
    ui->songsList->clear();

    char CurrentPath[_MAX_PATH];
    _getcwd(CurrentPath, 260);   // current path of directory

    char path[] = "/Data/Songs/songsData.txt";
    strcat_s(CurrentPath, path);

    string aFile;
    aFile.assign(CurrentPath);
    QString fName = QString::fromStdString(aFile);

    QFile file(fName);

    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        QStringList songs;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            songs.append(parts.first());
        }
        ui->songsList->addItems(songs);
        file.close();
    }
}

int ArtistWindow::songNum(const QString& fileName)
{
    int songCount = 0;
    QFile file(fileName);
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            in.readLine();
            songCount++;
        }
        file.close();
    }
    return songCount;
}

void ArtistWindow::populateSongTable()
{
    ui->tableSongs->clearContents();

    string aFile;

    aFile.assign(artist->userFolderPath);
    string uName = (artist->username).toStdString() + ".txt";

    aFile.append(uName);

    QString qFile = QString::fromStdString(aFile);

    QString userQ = artist->username;

    QFile file(qFile);

    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        int row = 0;
        while (!in.atEnd())
        {
            QString songName = in.readLine();
            QTableWidgetItem *srNoItem = new QTableWidgetItem(QString::number(row + 1));
            QTableWidgetItem *artistNameItem = new QTableWidgetItem(userQ);
            QTableWidgetItem *songNameItem = new QTableWidgetItem(songName);
            ui->tableSongs->insertRow(row);
            ui->tableSongs->setItem(row, 0, srNoItem);
            ui->tableSongs->setItem(row, 1, artistNameItem);
            ui->tableSongs->setItem(row, 2, songNameItem);
            row++;
        }

        file.close();
    }
}
/// remove song


void ArtistWindow::removeSong()
{
    QString songName = ui->removeSong->text();

    string aFile;

    aFile.assign(artist->userFolderPath);
    string uName = (artist->username).toStdString() + ".txt";

    aFile.append(uName);

    QString qFile = QString::fromStdString(aFile);

    QFile file(qFile);

    if (file.open(QFile::ReadWrite | QFile::Text))
    {
        QTextStream in(&file);
        QString fileContent;
        bool songFound = false;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            if (line == songName)
            {
                songFound = true;
                continue;
            }
            fileContent += line + "\n";
        }
        file.resize(0);
        QTextStream out(&file);
        out << fileContent;
        file.close();
        if (songFound)
        {
            char CurrentPath[_MAX_PATH];
            _getcwd(CurrentPath, 260);   // current path of directory

            char path[] = "/Data/Songs/songsData.txt";
            strcat_s(CurrentPath, path);

            string aFile;
            aFile.assign(CurrentPath);
            QString fName = QString::fromStdString(aFile);

            QFile songsDataFile(fName);

            if (songsDataFile.open(QFile::ReadWrite | QFile::Text))
            {
                QTextStream in(&songsDataFile);
                QString fileContent;
                while (!in.atEnd())
                {
                    QString line = in.readLine();
                    QStringList parts = line.split(",");
                    if (parts.first() != songName)
                    {
                        fileContent += line + "\n";
                    }
                }
                songsDataFile.resize(0);
                QTextStream out(&songsDataFile);
                out << fileContent;
                songsDataFile.close();
            }
        }
        else
        {
            QMessageBox::warning(this, "Error", "Song not found!");
        }
    }
    mainSetup();

}

void ArtistWindow::on_ok_clicked()
{
    removeSong();
}

void ArtistWindow::on_actionLog_Out_triggered()
{
    this->close();
    InitialWindow* newU = new InitialWindow(this);
    newU->show();
}

