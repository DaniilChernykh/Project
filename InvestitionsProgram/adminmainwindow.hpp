#ifndef ADMINMAINWINDOW_HPP
#define ADMINMAINWINDOW_HPP

#include <QMainWindow>
#include "database.hpp"

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = nullptr);
    void setDB(Database&);
    ~AdminMainWindow();

public slots:
    void manageUsers();
    void historyChangedSecurities();

private:
    Ui::AdminMainWindow *ui;
    Database db;
};

#endif // ADMINMAINWINDOW_HPP
