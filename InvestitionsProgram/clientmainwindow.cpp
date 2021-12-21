#include <QDialog>
#include <QDialogButtonBox>
#include "clientmainwindow.hpp"
#include "ui_clientmainwindow.h"
#include "ui_add_cost.h"

ClientMainWindow::ClientMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientMainWindow)
{
    ui->setupUi(this);
}

void ClientMainWindow::setDB(Database& db_)
{
    db = db_;
    user = db.getCurUser();
    ui->costEdit->setText(QString("%1").arg(user->getCost()));

    investments = db.getInvestmentUser(*user);

    doTablesView();
}

void ClientMainWindow::doTablesView()
{
    doSecuritesView();
    doMySecuritesView();
    doHistoryView();
}

void ClientMainWindow::doSecuritesView()
{
    tab1 = new QStandardItemModel(this);
    tab1->setColumnCount(4);
    tab1->setHorizontalHeaderLabels(QStringList() << "Название" << "Старая цена"
                                    << "Текущая цена" << "Тенденция");
    ui->securitesView->setModel(tab1);
    ui->securitesView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->securitesView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->securitesView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->securitesView->horizontalHeader()->setStretchLastSection(true);

    std::vector <Security> secs = db.getSecurites();
    for (size_t i = 0; i < secs.size(); i++) {
        if (secs[i].getAvailable())
        {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(secs[i].getName()));
            standardItemsList.append(new QStandardItem(QString("%1").arg(secs[i].getCostOld())));
            standardItemsList.append(new QStandardItem(QString("%1").arg(secs[i].getCostNew())));
            if (secs[i].getCostOld() <= secs[i].getCostNew())
                standardItemsList.append(new QStandardItem("Рост"));
            else
                standardItemsList.append(new QStandardItem("Падение"));
            tab1->insertRow(tab1->rowCount(), standardItemsList);
        }
    }
}

void ClientMainWindow::doMySecuritesView()
{
    tab2 = new QStandardItemModel(this);
    tab2->setColumnCount(3);
    tab2->setHorizontalHeaderLabels(QStringList() << "Название компании" << "Имя купившего" << "Количество");
    ui->mySecuritesView->setModel(tab2);
    ui->mySecuritesView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->mySecuritesView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->mySecuritesView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->mySecuritesView->horizontalHeader()->setStretchLastSection(true);

    for (size_t i = 0; i < investments.size(); i++) {
        if (investments[i].getDateSell().isNull())
        {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(db.getNameSecurityID(investments[i].getSecurityID())));
            standardItemsList.append(new QStandardItem(investments[i].getNameBought()));
            standardItemsList.append(new QStandardItem(QString("%1").arg(investments[i].getCount())));
            tab2->insertRow(tab2->rowCount(), standardItemsList);
        }
    }
}

void ClientMainWindow::doHistoryView()
{
    tab3 = new QStandardItemModel(this);
    tab3->setColumnCount(6);
    tab3->setHorizontalHeaderLabels(QStringList() << "Название компании" << "Имя купившего" << "Количество"
                                    << "Дата покупки" << "Дата продажи" << "Состояние");
    ui->historyView->setModel(tab3);
    ui->historyView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->historyView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->historyView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->historyView->horizontalHeader()->setStretchLastSection(true);

    for (size_t i = 0; i < investments.size(); i++) {
        QList<QStandardItem *> standardItemsList;
        standardItemsList.append(new QStandardItem(db.getNameSecurityID(investments[i].getSecurityID())));
        standardItemsList.append(new QStandardItem(investments[i].getNameBought()));
        standardItemsList.append(new QStandardItem(QString("%1").arg(investments[i].getCount())));
        standardItemsList.append(new QStandardItem(investments[i].getDateBuy().toString()));
        if (investments[i].getDateSell().isNull())
        {
            standardItemsList.append(new QStandardItem("Еще не продано"));
            standardItemsList.append(new QStandardItem("Куплено"));
        }
        else
        {
            standardItemsList.append(new QStandardItem(investments[i].getDateSell().toString()));
            standardItemsList.append(new QStandardItem("Продано"));
        }
        tab3->insertRow(tab3->rowCount(), standardItemsList);
    }
}

void ClientMainWindow::addCost()
{
    QDialog *costForm = new QDialog;
    Ui::Add_Cost add_cost;
    add_cost.setupUi(costForm);

    if (costForm->exec() != QDialog::Accepted)
        return;

    bool ok = false;
    size_t addCost = add_cost.label->text().toULongLong(&ok);
    if (ok)
    {
        user->addCost(addCost);
    }
    ui->costEdit->setText(QString("%1").arg(user->getCost()));
}

ClientMainWindow::~ClientMainWindow()
{
    delete ui;
}
