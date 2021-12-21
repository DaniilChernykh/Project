#ifndef CLIENTMAINWINDOW_HPP
#define CLIENTMAINWINDOW_HPP

#include <QMainWindow>
#include <QStandardItemModel>
#include "database.hpp"

namespace Ui {
class ClientMainWindow;
}

class ClientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientMainWindow(QWidget *parent = nullptr);
    void setDB(Database&);
    ~ClientMainWindow();

public slots:
    void addCost();

private:
    Ui::ClientMainWindow *ui;

    QStandardItemModel *tab1;
    QStandardItemModel *tab2;
    QStandardItemModel *tab3;

    void doTablesView();
    void doSecuritesView();
    void doMySecuritesView();
    void doHistoryView();

    Database db;
    std::vector<Investment> investments;
    User *user;
};

#endif // CLIENTMAINWINDOW_HPP
