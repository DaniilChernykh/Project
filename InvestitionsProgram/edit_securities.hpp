#ifndef EDIT_SECURITIES_HPP
#define EDIT_SECURITIES_HPP

#include <QDialog>
#include "security.hpp"

namespace Ui {
class Edit_Securities;
}

class Edit_Securities : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Securities(QWidget *parent = nullptr);
    void setSecurity(Security*);
    void setCurrentValues();
    ~Edit_Securities();

    void setLineName(QString);
    void setLineOCostEdit(QString);
    void setLineNCostEdit(QString);
    void setLineAvailableBox(bool);

public slots:
    void accept();

private:
    Ui::Edit_Securities *ui;
    Security* security;
};

#endif // EDIT_SECURITIES_HPP
