#include "adminmainwindow.hpp"
#include "list_users.hpp"
#include "ui_adminmainwindow.h"
#include "ui_list_investition.h"

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

void AdminMainWindow::historyChangedSecurities()
{
    QDialog *li = new QDialog;
    Ui::List_Investition list_invest;
    list_invest.setupUi(li);

    //list_invest.listWidget->addItems();


}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}
