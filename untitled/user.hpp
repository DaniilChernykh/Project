#ifndef USER_HPP
#define USER_HPP

#include <QString>

class User
{
public:
    User();
    void setID(int&);
    int &getID();
    void setRole(int&) ;
    int &getRole();
    void setName(QString&);
    QString &getName();
    void setAdress(QString&);
    QString &getAdress();
    void setPhone(QString&);
    QString &getPhone();

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);

private:
    int id;
    int role;
    QString name;
    QString adress;
    QString phone;
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
