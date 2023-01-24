//! @file administrator_choose
//! @authors Бордукова А.А.
//! @brief Заголовок для системно-служебного функционала.
#ifndef ADMINISTRATOR_CHOOSE_H
#define ADMINISTRATOR_CHOOSE_H

#include <QWidget>
#include "connect_data_base.h"
#include "dynamic_item.h"
#include "dinamic_items.h"
#include "dynamic_layout.h"
#include "dynamic_combobox.h"

namespace Ui {
class administrator_choose;
}

class administrator_choose : public QWidget
{
    Q_OBJECT

public:
    explicit administrator_choose(QWidget *parent = nullptr);
    //! @brief Создание формы для работа под учётной записью администратора
    ~administrator_choose();
    //! @brief Удаление формы для работа под учётной записью администратора

public slots:
    void get_id(QString id);
    //! @brief Получение id пользователя при его авторизации из базы данных

public:
    QString id_user, id_user_to_change;
    //!< id работающего пользователя, id посетителя с данными которгг производят манипуляции
    Dinamic_Items * appear, *change, * deletes, *block;
    //!< Динамические PushButton
    Dinamic_Items * back, *back_1;
    //!< Динамические PushButton
    dynamic_item * vvod, *first_name, *last_name, *middle_name, *education, *category, *date_of_birth, *passport_seria, *passport_number, *count;
    //!< Динамические QLineEdit
    dynamic_layout * answer, *text_1, *text_2;
    //!< Динамические Laybel
    dynamic_combobox * choose, *choose_time, *choose_group, *choose_benefits, *choose_marks;
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
    void on_add_trains_clicked();
    void come_back_5();
    //! @brief Вернуться к списку функций пользователя из ф-ции пополения абонемента
    void add_trains();
    void on_delete_or_block_card_clicked();
    void come_back_6();
    //! @brief Вернуться к списку функций пользователя из ф-ции блокировки/удалоения карты
    void blocks();
    void deletess();
    void on_add_user_clicked();
    void come_back_7();
    //! @brief Вернуться к списку функций пользователя из ф-ции добваления клиента
    void add_user();

signals:
    void return_to_autorization();
    //! @brief Вернуться к авторизации
private:
    Ui::administrator_choose *ui;
};

#endif // ADMINISTRATOR_CHOOSE_H
