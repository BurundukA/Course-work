#include "mainwindow.h"
#include "connect_data_base.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connect_Data_Base database;
    database.connectToDataBase();
    MainWindow w;
    w.show();
    return a.exec();
}
