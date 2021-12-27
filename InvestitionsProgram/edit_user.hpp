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
    void setCurrentValues();
    void setLineLogin(QString);
    void setLinePassword(QString);
    void setLinePassword2(QString);
    void setLineName(QString);
    void setLineAdress(QString);
    void setLinePhone(QString);
    ~Edit_User();

public slots:
    void accept();

private:
    Ui::Edit_User *ui;
    User* user;
};

#endif // EDIT_USER_HPP
