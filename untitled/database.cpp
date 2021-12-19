#include "database.hpp"

Database::Database()
{

}

void Database::load()
{
    load_users();
    load_security();
}

void Database::load_users()
{
    User admin;
    int id_ = 0;
    int role_ = 2;
    QString login_ = "adm";
    QString password_ = "123";
    //QString name_ = "Company";
    //QString adress_ = "";
    //QString phone_ = "";
    admin.setID(id_);
    admin.setRole(role_);
    admin.setLogin(login_);
    admin.setPassword(password_);
    //admin.setName(name_);
    //admin.setAdress(adress_);
    //admin.setPhone(phone_);
    users.push_back(admin);

    User emloyee;
    id_ = 1;
    role_ = 1;
    login_ = "emp";
    password_ = "123";
    //QString name_ = "Company";
    //QString adress_ = "";
    //QString phone_ = "";
    emloyee.setID(id_);
    emloyee.setRole(role_);
    emloyee.setLogin(login_);
    emloyee.setPassword(password_);
    //admin.setName(name_);
    //admin.setAdress(adress_);
    //admin.setPhone(phone_);
    users.push_back(emloyee);

    User client;
    id_ = 2;
    role_ = 0;
    login_ = "cli";
    password_ = "123";
    //QString name_ = "Company";
    //QString adress_ = "";
    //QString phone_ = "";
    client.setID(id_);
    client.setRole(role_);
    client.setLogin(login_);
    client.setPassword(password_);
    //admin.setName(name_);
    //admin.setAdress(adress_);
    //admin.setPhone(phone_);
    users.push_back(client);
}

void Database::load_security()
{
    Security sec1;
    int id_ = 101;
    QString name_ = "Газпром";
    size_t cost_old_ = 1000;
    size_t cost_new_ = 7000;
    bool available = true;
    sec1.setID(id_);
    sec1.setName(name_);
    sec1.setCostOld(cost_old_);
    sec1.setCostNew(cost_new_);
    sec1.setAvailable(available);
    securites.push_back(sec1);

    Security sec2;
    id_ = 102;
    name_ = "Магнит";
    cost_old_ = 8000;
    cost_new_ = 6500;
    sec2.setID(id_);
    sec2.setName(name_);
    sec2.setCostOld(cost_old_);
    sec2.setCostNew(cost_new_);
    sec2.setAvailable(available);
    securites.push_back(sec2);

    Security sec3;
    id_ = 103;
    name_ = "Яндекс";
    cost_old_ = 9000;
    cost_new_ = 17000;
    sec3.setID(id_);
    sec3.setName(name_);
    sec3.setCostOld(cost_old_);
    sec3.setCostNew(cost_new_);
    sec3.setAvailable(available);
    securites.push_back(sec3);
}

std::vector <Security> &Database::getSecurites()
{
    return securites;
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
        if (users[i].getLogin() == login_ && users[i].getPassword() == password_) {
            cur_user = users[i];
            return true;
        }
    }
    return false;
}

User *Database::getCurUser()
{
    return &cur_user;
}
