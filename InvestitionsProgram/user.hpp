#ifndef USER_HPP
#define USER_HPP

#include <QString>

class User
{
public:
    User();
    void setID(int&);
    int &getID();
    void setRole(int&);
    int &getRole();
    void setLogin(QString&);
    QString &getLogin();
    void setPassword(QString&);
    QString &getPassword();

    void setName(QString&);
    QString &getName();
    void setAdress(QString&);
    QString &getAdress();
    void setPhone(QString&);
    QString &getPhone();
    void setCost(size_t&);
    void addCost(size_t&);
    void removeCost(size_t&);
    size_t &getCost();
    void setAvailable(bool&);
    bool &getAvailable();

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);

private:
    int id;
    int role;
    QString login;
    QString password;

    QString name;
    QString adress;
    QString phone;

    size_t cost;
    bool available;
};

inline QDataStream &operator<<(QDataStream &ost, const User &u)
{
    u.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, User &u)
{
    u.load(ist);
    return ist;
}

#endif // USER_HPP
