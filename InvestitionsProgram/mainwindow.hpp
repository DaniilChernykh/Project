#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "database.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void authButton();
    void regButton();
    void exit();

private:
    void openMainWindow(int);

    Database db;
    std::vector <User>* users;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
