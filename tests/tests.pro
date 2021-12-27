QT += testlib
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase
CONFIG += app_bundle
CONFIG += c++17

TEMPLATE = app

SOURCES +=  tst_test.cpp \
            ../InvestitionsProgram/edit_securities.cpp \
            ../InvestitionsProgram/security.cpp \
            ../InvestitionsProgram/edit_user.cpp \
            ../InvestitionsProgram/user.cpp

HEADERS +=  ../InvestitionsProgram/edit_securities.hpp \
            ../InvestitionsProgram/security.hpp \
            ../InvestitionsProgram/edit_user.hpp \
            ../InvestitionsProgram/user.hpp

FORMS +=    ../InvestitionsProgram/edit_securities.ui \
            ../InvestitionsProgram/edit_user.ui
