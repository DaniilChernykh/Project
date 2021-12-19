#include "clientmainwindow.hpp"
#include "ui_clientmainwindow.h"

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

    doTablesView();
}

void ClientMainWindow::doTablesView()
{
    doSecuritesView();
    //doMySecuritesView();
    //doHistoryView();
}

void ClientMainWindow::doSecuritesView()
{
    tab1 = new QStandardItemModel(this);
    tab1->setColumnCount(5);
    tab1->setHorizontalHeaderLabels(QStringList() << "ID" << "Название" << "Старая цена"
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
            standardItemsList.append(new QStandardItem(QString("%1").arg(secs[i].getID())));
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

ClientMainWindow::~ClientMainWindow()
{
    delete ui;
}
