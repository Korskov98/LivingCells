#include "mainwindow.h"
#include <QApplication>
#include "field.h"
#include "api.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(0);
    w.show();

    return a.exec();
}
