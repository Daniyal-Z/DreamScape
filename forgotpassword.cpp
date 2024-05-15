#include "forgotpassword.h"
#include "ui_forgotpassword.h"
#include <QMessageBox>

#include "UserPass.h"

ForgotPassword::ForgotPassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ForgotPassword)
{
    ui->setupUi(this);

    connect(this, &ForgotPassword::finished, [this](){
        emit newPassword(ui->username->text(), ui->password->text());
    });
}

ForgotPassword::~ForgotPassword()
{
    delete ui;
}

void ForgotPassword::on_newPass_clicked()
{
    if (ui->username->text() != "" && ui->password->text() != "")
    {
        if (!checkUsername((ui->username->text()).toStdString()))
        {
            QMessageBox::information(this, "Username", "Username does not exist");
        }
        else
        {
            close();
        }
    }
}

