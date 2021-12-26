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

void Edit_Securities::setCurrentValues()
{
    ui->nameEdit->setText(security->getName());
    ui->oCostEdit->setText(QString("%1").arg(security->getCostOld()));
    ui->nCostEdit->setText(QString("%1").arg(security->getCostNew()));
    ui->availableBox->setChecked(security->getAvailable());
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
