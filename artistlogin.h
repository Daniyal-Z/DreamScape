#ifndef ARTISTLOGIN_H
#define ARTISTLOGIN_H

#include <QMainWindow>
using namespace std;

#include "user.h"


namespace Ui {
class artistLogin;
}

class artistLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit artistLogin(QWidget *parent = nullptr);
    ~artistLogin();

    bool signUp(const string& username, const string& password);
    bool signIn(const string& username, const string& password);
    bool usernameExists(const string& username);

public slots:
    void receiveUser(User** user);

private:
    Ui::artistLogin *ui;
    User** user;
    //string artistName;

signals:
    void initialWindowClicked();

private slots:
    void on_goBack_2_clicked();
    void on_Sign_In_2_clicked();
    void on_Sign_Up_2_clicked();
};

#endif // ARTISTLOGIN_H
