#include <QMessageBox>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    users = db.getUsers();
}

void MainWindow::authButton()
{
    QString login = ui->loginEdit->text();
    QString password = ui->passEdit->text();

    if (login.isEmpty())
    {
        QMessageBox::warning(0, "BuyInvestments", "Поле логин пустое.");
        return;
    }
    else if (password.isEmpty())
    {
        QMessageBox::warning(0, "BuyInvestments", "Поле пароль пустое.");
        return;
    }

    if (db.searchUser(login, password))
    {
        QMessageBox::warning(0, "BuyInvestments", "Поздравляю с авторизацией!");
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

