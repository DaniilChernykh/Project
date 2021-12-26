QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminmainwindow.cpp \
    clientmainwindow.cpp \
    database.cpp \
    edit_securities.cpp \
    edit_user.cpp \
    employeemainwindow.cpp \
    investment.cpp \
    main.cpp \
    mainwindow.cpp \
    security.cpp \
    user.cpp

HEADERS += \
    adminmainwindow.hpp \
    clientmainwindow.hpp \
    database.hpp \
    edit_securities.hpp \
    edit_user.hpp \
    employeemainwindow.hpp \
    investment.hpp \
    mainwindow.hpp \
    security.hpp \
    user.hpp

FORMS += \
    add_cost.ui \
    adminmainwindow.ui \
    buy_investition.ui \
    clientmainwindow.ui \
    edit_securities.ui \
    edit_user.ui \
    employeemainwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
