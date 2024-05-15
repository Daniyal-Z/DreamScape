#include "sign_up.h"
#include "ui_sign_up.h"
#include "login.h"
#include "UserPass.h"

Sign_Up::Sign_Up(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Sign_Up)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    confirmation = false;
    connect(ui->confirmation, &QCheckBox::checkStateChanged, this, &Sign_Up::on_confirmation_stateChanged);
}

Sign_Up::~Sign_Up()
{
    delete ui;
}


void Sign_Up::on_Sign_In_clicked()
{
    emit loginWindowClicked();
}

QString usernameNew, passwordNew;

void Sign_Up::on_Sign_Up_2_clicked()
{
    usernameNew = ui->newUser->text();
    passwordNew = ui->newPass->text();

    int state = 0;

    if (confirmation)
    {
        state = newUser(usernameNew.toStdString(), passwordNew.toStdString());
    }

    if (state == 1)    // new user created
    {
        ui->validUser->setText("New User created");
    }
    else if (state == 2)
    {
        ui->validUser->setText("Username already exists");
    }
    else if (state == 3)
    {
        ui->validUser->setText("Empty field");
    }
    else if (state == 4)
    {
        ui->validUser->setText("Empty field");
    }
    else
    {
        ui->confirm_label->setText("Invalid Confirmation!");
    }
}


void Sign_Up::on_newUser_editingFinished()     // informs user if username already exists or not
{
    usernameNew = ui->newUser->text();

    if (checkUsername(usernameNew.toStdString()))
    {
        ui->validUser->setText("Username already exists");
    }
    else
    {
        ui->validUser->setText("Username available");
    }
}


void Sign_Up::on_confirmation_stateChanged(int arg1)
{
    ui->confirm_label->setText("");
    if (arg1)
    {
        confirmation = true;
    }
    else
    {
        confirmation = false;
    }
}

