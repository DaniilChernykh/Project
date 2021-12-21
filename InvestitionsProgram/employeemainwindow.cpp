#include "employeemainwindow.hpp"
#include "ui_employeemainwindow.h"

EmployeeMainWindow::EmployeeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployeeMainWindow)
{
    ui->setupUi(this);
}

EmployeeMainWindow::~EmployeeMainWindow()
{
    delete ui;
}
