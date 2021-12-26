#include <QMessageBox>

#include "mainwindow.hpp"
#include "clientmainwindow.hpp"
#include "employeemainwindow.hpp"
#include "edit_user.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    users = db.getUsers();
}

void MainWindow::regButton()
{
    User user;
    Edit_User regUser;
    regUser.setUser(&user);
    if (regUser.exec() != Edit_User::Accepted)
        return;
    user.setAvailable(true);
    user.setRole(0);
    user.setID(1000 + db.getSizeClients());
    user.setCost(0);
    db.addUser(user);
    users->push_back(user);
}

void MainWindow::authButton()
{
    QString login = ui->loginEdit->text();
    QString password = ui->passEdit->text();

    if (login.isEmpty()) {
        QMessageBox::warning(0, "BuyInvestments", "Поле логин пустое.");
        return;
    }
    else if (password.isEmpty()) {
        QMessageBox::warning(0, "BuyInvestments", "Поле пароль пустое.");
        return;
    }

    if (!db.searchUser(login, password)) {
        QMessageBox::warning(0, "BuyInvestments", "Пользователя с введенным логином и паролем не найден.");
        return;
    }
    openMainWindow(db.getCurUser()->getRole());
}

void MainWindow::openMainWindow(int role_)
{
    if (role_ == 0) {
        ClientMainWindow *cmm = new ClientMainWindow;
        cmm->setDB(db);
        cmm->show();
        exit();
    }
    else if (role_ == 1) {
        EmployeeMainWindow *emm = new EmployeeMainWindow;
        emm->setDB(db);
        emm->show();
        exit();
    }
    else if (role_ == 2) {
        QMessageBox::information(0, "BuyInvestments", "Ты - администратор!");
        return;
    }
}

void MainWindow::exit()
{
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

