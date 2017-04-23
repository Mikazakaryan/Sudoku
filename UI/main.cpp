#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow first_page;
    first_page.show();

//    QMainWindow rules_p;
//    rules_p.show();

    return a.exec();
}
