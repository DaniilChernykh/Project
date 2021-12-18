#include "user.hpp"

User::User()
{

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

void User::save(QDataStream &ost) const
{
    ost << QString("%1").arg(id) << QString("%1").arg(role) << name << adress << phone;
}

void User::load(QDataStream &ist)
{
    QString id_;
    QString role_;
    ist >> id_ >> role_ >> name >> adress >> phone;
    id = id_.toInt();
    role = role_.toInt();
}
