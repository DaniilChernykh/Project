#include <QMessageBox>
#include "list_users.hpp"
#include "edit_user.hpp"
#include "ui_list_users.h"

List_Users::List_Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::List_Users)
{
    ui->setupUi(this);
}

void List_Users::build_combobox()
{
    size_t size = ui->comboBox->count();
    for (size_t i = 0; i < users->size(); i++) {
        ui->comboBox->addItem(QString(users->at(i).getName()));
    }
    for (size_t i = 0; i < size; i++) {
        ui->comboBox->removeItem(0);
    }
}

void List_Users::setUsers(std::vector<User> * users_)
{
    users = users_;
    build_combobox();
}

void List_Users::editUser()
{
    Edit_User eu;
    User user = users->at(ui->comboBox->currentIndex());
    eu.setUser(&user);
    eu.setCurrentValues();
    eu.exec();
    users->at(ui->comboBox->currentIndex()) = user;
    build_combobox();
}

void List_Users::changeUser(int index_)
{
    ui->checkBox->setChecked(users->at(index_).getAvailable());
    ui->comboBox_2->setCurrentIndex(users->at(index_).getRole());
}

void List_Users::accept()
{
    User user = users->at(ui->comboBox->currentIndex());
    user.setRole(ui->comboBox_2->currentIndex());
    user.setAvailable(ui->checkBox->isChecked());
    return QDialog::accept();
}

List_Users::~List_Users()
{
    delete ui;
}
