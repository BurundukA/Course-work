//! @file autoriztion
//! @authors Бордукова А.А.
//! @brief Заголовок для системно-служебного функционала.
#ifndef AUTORIZATION_H
#define AUTORIZATION_H

#include "users_choose.h"
#include "trainers_choose.h"
#include "administrator_choose.h"
#include "connect_data_base.h"
#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <iostream>
#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>

namespace Ui {
class Autorization;
}

class Autorization : public QDialog
{
    Q_OBJECT

public:
    explicit Autorization(QWidget *parent = nullptr);
    //! @brief Создание формы для авторизации
    ~Autorization();
    //! @brief Удаление формы для авторизации
signals:
    void return_to_main_window();
    //! @brief Возварещение к форме выбора типа учтёной записи
    void pass_id(QString id);
    //! @brief Передача вызываемому окну id авторизировавшегося пользователя
    //! @param[in] id -id авторизировавшегося пользователя
private slots:
    void on_pushButton_clicked();
    //! @brief Авторизация
    void on_pushButton_3_clicked();
    //! @brief Возварещение к форме выбора типа учтёной записи

public slots:
    void slot(QString a);
     //! @brief Получение данных о типе учтной записи из предыдущей формы

private:
    QSqlDatabase    db;
    //!< База данных с инофрмацией о пользователях
    Ui::Autorization *ui;
    users_choose *us_choose;
    trainers_choose *tr_choose;
    administrator_choose *ad_choose;
    //!< Вызываемые формы
public:
    QString user_type;
    //!< Тип учётной записи
};

#endif // AUTORIZATION_H
