#ifndef EDIT_USER_HPP
#define EDIT_USER_HPP

#include <QDialog>
#include "user.hpp"

namespace Ui {
class Edit_User;
}

class Edit_User : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_User(QWidget *parent = nullptr);
    void setUser(User*);
    ~Edit_User();

public slots:
    void accept();

private:
    Ui::Edit_User *ui;
    User* user;
};

#endif // EDIT_USER_HPP
