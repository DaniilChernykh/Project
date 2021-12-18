#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "user.hpp"

class Database
{
public:
    Database();
    std::vector <User> *getUsers();
    bool searchUser(QString& login_, QString& password_);

private:
    void load();
    void load_users();

    std::vector <User> users;
};

#endif // DATABASE_HPP
