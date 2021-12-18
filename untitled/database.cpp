#include "database.hpp"

Database::Database()
{

}

void Database::load()
{
    load_users();
}

void Database::load_users()
{
    User admin;
    int id_ = 0;
    int role_ = 2;
    QString login_ = "Admin";
    QString password_ = "123";
    QString name_ = "Company";
    QString adress_ = "";
    QString phone_ = "";
    admin.setID(id_);
    admin.setRole(role_);
    admin.setLogin(login_);
    admin.setPassword(password_);
    admin.setName(name_);
    admin.setAdress(adress_);
    admin.setPhone(phone_);

    users.push_back(admin);
}

std::vector <User> *Database::getUsers()
{
    if (users.empty())
    {
        load();
    }
    return &users;
}

bool Database::searchUser(QString& login_, QString& password_)
{
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login_ && users[i].getPassword() == password_)
            return true;
    }
    return false;
}
