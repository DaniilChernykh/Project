#include <QDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include "edit_securities.hpp"
#include "employeemainwindow.hpp"
#include "ui_employeemainwindow.h"
#include "ui_buy_investition.h"

EmployeeMainWindow::EmployeeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployeeMainWindow)
{
    ui->setupUi(this);
}

void EmployeeMainWindow::setDB(Database& db_)
{
    db = db_;
    user = db.getCurUser();
    securites = db.getSecurites();
    clients = db.getClients();
    investments = db.getInvestmentEmployee(*user);

    doTablesView();
}

void EmployeeMainWindow::doTablesView()
{
    doSecuritesView();
    doClientsView();
    doHistoryView();
}

void EmployeeMainWindow::doSecuritesView()
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

    for (size_t i = 0; i < securites.size(); i++) {
        if (securites[i].getAvailable())
        {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(securites[i].getName()));
            standardItemsList.append(new QStandardItem(QString("%1").arg(securites[i].getCostOld())));
            standardItemsList.append(new QStandardItem(QString("%1").arg(securites[i].getCostNew())));
            if (securites[i].getCostOld() <= securites[i].getCostNew())
                standardItemsList.append(new QStandardItem("Рост"));
            else
                standardItemsList.append(new QStandardItem("Падение"));
            tab1->insertRow(tab1->rowCount(), standardItemsList);
        }
    }
}

void EmployeeMainWindow::doClientsView()
{
    tab2 = new QStandardItemModel(this);
    tab2->setColumnCount(4);
    tab2->setHorizontalHeaderLabels(QStringList() << "Название" << "Адрес"
                                    << "Телефон" << "Количество денег");
    ui->clientsView->setModel(tab2);
    ui->clientsView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->clientsView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->clientsView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->clientsView->horizontalHeader()->setStretchLastSection(true);

    for (size_t i = 0; i < clients.size(); i++) {
        if (clients[i].getAvailable())
        {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(clients[i].getName()));
            standardItemsList.append(new QStandardItem(clients[i].getAdress()));
            standardItemsList.append(new QStandardItem(clients[i].getPhone()));
            standardItemsList.append(new QStandardItem(QString("%1").arg(clients[i].getCost())));
            tab2->insertRow(tab2->rowCount(), standardItemsList);
        }
    }
}

void EmployeeMainWindow::doHistoryView()
{
    tab3 = new QStandardItemModel(this);
    tab3->setColumnCount(6);
    tab3->setHorizontalHeaderLabels(QStringList() << "Название компании" << "Имя клиента" << "Количество"
                                    << "Дата покупки" << "Дата продажи" << "Состояние");
    ui->historyView->setModel(tab3);
    ui->historyView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->historyView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->historyView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->historyView->horizontalHeader()->setStretchLastSection(true);

    for (size_t i = 0; i < investments.size(); i++) {
        QList<QStandardItem *> standardItemsList;
        standardItemsList.append(new QStandardItem(db.getNameSecurityID(investments[i].getSecurityID())));
        standardItemsList.append(new QStandardItem(db.getNameClientID(investments[i].getUserID())));
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

void EmployeeMainWindow::addSecurities()
{
    Security s;
    Edit_Securities es;
    es.setSecurity(&s);
    if (es.exec() != Edit_Securities::Accepted)
        return;
    s.setCostOld(0);
    s.setID(101 + db.getSizeSecurities());
    db.addSecurity(s);
    securites.push_back(s);
    doTablesView();
}

void EmployeeMainWindow::editSecurities()
{
    if (!ui->securitesView->selectionModel()->hasSelection()) {
        return;
    }

    QModelIndexList selection = ui->securitesView->selectionModel()->selectedRows();
    int index_security = selection.at(0).row();

    Security s = securites[index_security];
    Edit_Securities es;
    es.setSecurity(&s);
    es.setCurrentValues();
    if (es.exec() != Edit_Securities::Accepted)
        return;
    db.refreshDataSecurity(s);
    securites = db.getSecurites();
    doTablesView();
}

void EmployeeMainWindow::buyInvestion()
{
    if (!ui->securitesView->selectionModel()->hasSelection()) {
        return;
    }

    QDialog *buyForm = new QDialog;
    Ui::buy_inv buy_investition;
    buy_investition.setupUi(buyForm);

    for (size_t i = 0; i < clients.size(); i++) {
        buy_investition.comboBox->addItem(clients[i].getName());
    }

    if (buyForm->exec() != QDialog::Accepted)
        return;
    int index_client = buy_investition.comboBox->currentIndex();

    QModelIndexList selection = ui->securitesView->selectionModel()->selectedRows();
    int index_security = selection.at(0).row();

    bool ok = false;
    size_t count_securite = buy_investition.lineEdit->text().toULongLong(&ok);
    if (!ok) { return; }

    if (clients[index_client].getCost() < securites[index_security].getCostNew() * count_securite) {
        QMessageBox::warning(0, "InvestitionsProgram", "У пользователя недостаточно средств.");
        return;
    }
    size_t rem_cost = securites[index_security].getCostNew() * count_securite;
    clients[index_client].removeCost(rem_cost);

    Investment inv;
    inv.setSecurityID(securites[index_security].getID());
    inv.setCount(count_securite);
    inv.setNameBought(user->getName());
    inv.setDateBuy(QDate::currentDate());
    inv.setUserID(clients[index_client].getID());
    investments.push_back(inv);
    db.addInvestment(inv);
    db.save_users();
    doTablesView();
}

EmployeeMainWindow::~EmployeeMainWindow()
{
    delete ui;
}


void EmployeeMainWindow::on_securitesView_clicked(const QModelIndex&)
{
    ui->buyButton->setEnabled(true);
    ui->editButton->setEnabled(true);
}

void EmployeeMainWindow::on_tabWidget_currentChanged(int)
{
    if (ui->tabWidget->currentIndex() != 0)
    {
        ui->editButton->setEnabled(false);
        ui->buyButton->setEnabled(false);
        ui->addButton->setEnabled(false);
    }
    if (ui->tabWidget->currentIndex() == 0 && ui->securitesView->selectionModel()->hasSelection())
    {
        ui->editButton->setEnabled(true);
        ui->buyButton->setEnabled(true);
    }
    else if (ui->tabWidget->currentIndex() == 0)
    {
        ui->addButton->setEnabled(true);
    }
}

