#include "connect_data_base.h"

Connect_Data_Base::Connect_Data_Base(QObject *parent) : QObject(parent)
{

}

Connect_Data_Base::~Connect_Data_Base()
{

}
void Connect_Data_Base::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    path = QDir::currentPath() + "/src/moscomsport.db";
    qDebug()<<path;
    if(!QFile(path).exists()){
        qDebug()<<"Базы данныйх не существует";
    } else {
        this->openDataBase();
    }
}
bool Connect_Data_Base::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if(db.open()){
        return true;
        qDebug()<<"Юху!";
    } else {
        return false;
        qDebug() << "Что-то пошло не так!";
    }
}

void Connect_Data_Base::closeDataBase()
{
    db.close();
}
