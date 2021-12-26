#ifndef SELL_INVESTITION_HPP
#define SELL_INVESTITION_HPP

#include <QDialog>
#include "database.hpp"

namespace Ui {
class Sell_Investition;
}

class Sell_Investition : public QDialog
{
    Q_OBJECT

public:
    explicit Sell_Investition(QWidget *parent = nullptr);
    void setDB(Database*);
    ~Sell_Investition();

public slots:
    void changeUser(int);
    void accept();

private:
    Ui::Sell_Investition *ui;
    Database* db;
    std::vector<User> users;

    void buildInvestition();
};

#endif // SELL_INVESTITION_HPP
