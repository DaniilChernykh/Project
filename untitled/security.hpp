#ifndef SECURITY_HPP
#define SECURITY_HPP

#include <QString>

class Security
{
public:
    Security();
    void setID(int&);
    int &getID();
    void setName(QString&);
    QString &getName();
    void setCostOld(size_t&);
    size_t &getCostOld();
    void setCostNew(size_t&);
    size_t &getCostNew();
    void setAvailable(bool&);
    bool &getAvailable();

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);

private:
    int id;
    QString name;
    size_t cost_old;
    size_t cost_new;

    bool available;
};

inline QDataStream &operator<<(QDataStream &ost, const Security &s)
{
    s.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, Security &s)
{
    s.load(ist);
    return ist;
}

#endif // SECURITY_HPP
