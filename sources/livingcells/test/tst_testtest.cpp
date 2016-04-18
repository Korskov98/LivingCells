#include <QString>
#include <QtTest>
#include "api.h"
#include "field.h"

class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest();

private Q_SLOTS:
    void test_initialize_field();
    void test_change_field();
};

TestTest::TestTest()
{
}

void TestTest::test_initialize_field()
{
    Field f(5,5);
    Api model;
    bool flag = true;
    model.initialize_field(f);
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            Cell c = f.get_cell(i,j);
            if ((c.get_status() != 0) && (c.get_status() != 1)){
                flag = false;
            }
        }
    }
    QCOMPARE(flag,true);
}

void TestTest::test_change_field(){
    Field f(3,3);
    Api model;
    f.set_cell(0,0,1);
    f.set_cell(0,1,1);
    f.set_cell(0,2,1);
    f.set_cell(1,0,1);
    f.set_cell(1,1,0);
    f.set_cell(1,2,1);
    f.set_cell(2,0,0);
    f.set_cell(2,1,1);
    f.set_cell(2,2,1);
    model.change_field(f);
    Cell c = f.get_cell(0,0);
    QCOMPARE(c.get_status(),true);
    c = f.get_cell(0,1);
    QCOMPARE(c.get_status(),false);
    c = f.get_cell(0,2);
    QCOMPARE(c.get_status(),true);
    c = f.get_cell(1,0);
    QCOMPARE(c.get_status(),true);
    c = f.get_cell(1,1);
    QCOMPARE(c.get_status(),false);
    c = f.get_cell(1,2);
    QCOMPARE(c.get_status(),false);
    c = f.get_cell(2,0);
    QCOMPARE(c.get_status(),false);
    c = f.get_cell(2,1);
    QCOMPARE(c.get_status(),true);
    c = f.get_cell(2,2);
    QCOMPARE(c.get_status(),true);
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
