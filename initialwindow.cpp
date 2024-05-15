#include "initialwindow.h"
#include "ui_initialwindow.h"

InitialWindow::InitialWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InitialWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    ui->stackWidget->insertWidget(1, &login);
    ui->stackWidget->insertWidget(2, &aLogin);

    connect(&login, SIGNAL(initialWindowClicked()), this, SLOT(moveBack()));
    connect(&aLogin, SIGNAL(initialWindowClicked()), this, SLOT(moveBack()));

    user = new User*[1];

    connect(this, SIGNAL(listenerClicked(User**)), &login, SLOT(receiveUser(User**)));
    connect(this, SIGNAL(artistClicked(User**)), &aLogin, SLOT(receiveUser(User**)));
}

InitialWindow::~InitialWindow()
{
    delete ui;
}

void InitialWindow::on_Listener_clicked()
{
    emit listenerClicked(user);

    ui->stackWidget->setCurrentIndex(1);
}

void InitialWindow::moveBack()
{
    ui->stackWidget->setCurrentIndex(0);
}

void InitialWindow::on_Artist_clicked()
{
    emit artistClicked(user);

    ui->stackWidget->setCurrentIndex(2);
}

