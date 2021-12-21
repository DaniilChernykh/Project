#include "user.hpp"

User::User()
{
    role = 0;
    available = true;
}

void User::setID(int& id_)
{
    id = id_;
}

int &User::getID()
{
    return id;
}

void User::setRole(int& role_)
{
    role = role_;
}

int &User::getRole()
{
    return role;
}

void User::setLogin(QString& login_)
{
    login = login_;
}

QString &User::getLogin()
{
    return login;
}

void User::setPassword(QString& password_)
{
    password = password_;
}

QString &User::getPassword()
{
    return password;
}

void User::setName(QString& name_)
{
    name = name_;
}

QString &User::getName()
{
    return name;
}

void User::setAdress(QString& adress_)
{
    adress = adress_;
}

QString &User::getAdress()
{
    return adress;
}

void User::setPhone(QString& phone_)
{
    phone = phone_;
}

QString &User::getPhone()
{
    return phone;
}

void User::setCost(size_t& cost_)
{
    cost = cost_;
}

void User::addCost(size_t& cost_)
{
    cost += cost_;
}

void User::removeCost(size_t& cost_)
{
    cost -= cost_;
}

size_t &User::getCost()
{
    return cost;
}

void User::setAvailable(bool& available_)
{
    available = available_;
}

bool &User::getAvailable()
{
    return available;
}

void User::save(QDataStream &ost) const
{
    ost << QString("%1").arg(id) << QString("%1").arg(role) << login << password <<
           name << adress << phone << QString("%1").arg(cost) << QString("%1").arg(available);
}

void User::load(QDataStream &ist)
{
    QString id_;
    QString role_;
    QString cost_;
    QString available_;
    ist >> id_ >> role_ >> login >> password >> name >> adress >> phone >> cost_ >> available_;
    id = id_.toInt();
    role = role_.toInt();
    cost = cost_.toULongLong();
    available = available_.toInt();
}
