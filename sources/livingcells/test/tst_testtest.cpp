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
};

TestTest::TestTest()
{
}

void TestTest::test_initialize_field()
{
    Field f(5, 5);
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

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"
