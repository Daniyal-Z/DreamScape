#include "login.h"
#include "ui_login.h"
#include "UserPass.h"
#include "sign_up.h"
#include "mainscreen.h"
#include "forgotpassword.h"
#include <QMessageBox>

#include "listener.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    //this->setFixedSize(800, 600);

    ui->stackedWidget->insertWidget(1, &signUp_Win);

    connect(&signUp_Win, SIGNAL(loginWindowClicked()), this, SLOT(moveBack_Login()));

    confirmation = false;

    connect(ui->confirmation, &QCheckBox::checkStateChanged, this, &Login::on_confirmation_stateChanged);
}

Login::~Login()
{
    delete ui;
}

QString username, password;

void Login::on_Sign_In_clicked()
{
    username = ui->username->text();
    password = ui->password->text();

    ui->validPass->setText("");
    ui->validUser->setText("");

    if (checkUsername(username.toStdString()))
    {
        if (checkPassword(username.toStdString(), password.toStdString()) && confirmation)
        {
            //ui->statusPass->setText("Yeah");

            this->close();
            //*user = new Listener(username);
            //Listener* baby = new Listener(username);
            MainScreen* newU = new MainScreen(user, username, this);
            newU->show();
        }
        else if (!confirmation)
        {
            ui->confirm_label->setText("Invalid Confirmation!");
        }
        else
        {
            ui->validPass->setText("Wrong Password");
            //ui->statusPass->setText("Nah");
        }
    }
    else
    {
        ui->validUser->setText("Invalid Username");
        //ui->statusPass->setText("Bruh");
    }
}

void Login::on_Sign_Up_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    //connect(newU, &sign_up, this, &MainWindow);
}

void Login::on_username_editingFinished()
{
    username = ui->username->text();

    if (!checkUsername(username.toStdString()))
    {
        ui->validUser->setText("Username does not exist");
    }
    else
    {
        ui->validUser->setText("");
    }
}


void Login::on_confirmation_stateChanged(int arg1)
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

void Login::moveBack_Login()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Login::on_goBack_clicked()
{
    emit initialWindowClicked();
}

void Login::receiveUser(User** user)
{
    this->user = user;
}

void Login::newPassword(QString name, QString pass)
{
    if(!forgotPassword(name.toStdString(), pass.toStdString()))
    {
        QMessageBox::information(this, "Forgot Password", "Password could not be changed");
    }
    else
    {
        QMessageBox::information(this, "Forgot Password", "Password updated");
    }
}


void Login::on_forgotPassword_clicked()
{
    ForgotPassword* newPass = new ForgotPassword(this);
    newPass->show();

    connect(newPass, &ForgotPassword::newPassword, this, &Login::newPassword);
}


