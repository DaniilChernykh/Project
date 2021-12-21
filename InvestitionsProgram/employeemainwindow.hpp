#ifndef EMPLOYEEMAINWINDOW_HPP
#define EMPLOYEEMAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class EmployeeMainWindow;
}

class EmployeeMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeMainWindow(QWidget *parent = nullptr);
    void setUser();
    ~EmployeeMainWindow();

private:
    Ui::EmployeeMainWindow *ui;
};

#endif // EMPLOYEEMAINWINDOW_HPP
