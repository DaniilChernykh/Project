#include "adminmainwindow.hpp"
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

}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}
