#ifndef INVESTMENT_HPP
#define INVESTMENT_HPP

#include <QDate>

class Investment
{
public:
    Investment();
    void setUserID(int&);
    int &getUserID();
    void setSecurityID(int&);
    int &getSecurityID();
    void setCount(size_t&);
    size_t &getCount();
    void setDateBuy(QDate&);
    QDate getDateBuy();
    void setDateSell(QDate&);
    QDate getDateSell();

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);

private:
    int user_id;
    int security_id;
    size_t count;
    QDate date_buy;
    QDate date_sell;
};

inline QDataStream &operator<<(QDataStream &ost, const Investment &i)
{
    i.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, Investment &i)
{
    i.load(ist);
    return ist;
}

#endif // INVESTMENT_HPP
