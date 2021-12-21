#include "security.hpp"

Security::Security()
{

}

void Security::setID(int& id_)
{
    id = id_;
}

int &Security::getID()
{
    return id;
}

void Security::setName(QString& name_)
{
    name = name_;
}

QString &Security::getName()
{
    return name;
}

void Security::setCostOld(size_t& cost_old_)
{
    cost_old = cost_old_;
}

size_t &Security::getCostOld()
{
    return cost_old;
}


void Security::setCostNew(size_t& cost_new_)
{
    cost_new = cost_new_;
}

size_t &Security::getCostNew()
{
    return cost_new;
}

void Security::setAvailable(bool& available_)
{
    available = available_;
}

bool &Security::getAvailable()
{
    return available;
}

void Security::save(QDataStream &ost) const
{
    ost << QString("%1").arg(id) << name << QString("%1").arg(cost_old)
        << QString("%1").arg(cost_new) << QString("%1").arg(available);
}

void Security::load(QDataStream &ist)
{
    QString id_;
    QString cost_old_;
    QString cost_new_;
    QString available_;
    ist >> id_ >> name >> cost_old_ >> cost_new_ >> available_;
    id = id_.toInt();
    cost_old = cost_old_.toULongLong();
    cost_new = cost_new_.toULongLong();
    available = available_.toInt();
}
