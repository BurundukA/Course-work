//! @file connect_data_base
//! @authors Бордукова А.А.
//! @brief Заголовок для системно-служебного функционала.
#ifndef CONNECT_DATA_BASE_H
#define CONNECT_DATA_BASE_H

#include <QAbstractItemModel>
#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QDir>
#include <QApplication>
#include <QProcessEnvironment>

class Connect_Data_Base : public QObject
{
    Q_OBJECT

public:
public:
    explicit Connect_Data_Base(QObject *parent = 0);
    ~Connect_Data_Base();
    void connectToDataBase();
    QString path;

private:
     QSqlDatabase    db;
     //!< База данных с инофрмацией о пользователях
     bool openDataBase();
     void closeDataBase();
};

#endif // CONNECT_DATA_BASE_H
