#include <QMessageBox>
#include "sell_investition.hpp"
#include "ui_sell_investition.h"

Sell_Investition::Sell_Investition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sell_Investition)
{
    ui->setupUi(this);
}



void Sell_Investition::setDB(Database* db_)
{
    db = db_;
    users = db->getClients();

    for (size_t i = 0; i < users.size(); i++) {
        ui->comboBox->addItem(users[i].getName());
    }
}

void Sell_Investition::changeUser(int)
{
    buildInvestition();
}

void Sell_Investition::buildInvestition()
{
    size_t size = ui->comboBox_2->count();
    auto investments = db->getInvestmentUser(users[ui->comboBox->currentIndex()]);
    for (size_t i = 0; i < investments.size(); i++) {
        ui->comboBox_2->addItem(db->getNameSecurityID(investments[i].getSecurityID()));
    }

    for (size_t i = 0; i < size; i++) {
        ui->comboBox_2->removeItem(0);
    }

    ui->countLabel->setText(QString("%1").arg(ui->comboBox_2->count()));
}

void Sell_Investition::accept()
{
    auto investments = db->getInvestmentUser(users[ui->comboBox->currentIndex()]);
    QString count = ui->lineEdit->text();
    if (ui->comboBox_2->count() == 0)
        return;

    if (count.isEmpty())
    {
        QMessageBox::warning(this,"InvestitionsProgram", "Поле количество пустое");
        return;
    }
    Investment inv = investments[ui->comboBox_2->currentIndex()];
    if (inv.getCount() < count.toULongLong())
    {
        QMessageBox::warning(this,"InvestitionsProgram", "Количество на продажу больше имеющихся.");
        return;
    }
    inv.setCount(inv.getCount() - count.toULongLong());
    if (inv.getCount() == 0)
        inv.setDateSell(QDate::currentDate());

    Security sec = db->getSecurityID(inv.getSecurityID());
    User user = db->getClientID(inv.getUserID());

    user.addCost(sec.getCostNew() * count.toULongLong());

    db->refreshDataInvestments(inv);
    db->refreshDataUser(user);
    return QDialog::accept();
}

Sell_Investition::~Sell_Investition()
{
    delete ui;
}
