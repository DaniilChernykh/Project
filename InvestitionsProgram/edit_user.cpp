#include <QMessageBox>
#include "edit_user.hpp"
#include "ui_edit_user.h"

Edit_User::Edit_User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_User)
{
    ui->setupUi(this);
}

void Edit_User::setUser(User* user_)
{
    user = user_;
}

void Edit_User::setCurrentValues()
{
    ui->loginEdit->setText(user->getLogin());
    ui->nameEdit->setText(user->getName());
    ui->adressEdit->setText(user->getAdress());
    ui->phoneEdit->setText(user->getPhone());
}

void Edit_User::accept()
{
    QString login = ui->loginEdit->text();
    QString password = ui->passEdit->text();
    QString password2 = ui->try_passEdit->text();
    QString name = ui->nameEdit->text();
    QString adress = ui->adressEdit->text();
    QString phone = ui->phoneEdit->text();

    if (login.isEmpty() || password.isEmpty() || password2.isEmpty() ||
            name.isEmpty() || adress.isEmpty() || phone.isEmpty())
    {
        QMessageBox::warning(this, "InvestitionProgram", "Заполните все поля!");
        return;
    }

    if (password != password2)
    {
        QMessageBox::warning(this, "InvestitionProgram", "Пароли не совпадают!");
        return;
    }

    user->setLogin(login);
    user->setPassword(password);
    user->setName(name);
    user->setAdress(adress);
    user->setPhone(phone);
    return QDialog::accept();
}

Edit_User::~Edit_User()
{
    delete ui;
}
