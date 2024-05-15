#ifndef INITIALWINDOW_H
#define INITIALWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "artistlogin.h"
#include "user.h"

namespace Ui {
class InitialWindow;
}

class InitialWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InitialWindow(QWidget *parent = nullptr);
    ~InitialWindow();

private slots:
    void on_Listener_clicked();

    void moveBack();

    void on_Artist_clicked();

private:
    Ui::InitialWindow *ui;
    User** user;
    Login login;
    artistLogin aLogin;

signals:
    void listenerClicked(User **user); // Signal to pass the user variable
    void artistClicked(User **user);  // Signal to pass the user variable
};

#endif // INITIALWINDOW_H
