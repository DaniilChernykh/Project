#include "adminmainwindow.hpp"
#include "list_users.hpp"
#include "ui_adminmainwindow.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
}

void AdminMainWindow::setDB(Database& db_)
{
    db = db_;
}

void AdminMainWindow::manageUsers()
{
    List_Users lu;
    lu.setUsers(db.getUsers());
    lu.exec();
    db.save_users();
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}
