#ifndef LIST_USERS_HPP
#define LIST_USERS_HPP

#include <QDialog>
#include "user.hpp"

namespace Ui {
class List_Users;
}

class List_Users : public QDialog
{
    Q_OBJECT

public:
    explicit List_Users(QWidget *parent = nullptr);
    void setUsers(std::vector<User>*);
    ~List_Users();

public slots:
    void changeUser(int);
    void editUser();
    void accept();

private:
    void build_combobox();
    Ui::List_Users *ui;
    std::vector<User>* users;
};

#endif // LIST_USERS_HPP
