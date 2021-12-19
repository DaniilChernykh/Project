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

    if (!db.searchUser(login, password))
    {
        QMessageBox::warning(0, "BuyInvestments", "Пользователя с введенным логином и паролем не найден.");
        return;
    }
    openMainWindow(db.getRoleCurUser());
}

void openMainWindow(int role_)
{
    if (role_ == 0) {
        QMessageBox::information(0, "BuyInvestments", "Ты - клиент!");
        return;
    }
    else if (role_ == 1) {
        QMessageBox::information(0, "BuyInvestments", "Ты - сотрудник!");
        return;
    }
    else if (role_ == 2) {
        QMessageBox::information(0, "BuyInvestments", "Ты - администратор!");
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

