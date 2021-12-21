#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "user.hpp"
#include "security.hpp"
#include "investment.hpp"

class Database
{
public:
    Database();
    std::vector <User> *getUsers();
    bool searchUser(QString& login_, QString& password_);
    User *getCurUser();

    std::vector <Security> &getSecurites();
    std::vector <Investment> getInvestmentUser(User);
    QString getNameSecurityID(int);

private:
    void load();
    void load_users();
    void load_security();
    void load_investment();

    std::vector <User> users;
    std::vector <Security> securites;
    std::vector <Investment> investments;
    User cur_user;
};

#endif // DATABASE_HPP
