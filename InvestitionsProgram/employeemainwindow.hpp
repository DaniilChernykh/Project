#ifndef EMPLOYEEMAINWINDOW_HPP
#define EMPLOYEEMAINWINDOW_HPP

#include <QMainWindow>
#include <QStandardItemModel>
#include "database.hpp"

namespace Ui {
class EmployeeMainWindow;
}

class EmployeeMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeMainWindow(QWidget *parent = nullptr);
    void setDB(Database&);
    ~EmployeeMainWindow();

public slots:
    void buyInvestion();

private:
    void doTablesView();
    void doSecuritesView();
    void doClientsView();
    void doHistoryView();

    Ui::EmployeeMainWindow *ui;

    Database db;
    User *user;

    std::vector<Security> securites;
    std::vector<User> clients;
    std::vector<Investment> investments;

    QStandardItemModel *tab1;
    QStandardItemModel *tab2;
    QStandardItemModel *tab3;



};

#endif // EMPLOYEEMAINWINDOW_HPP
