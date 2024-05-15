#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "sign_up.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

public slots:
    void receiveUser(User **user); // Slot to receive the user variable
    void newPassword(QString name, QString pass);

private slots:
    void on_Sign_In_clicked();

    void on_Sign_Up_clicked();

    void on_username_editingFinished();

    void on_confirmation_stateChanged(int arg1);

    void on_goBack_clicked();

    void moveBack_Login();

    void on_forgotPassword_clicked();

private:
    Ui::Login *ui;
    User** user;
    Sign_Up signUp_Win;
    bool confirmation;

signals:
    void initialWindowClicked();
};
#endif // LOGIN_H
