#include <memory>
#include <QtTest>
#include <QCoreApplication>
#include <QMessageBox>

#include "../InvestitionsProgram/edit_securities.hpp"
#include "../InvestitionsProgram/security.hpp"

#include "../InvestitionsProgram/edit_user.hpp"
#include "../InvestitionsProgram/user.hpp"

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case1_data();
    void test_case2();
    void test_case2_data();
private:
    std::unique_ptr<Edit_Securities> m_dlg1;
    std::unique_ptr<Edit_User> m_dlg2;
};

void test::initTestCase()
{
    m_dlg1.reset(new Edit_Securities);
    m_dlg2.reset(new Edit_User);
}

void test::cleanupTestCase()
{
    m_dlg1.reset();
    m_dlg2.reset();
}

void test::test_case1_data()
{
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("cost_old");
    QTest::addColumn<QString>("cost_new");

    QTest::newRow("empty name") << "" << "1000" << "2000";
    QTest::newRow("empty new cost") << "Kebab" << "1000" << "";
    QTest::newRow("negative new cost") << "Kebab" << "1000" << "-5000";
    QTest::newRow("zero new cost") << "Kebab" << "1000" << "0";
}

void test::test_case1()
{
    QFETCH(QString, name);
    QFETCH(QString, cost_old);
    QFETCH(QString, cost_new);
    Security sec;
    m_dlg1->setSecurity(&sec);
    QSignalSpy spy(m_dlg1.get(), &Edit_Securities::accepted);
    m_dlg1->setLineName(name);
    m_dlg1->setLineOCostEdit(cost_old);
    m_dlg1->setLineNCostEdit(cost_new);
    m_dlg1->setLineAvailableBox(true);
    m_dlg1->open();
    QTimer::singleShot(0, [=]()
    {
        QMessageBox *box = dynamic_cast<QMessageBox *>(QApplication::activeModalWidget());
        box->accept();
        m_dlg1->reject();
    });
    m_dlg1->accept();
    QVERIFY2(spy.count() == 0, "Неверная работоспособность класса Edit_Securities.");
}

void test::test_case2_data()
{
    QTest::addColumn<QString>("login");
    QTest::addColumn<QString>("password");
    QTest::addColumn<QString>("password_2");
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("phone");
    QTest::addColumn<QString>("adress");

    QTest::newRow("empty login") << "" << "123" << "123" << "Kebab" << "+79509556655" << "Krasnoyarsk";
    QTest::newRow("empty password") << "clientik" << "" << "123" << "Kebab" << "+79509556655" << "Krasnoyarsk";
    QTest::newRow("empty password_2") << "clientik" << "123" << "" << "Kebab" << "+79509556655" << "Krasnoyarsk";
    QTest::newRow("empty name") << "clientik" << "123" << "123" << "" << "+79509556655" << "Krasnoyarsk";
    QTest::newRow("empty phone") << "clientik" << "123" << "123" << "Kebab" << "" << "Krasnoyarsk";
    QTest::newRow("empty adress") << "clientik" << "123" << "123" << "Kebab" << "+79509556655" << "";

    QTest::newRow("pass != pass2") << "clientik" << "123" << "321" << "Kebab" << "+79509556655" << "Krasnoyarsk";
}

void test::test_case2()
{
    QFETCH(QString, login);
    QFETCH(QString, password);
    QFETCH(QString, password_2);
    QFETCH(QString, name);
    QFETCH(QString, phone);
    QFETCH(QString, adress);
    User u;
    m_dlg2->setUser(&u);
    QSignalSpy spy(m_dlg2.get(), &Edit_User::accepted);
    m_dlg2->setLineLogin(login);
    m_dlg2->setLinePassword(password);
    m_dlg2->setLinePassword2(password_2);
    m_dlg2->setLineName(name);
    m_dlg2->setLinePhone(phone);
    m_dlg2->setLineAdress(adress);
    m_dlg2->open();
    QTimer::singleShot(0, [=]()
    {
        QMessageBox *box = dynamic_cast<QMessageBox *>(QApplication::activeModalWidget());
        box->accept();
        m_dlg2->reject();
    });
    m_dlg2->accept();
    QVERIFY2(spy.count() == 0, "Неверная работоспособность класса Edit_Users.");
}

test::test()
{

}

test::~test()
{

}

QTEST_MAIN(test)

#include "tst_test.moc"
