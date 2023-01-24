//! @file users_choose
//! @authors Бордукова А.А.
//! @brief Заголовок для системно-служебного функционала.
#ifndef USERS_CHOOSE_H
#define USERS_CHOOSE_H

#include <QWidget>
#include "dinamic_items.h"
#include "dynamic_item.h"
#include "dynamic_layout.h"
#include "connect_data_base.h"
#include<QLayout>
namespace Ui {
class users_choose;
}

class users_choose : public QWidget
{
    Q_OBJECT

public:
    explicit users_choose(QWidget *parent = nullptr);
    ~users_choose();
public slots:
    void get_id(QString id);
private:
    Ui::users_choose *ui;
public:
    QString id_user;
    //!< id работающего пользователя, id посетителя с данными которгг производят манипуляции
    Dinamic_Items * appear;
    //!< Динамические PushButton
    Dinamic_Items * back;
    //!< Динамические PushButton
    dynamic_item * vvod, *first_name, *last_name, *middle_name, *date_of_birth;
    //!< Динамические QLineEdit
    dynamic_layout * answer;
    //!< Динамические Laybel
private slots:
    void on_pushButton_clicked();
    //! @brief Перейти к полям по изменению данные о посетителях
    void on_pushButton_3_clicked();
    //! @brief Вернуться к авторизации
    void come_back();
    //! @brief Вернуться к списку функций пользователя из ф-ции изменения данных о посетителях
    void on_pushButton_2_clicked();
    //! @brief Перейти к полям по изменению личных данных
    void come_back_1();
    //! @brief Вернуться к списку функций пользователя из ф-ции изменения личных данных
    void change_personal_data();
    void come_back_2();
    //! @brief Вернуться к списку функций пользователя из ф-ции "изменения личных данных"кол-во человек в группе"
    void come_back_3();
    //! @brief Вернуться к списку функций пользователя из ф-ции изменения группы или врмени занятий
    void get_trainer();
    void on_number_of_visits_clicked();
    void on_time_limits_clicked();

signals:
    void return_to_autorization();
    //! @brief Вернуться к авторизации
};

#endif // USERS_CHOOSE_H
