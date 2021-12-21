#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "user.hpp"
#include "security.hpp"
#include "investment.hpp"

class Database
{
public:
    Database();
    bool searchUser(QString& login_, QString& password_);
    std::vector <User> *getUsers();
    User *getCurUser();
    std::vector <Security> &getSecurites();
    std::vector <Investment> getInvestmentUser(User);
    std::vector <Investment> getInvestmentEmployee(User);
    std::vector <User> getClients();
    QString getNameSecurityID(int);
    QString getNameClientID(int);
    void addInvestment(Investment&);

    void save_users();
    void save_security();
    void save_investment();

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
