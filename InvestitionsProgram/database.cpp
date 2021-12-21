#include "database.hpp"

Database::Database()
{

}

void Database::load()
{
    load_users();
    load_security();
    load_investment();
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
    QString name_ = "Danila";
    //QString adress_ = "";
    //QString phone_ = "";
    emloyee.setID(id_);
    emloyee.setRole(role_);
    emloyee.setLogin(login_);
    emloyee.setPassword(password_);
    emloyee.setName(name_);
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

void Database::load_investment()
{
    int cli_id = 2;
    int sec_id = 101;
    size_t count = 1;
    QString name_bought = "Danila";
    QDate date_buy = QDate::currentDate();
    QDate date_sell;

    Investment inv1;
    inv1.setUserID(cli_id);
    inv1.setSecurityID(sec_id);
    inv1.setCount(count);
    inv1.setNameBought(name_bought);
    inv1.setDateBuy(date_buy);
    inv1.setDateSell(date_sell);
    investments.push_back(inv1);

    sec_id = 102;
    count = 2;
    Investment inv2;
    inv2.setUserID(cli_id);
    inv2.setSecurityID(sec_id);
    inv2.setCount(count);
    inv2.setNameBought(name_bought);
    inv2.setDateBuy(date_buy);
    inv2.setDateSell(date_sell);
    investments.push_back(inv2);

    sec_id = 103;
    count = 1;
    date_sell = QDate::currentDate().addDays(1);
    Investment inv3;
    inv3.setUserID(cli_id);
    inv3.setSecurityID(sec_id);
    inv3.setCount(count);
    inv3.setNameBought(name_bought);
    inv3.setDateBuy(date_buy);
    inv3.setDateSell(date_sell);
    investments.push_back(inv3);
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

std::vector <Investment> Database::getInvestmentUser(User user_)
{
    std::vector <Investment> m_inv;
    for (size_t i = 0; i < investments.size(); i++)
    {
        if (investments[i].getUserID() == user_.getID())
        {
            m_inv.push_back(investments[i]);
        }
    }
    return m_inv;
}

QString Database::getNameSecurityID(int ID)
{
    QString res = "Не найдено!";
    for (size_t i = 0; i < securites.size(); i++)
    {
        if (securites[i].getID() == ID)
            return securites[i].getName();
    }
    return res;
}

User *Database::getCurUser()
{
    return &cur_user;
}