//! @file trainers_choose
//! @authors Бордукова А.А.
//! @brief Заголовок для системно-служебного функционала.
#ifndef TRAINERS_CHOOSE_H
#define TRAINERS_CHOOSE_H

#include <QWidget>
#include "connect_data_base.h"
#include "dynamic_item.h"
#include "dinamic_items.h"
#include "dynamic_layout.h"
#include "dynamic_combobox.h"

namespace Ui {
class trainers_choose;
}

class trainers_choose : public QWidget
{
    Q_OBJECT

public:
    explicit trainers_choose(QWidget *parent = nullptr);
    ~trainers_choose();
public slots:
    void get_id(QString id);
private:
    Ui::trainers_choose *ui;
public:
    QString id_user, id_user_to_change;
    //!< id работающего пользователя, id посетителя с данными которгг производят манипуляции
    Dinamic_Items * appear, *change;
    //!< Динамические PushButton
    Dinamic_Items * back, *back_1;
    //!< Динамические PushButton
    dynamic_item * vvod, *first_name, *last_name, *middle_name, *education, *category, *date_of_birth, *passport_seria, *passport_number;
    //!< Динамические QLineEdit
    dynamic_layout * answer, *text_1, *text_2;
    //!< Динамические Laybel
    dynamic_combobox * choose, *choose_time;
    //!< Динамические QComboBox
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
    void on_number_of_members_clicked();
    void get_person();
    void change_personal_data_of_visitors();
    void come_back_to_choosing_visitor();
    void come_back_to_choosing_person();
    void on_change_time_or_group_clicked();
    void get_time_or_group();
    void change_time_or_group();
    void come_back_3();
    //! @brief Вернуться к списку функций пользователя из ф-ции изменения группы или врмени занятий
    void on_write_off_the_workout_clicked();
    void come_back_4();
    //! @brief Вернуться к списку функций пользователя из ф-ции исписания/проверки списания тренировки
    void write_off_the_workout();
    void on_check_status_clicked();
    void check_status();

signals:
    void return_to_autorization();
    //! @brief Вернуться к авторизации
};

#endif // TRAINERS_CHOOSE_H
