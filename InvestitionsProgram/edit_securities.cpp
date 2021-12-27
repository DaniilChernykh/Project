#include <QMessageBox>
#include "edit_securities.hpp"
#include "ui_edit_securities.h"

Edit_Securities::Edit_Securities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Securities)
{
    ui->setupUi(this);
}

void Edit_Securities::setSecurity(Security* security_)
{
    security = security_;
}

void Edit_Securities::setLineName(QString name_)
{
    ui->nameEdit->setText(name_);
}

void Edit_Securities::setLineOCostEdit(QString oCost_)
{
    ui->oCostEdit->setText(QString("%1").arg(oCost_));
}

void Edit_Securities::setLineNCostEdit(QString nCost_)
{
    ui->nCostEdit->setText(QString("%1").arg(nCost_));
}

void Edit_Securities::setLineAvailableBox(bool avail_)
{
    ui->availableBox->setChecked(avail_);
}

void Edit_Securities::setCurrentValues()
{
    setLineName(security->getName());
    setLineOCostEdit(QString("%1").arg(security->getCostOld()));
    setLineNCostEdit(QString("%1").arg(security->getCostNew()));
    setLineAvailableBox(security->getAvailable());
}

void Edit_Securities::accept()
{
    QString name = ui->nameEdit->text();
    QString new_cost = ui->nCostEdit->text();
    bool available = ui->availableBox->isChecked();

    if (name.isEmpty() || new_cost.isEmpty())
    {
        QMessageBox::warning(this, "InvestitionsProgram", "Заполните все поля");
        return;
    }

    bool ok = false;
    size_t n_cost = new_cost.toULongLong(&ok);
    if (!ok)
    {
        QMessageBox::warning(this, "InvestitionsProgram", "Поле с новой ценой введена неправильно.");
        return;
    }
    else if (n_cost <= 0) {
        QMessageBox::warning(this, "InvestitionsProgram", "Новая цена отрицательная.");
        return;
    }

    security->setName(name);
    security->setCostOld(security->getCostNew());
    security->setCostNew(n_cost);
    security->setAvailable(available);

    return QDialog::accept();
}

Edit_Securities::~Edit_Securities()
{
    delete ui;
}
