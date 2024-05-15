#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QDialog>

namespace Ui {
class Sign_Up;
}

class Sign_Up : public QDialog
{
    Q_OBJECT

public:
    explicit Sign_Up(QWidget *parent = nullptr);
    ~Sign_Up();

private slots:
    void on_Sign_In_clicked();

    void on_Sign_Up_2_clicked();

    void on_newUser_editingFinished();

    void on_confirmation_stateChanged(int arg1);

private:
    Ui::Sign_Up *ui;
    bool confirmation;

signals:
    void loginWindowClicked();
};

#endif // SIGN_UP_H
