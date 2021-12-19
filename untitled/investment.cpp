#include "investment.hpp"

Investment::Investment()
{

}

void Investment::setUserID(int& user_id_)
{
    user_id = user_id_;
}

int &Investment::getUserID()
{
    return user_id;
}

void Investment::setSecurityID(int& security_id_)
{
    security_id = security_id_;
}

int &Investment::getSecurityID()
{
    return security_id;
}

void Investment::setCount(size_t& count_)
{
    count = count_;
}

size_t &Investment::getCount()
{
    return count;
}

void Investment::setDateBuy(QDate& date_buy_)
{
    date_buy = date_buy_;
}

QDate Investment::getDateBuy()
{
    return date_buy;
}

void Investment::setDateSell(QDate& date_sell_)
{
    date_sell = date_sell_;
}

QDate Investment::getDateSell()
{
    return date_sell;
}

void Investment::save(QDataStream &ost) const
{
    ost << QString("%1").arg(user_id) << QString("%1").arg(security_id)
        << count << date_buy << date_sell;
}

void Investment::load(QDataStream &ist)
{
    QString user_id_;
    QString security_id_;
    ist >> user_id_ >> security_id_ >> count >> date_buy >> date_sell;
    user_id = user_id_.toInt();
    security_id = security_id_.toInt();
}

