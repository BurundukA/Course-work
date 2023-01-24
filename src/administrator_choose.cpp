#include "administrator_choose.h"
#include "ui_administrator_choose.h"

administrator_choose::administrator_choose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrator_choose)
{
    ui->setupUi(this);
    this->setWindowTitle("Функционал администратора");
}

administrator_choose::~administrator_choose()
{
    delete ui;
}

void administrator_choose::get_id(QString id)
{
    id_user = id;
    //qDebug()<<id_user;
}
void administrator_choose::on_pushButton_clicked()
{
    appear = new Dinamic_Items(this);
    vvod = new dynamic_item(this);
    vvod->setText("Введите фамилию посетителя");
    appear->setText("Найти");
    answer = new dynamic_layout();
    ui->gridLayout->addWidget(vvod, 2, 1);
    ui->gridLayout->addWidget(appear, 2, 2);
    back = new Dinamic_Items(this);
    back->setText("Назад");
    ui->pushButton_2->hide();
    ui->number_of_members->hide();
    ui->gridLayout->addWidget(back, 0, 2);
    ui->change_time_or_group->hide();
    ui->check_status->hide();
    ui->write_off_the_workout->hide();
    ui->add_trains->hide();
    ui->delete_or_block_card->hide();
    ui->add_user->hide();
    ui->pushButton->blockSignals(true);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back()));
    connect(appear, SIGNAL(clicked()), this, SLOT(get_person()));
}

void administrator_choose::get_person()
{
    QString l_name = vvod->text();
    //qDebug()<<l_name;
    vvod->hide();
    back->hide();
    appear->hide();
    change = new Dinamic_Items(this);
    back_1 = new Dinamic_Items(this);
    first_name = new dynamic_item(this);
    last_name = new dynamic_item(this);
    middle_name = new dynamic_item(this);
    date_of_birth = new dynamic_item(this);
    passport_seria = new dynamic_item(this);
    passport_number = new dynamic_item(this);
    QSqlQuery person;
    person.exec("SELECT first_name, last_name, middle_name, date_of_birth, passport_seria, passport_number, id_user FROM users WHERE last_name = \'" +l_name+ "\'");
    person.next();
    change->setText("Изменить");
    back_1->setText("Назад");
    id_user_to_change = person.value(6).toString();
    first_name->setText(person.value(0).toString());
    last_name->setText(person.value(1).toString());
    middle_name->setText(person.value(2).toString());
    date_of_birth->setText(person.value(3).toString());
    passport_seria->setText(person.value(4).toString());
    passport_number->setText(person.value(5).toString());
    ui->gridLayout->addWidget(back_1, 0, 2);
    ui->gridLayout->addWidget(first_name, 2, 1);
    ui->gridLayout->addWidget(last_name, 3, 1);
    ui->gridLayout->addWidget(middle_name, 4, 1);
    ui->gridLayout->addWidget(date_of_birth, 5, 1);
    ui->gridLayout->addWidget(passport_seria, 6, 1);
    ui->gridLayout->addWidget(passport_number, 7, 1);
    ui->gridLayout->addWidget(change, 7, 2);
    connect(back_1, SIGNAL(clicked()), this, SLOT(come_back_to_choosing_visitor()));
    connect(change, SIGNAL(clicked()), this, SLOT(change_personal_data_of_visitors()));
}

void administrator_choose::change_personal_data_of_visitors()
{
    QString f_name = first_name->text();
    QString l_name = last_name->text();
    QString m_name = middle_name->text();
    QString d_of_birth = date_of_birth->text();
    QString p_seria = passport_seria->text();
    QString p_number = passport_number->text();
    QSqlQuery vvod;
    qDebug()<<id_user_to_change;
  /*vvod.exec("UPDATE users SET first_name = \'" + f_name +
                 "\' ,last_name = \'" + l_name +
                 "\', middle_name = \'" + m_name+
             "\', date_of_birth = \'" + d_of_birth+
             "\', passport_seria = \'" + p_seria+
             "\', Passport_number = \'" + p_number+
                 "\' WHERE id_user = \'"+id_user_to_change+"\'");*/
   vvod.exec("UPDATE users SET first_name = \'" + f_name +
             "\' ,last_name = \'" + l_name +
             "\', middle_name = \'" + m_name+
             "\', date_of_birth = \'" + d_of_birth+
             "\', passport_seria = \'" + p_seria+
             "\', Passport_number = \'" + p_number+
             "\' WHERE id_user =\'"+id_user_to_change+"\'");
   answer->setText("Данные успешно обновлены!");
   ui->gridLayout->addWidget(answer, 8, 1);
}

void administrator_choose::come_back_to_choosing_visitor()
{
    back->show();
    vvod->show();
    appear->show();
    first_name->hide();
    delete first_name;
    last_name->hide();
    delete last_name;
    middle_name->hide();
    delete middle_name;
    date_of_birth->hide();
    delete date_of_birth;
    passport_seria->hide();
    delete passport_seria;
    passport_number->hide();
    delete passport_number;
    change->hide();
    delete change;
    back_1->hide();
    delete back_1;
    answer->hide();
}

void administrator_choose::on_pushButton_3_clicked()
{
    this->close();
    emit return_to_autorization();
}
void administrator_choose::come_back()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->number_of_members->show();
    ui->change_time_or_group->show();
    ui->check_status->show();
    ui->write_off_the_workout->show();
    ui->add_trains->show();
    ui->delete_or_block_card->show();
    ui->add_user->show();
    ui->pushButton->blockSignals(false);
    back->hide();
    vvod->hide();
    appear->hide();
    answer->hide();
    delete back;
    delete vvod;
    delete appear;
    delete answer;
}


void administrator_choose::on_pushButton_2_clicked()
{
    appear = new Dinamic_Items(this);
    back = new Dinamic_Items(this);
    first_name = new dynamic_item(this);
    last_name = new dynamic_item(this);
    middle_name = new dynamic_item(this);
    education= new dynamic_item(this);
    category= new dynamic_item(this);
    answer = new dynamic_layout();
    QSqlQuery person;
    qDebug()<<id_user;
    person.exec("SELECT first_name, last_name, middle_name, education, category FROM trainers WHERE id_trainer = \'" +id_user+ "\'");
    person.next();
    first_name->setText(person.value(0).toString());
    last_name->setText(person.value(1).toString());
    middle_name->setText(person.value(2).toString());
    education->setText(person.value(3).toString());
    category->setText(person.value(4).toString());
    appear->setText("Изменить");
    back->setText("Назад");
    ui->pushButton->hide();
    ui->number_of_members->hide();
    ui->change_time_or_group->hide();
    ui->check_status->hide();
    ui->write_off_the_workout->hide();
    ui->add_trains->hide();
    ui->delete_or_block_card->hide();
    ui->add_user->hide();
    ui->gridLayout->addWidget(back, 0, 2);
    ui->gridLayout->addWidget(first_name, 3, 1);
    ui->gridLayout->addWidget(last_name, 4, 1);
    ui->gridLayout->addWidget(middle_name, 5, 1);
    ui->gridLayout->addWidget(education, 6, 1);
    ui->gridLayout->addWidget(category, 7, 1);
    ui->gridLayout->addWidget(appear, 7, 2);
    ui->pushButton_2->blockSignals(true);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_1()));
    connect(appear, SIGNAL(clicked()), this, SLOT(change_personal_data()));
}

void administrator_choose::come_back_1()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->number_of_members->show();
    ui->change_time_or_group->show();
    ui->check_status->show();
    ui->write_off_the_workout->show();
    ui->add_trains->show();
    ui->delete_or_block_card->show();
    ui->add_user->show();
    ui->pushButton->blockSignals(false);
    first_name->hide();
    delete first_name;
    last_name->hide();
    delete last_name;
    middle_name->hide();
    delete middle_name;
    education->hide();
    delete education;
    category->hide();
    delete category;
    appear->hide();
    delete appear;
    back->hide();
    delete back;
    answer->hide();
    delete answer;
}

void administrator_choose::change_personal_data()
{
    QString f_name = first_name->text();
    QString l_name = last_name->text();
    QString m_name = middle_name->text();
    QString edu = education->text();
    QString cat = category->text();
    QSqlQuery vvod;
    QSqlQuery query;
   vvod.exec("UPDATE trainers SET first_name = \'" + f_name +
                 "\' ,last_name = \'" + l_name +
                 "\', middle_name = \'" + m_name+
             "\', education = \'" + edu+
             "\', category = \'" + cat+
                 "\' WHERE id_trainer = \'"+id_user+"\'");
   answer->setText("Данные успешно обновлены!");
   ui->gridLayout->addWidget(answer, 8, 1);

}


void administrator_choose::on_number_of_members_clicked()
{
    back = new Dinamic_Items(this);
    back->setText("Назад");
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->change_time_or_group->hide();
    ui->check_status->hide();
    ui->write_off_the_workout->hide();
    ui->add_trains->hide();
    ui->delete_or_block_card->hide();
    ui->add_user->hide();
    ui->number_of_members->blockSignals(true);
    answer = new dynamic_layout();
    QString data;
    ui->gridLayout->addWidget(back, 0, 2);
    QSqlQuery trains;
    trains.exec("SELECT g.id_group, COUNT(c.id_card) AS count FROM cards AS c RIGHT JOIN groupss AS g ON g.id_group = c.groupsss WHERE g.trainer = \'" + id_user+ "\'GROUP BY g.id_group");
    while (trains.next()) {
            data.append(trains.value(0).toString());
            data.append("->");
            data.append(trains.value(1).toString());
            data.append("\n");
        }
    answer->setText(data);
    qDebug()<<data;
    ui->gridLayout->addWidget(answer, 4 ,1);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_2()));
}

void administrator_choose::come_back_2()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->change_time_or_group->show();
    ui->number_of_members->show();
    ui->check_status->show();
    ui->write_off_the_workout->show();
    ui->add_trains->show();
    ui->delete_or_block_card->show();
    ui->add_user->show();
    ui->number_of_members->blockSignals(false);
    back->hide();
    delete back;
    answer->hide();
    delete answer;
}



void administrator_choose::on_change_time_or_group_clicked()
{
    appear = new Dinamic_Items(this);
    vvod = new dynamic_item(this);
    vvod->setText("Введите фамилию посетителя");
    appear->setText("Найти");
    answer = new dynamic_layout();
    //ui->gridLayout->addWidget(ui->change_time_or_group, 1, 1);
    ui->gridLayout->addWidget(vvod, 2, 1);
    ui->gridLayout->addWidget(appear, 2, 2);
    back = new Dinamic_Items(this);
    back->setText("Назад");
    ui->pushButton_2->hide();
    ui->number_of_members->hide();
    ui->gridLayout->addWidget(back, 0, 2);
    ui->pushButton->hide();
    ui->check_status->hide();
    ui->write_off_the_workout->hide();
    ui->add_trains->hide();
    ui->delete_or_block_card->hide();
    ui->add_user->hide();
    ui->change_time_or_group->blockSignals(true);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_3()));
    connect(appear, SIGNAL(clicked()), this, SLOT(get_time_or_group()));
}

void administrator_choose::get_time_or_group()
{
    QString l_name = vvod->text();
    qDebug()<<l_name;
    vvod->hide();
    back->hide();
    appear->hide();
    change = new Dinamic_Items(this);
    back_1 = new Dinamic_Items(this);
    first_name = new dynamic_item(this);
    last_name = new dynamic_item(this);
    QSqlQuery person;
    person.exec("SELECT id_user FROM users WHERE last_name = \'" +l_name+ "\'");
    person.next();
    change->setText("Изменить");
    back_1->setText("Назад");
    id_user_to_change = person.value(0).toString();
    person.exec("SELECT train, groupsss FROM cards WHERE id_card = \'" +id_user_to_change+ "\' AND ( train = 'Занятие в группе' OR train = 'Аквааэробика')");
    ui->gridLayout->addWidget(back_1, 0, 2);
    if(person.next())
    {text_1 = new dynamic_layout();
    text_2 = new dynamic_layout();
    text_1 ->setText(person.value(0).toString());
    first_name->setText(person.value(1).toString());
    ui->gridLayout->addWidget(text_1, 2, 1);
    ui->gridLayout->addWidget(first_name, 2, 2);
    ui->gridLayout->addWidget(change, 2, 3);
    answer->setText("1");
    if(person.next())
    {
    text_2 ->setText(person.value(0).toString());
    last_name->setText(person.value(1).toString());
    ui->gridLayout->addWidget(text_2, 3, 1);
    ui->gridLayout->addWidget(last_name, 3, 2);
     ui->gridLayout->addWidget(change, 3, 3);
    answer->setText("2");
    }
    }
    else
    {
        answer->setText("Пользователь не числится ни в одной группе");
    }
    connect(back_1, SIGNAL(clicked()), this, SLOT(come_back_to_choosing_person()));
    connect(change, SIGNAL(clicked()), this, SLOT(change_time_or_group()));
}

void administrator_choose::come_back_to_choosing_person()
{
    back->show();
    vvod->show();
    appear->show();
    if(answer->text() == "Пользователь не числится ни в одной группе")
    {
        back_1->hide();
        delete back_1;
        answer->hide();
        vvod->setText("Введите фамилию посетителя");
    }
    if(answer->text() == "Данные успешно обновлены1!" || answer->text()=="1")
    {
        first_name->hide();
        delete first_name;
        text_1->hide();
        delete text_1;
        back_1->hide();
        delete back_1;
        answer->hide();
        change->hide();
        delete change;
        vvod->setText("Введите фамилию посетителя");
    }
    if(answer->text() == "Данные успешно обновлены2!" || answer->text()=="2")
    {
    first_name->hide();
    delete first_name;
    last_name->hide();
    delete last_name;
    text_1->hide();
    delete text_1;
    text_2->hide();
    delete text_2;
    change->hide();
    delete change;
    back_1->hide();
    delete back_1;
    answer->hide();
    vvod->setText("Введите фамилию посетителя");
    }
}

void administrator_choose::change_time_or_group()
{
    if(answer->text() == "1")
    {
        QString f_name = first_name->text();
        QString type_1 = text_1->text();
        QSqlQuery vvod;
       vvod.exec("UPDATE cards SET groupsss = \'" +f_name+ "\' WHERE id_card = \'" +id_user_to_change+ "\' AND train = \'" +type_1+ "\'; ");
       answer->setText("Данные успешно обновлены1!");
       ui->gridLayout->addWidget(answer, 4, 1);
    }
    else
    {
        QString f_name = first_name->text();
        QString l_name = last_name->text();
        QString type_1 = text_1->text();
        QString type_2 = text_2->text();
        QSqlQuery vvod;
       vvod.exec("UPDATE cards SET groupsss = \'" +f_name+ "\' WHERE id_card = \'" +id_user_to_change+ "\' AND train = \'" +type_1+ "\'");
       vvod.exec("UPDATE cards SET groupsss = \'" +l_name+ "\' WHERE id_card = \'" +id_user_to_change+ "\' AND train = \'" +type_2+ "\'");
       answer->setText("Данные успешно обновлены2!");
       ui->gridLayout->addWidget(answer, 5, 1);
    }
}
void administrator_choose::come_back_3()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->change_time_or_group->show();
    ui->number_of_members->show();
    ui->check_status->show();
    ui->write_off_the_workout->show();
    ui->add_trains->show();
    ui->delete_or_block_card->show();
    ui->add_user->show();
    ui->change_time_or_group->blockSignals(false);
    back->hide();
    delete back;
    answer->hide();
    delete answer;
    vvod->hide();
    delete vvod;
    appear->hide();
    delete appear;
}


void administrator_choose::on_write_off_the_workout_clicked()
{
    ui->pushButton_2->hide();
    ui->number_of_members->hide();
    ui->pushButton->hide();
    ui->change_time_or_group->hide();
    ui->check_status->hide();
    ui->add_trains->hide();
    ui->delete_or_block_card->hide();
    ui->add_user->hide();
    ui->write_off_the_workout->blockSignals(true);
    choose_time = new dynamic_combobox(this);
    choose = new dynamic_combobox(this);
    choose->addItem("Свободное плавание");
    choose->addItem("Групповая тренировка");
    choose->addItem("Аквааэробика");
    back = new Dinamic_Items(this);
    back->setText("Назад");
    appear = new Dinamic_Items(this);
    appear->setText("Добавить");
    vvod = new dynamic_item(this);
    vvod->setText("0000-00-00");
    answer = new dynamic_layout();
    last_name = new dynamic_item(this);
    last_name->setText("Фамилия");
    QSqlQuery choose_time_from_table;
    choose_time_from_table.exec("SELECT times FROM times");
    while(choose_time_from_table.next())
    {
        choose_time->addItem(choose_time_from_table.value(0).toString());
    }
    ui->gridLayout->addWidget(back, 0, 2);
    ui->gridLayout->addWidget(choose, 3, 1);
    ui->gridLayout->addWidget(vvod, 3, 2);
    ui->gridLayout->addWidget(choose_time, 3, 3);
    ui->gridLayout->addWidget(last_name, 3, 4);
    ui->gridLayout->addWidget(appear, 4, 4);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_4()));
    connect(appear, SIGNAL(clicked()), this, SLOT(write_off_the_workout()));
}

void administrator_choose::come_back_4()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->change_time_or_group->show();
    ui->number_of_members->show();
    ui->write_off_the_workout->show();
    ui->check_status->show();
    ui->add_trains->show();
    ui->delete_or_block_card->show();
    ui->add_user->show();
    ui->write_off_the_workout->blockSignals(false);
     ui->check_status->blockSignals(false);
    back->hide();
    delete back;
    choose->hide();
    delete choose;
    choose_time->hide();
    delete choose_time;
    answer->hide();
    delete answer;
    vvod->hide();
    delete vvod;
    appear->hide();
    delete appear;
    last_name->hide();
    delete last_name;
}

void administrator_choose::write_off_the_workout()
{
    QString choose_1 = choose->currentText();
    QString date = vvod->text();
    QString choose_time_1 = choose_time->currentText();
    QString l_name = last_name->text();
    QSqlQuery visitor_id;
    visitor_id.exec("SELECT id_user FROM users WHERE last_Name = \'"+l_name+"\'");
    visitor_id.next();
    QString v_id = visitor_id.value(0).toString();
    //qDebug()<<v_id;
    QSqlQuery time;
    time.exec("SELECT id_time fROM times WHERE times =\'"+choose_time_1+"\'");
    time.next();
    choose_time_1 = time.value(0).toString();
    QSqlQuery vvod;
    vvod.exec("INSERT INTO visits (DATE, time, trainer, id_visitor) VALUES (\'" + date+"\',\'"+ choose_time_1+"\',\'" +id_user+ "\',\'" + v_id+"\')");
    QSqlQuery minus;
    minus.exec("UPDATE cards SET COUNT = COUNT - 1 WHERE train = \'"+choose_1+"\' and id_card = \'"+v_id+"\'");
    answer->setText("Запись добавлена!");
    ui->gridLayout->addWidget(answer, 6, 1);
}




void administrator_choose::on_check_status_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->number_of_members->hide();
    ui->pushButton->hide();
    ui->change_time_or_group->hide();
    ui->write_off_the_workout->hide();
    ui->add_trains->hide();
    ui->delete_or_block_card->hide();
    ui->add_user->hide();
    ui->check_status->blockSignals(true);
    back = new Dinamic_Items(this);
    back->setText("Назад");
    choose_time = new dynamic_combobox(this);
    choose = new dynamic_combobox(this);
    choose->addItem("Свободное плавание");
    choose->addItem("Групповая тренировка");
    choose->addItem("Аквааэробика");
    back = new Dinamic_Items(this);
    back->setText("Назад");
    appear = new Dinamic_Items(this);
    appear->setText("Проверить");
    vvod = new dynamic_item(this);
    vvod->setText("0000-00-00");
    answer = new dynamic_layout();
    last_name = new dynamic_item(this);
    last_name->setText("Фамилия");
    QSqlQuery choose_time_from_table;
    choose_time_from_table.exec("SELECT times FROM times");
    while(choose_time_from_table.next())
    {
        choose_time->addItem(choose_time_from_table.value(0).toString());
    }
    ui->gridLayout->addWidget(back, 0, 2);
    ui->gridLayout->addWidget(choose, 3, 1);
    ui->gridLayout->addWidget(vvod, 3, 2);
    ui->gridLayout->addWidget(choose_time, 3, 3);
    ui->gridLayout->addWidget(last_name, 3, 4);
    ui->gridLayout->addWidget(appear, 4, 4);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_4()));
    connect(appear, SIGNAL(clicked()), this, SLOT(check_status()));
}

void administrator_choose::check_status()
{
    QString choose_1 = choose->currentText();
    QString date = vvod->text();
    QString choose_time_1 = choose_time->currentText();
    QString l_name = last_name->text();
    QSqlQuery visitor_id;
    visitor_id.exec("SELECT id_user FROM users WHERE last_Name = \'"+l_name+"\'");
    visitor_id.next();
    QString v_id = visitor_id.value(0).toString();
    //qDebug()<<v_id;
    QSqlQuery time;
    time.exec("SELECT id_time fROM times WHERE times =\'"+choose_time_1+"\'");
    time.next();
    choose_time_1 = time.value(0).toString();
    QSqlQuery vvod;
    vvod.exec("SELECT id_visit FROM visits WHERE DATE = \'" + date+"\' AND time = \'"+ choose_time_1+ "\' AND trainer = \'" +id_user+ "\' AND id_visitor = \'" + v_id+"\'" );
    if (vvod.next())
    {
        answer->setText("Тренировка списана!");
    }
    else
    {
        answer->setText("Тренировка не списана!");
    }
    ui->gridLayout->addWidget(answer, 5, 1);
}

void administrator_choose::on_add_trains_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->number_of_members->hide();
    ui->change_time_or_group->hide();
    ui->write_off_the_workout->hide();
    ui->check_status->hide();
    ui->delete_or_block_card->hide();
    ui->add_user->hide();
    ui->add_trains->blockSignals(true);
    back = new Dinamic_Items(this);
    back->setText("Назад");
    last_name = new dynamic_item(this);
    last_name->setText("Фамилия");
    choose = new dynamic_combobox(this);
    choose_group = new dynamic_combobox(this);
    QSqlQuery choose_group_from_table;
    choose_group_from_table.exec("SELECT id_group FROM groupss");
    while(choose_group_from_table.next())
    {
        choose_group->addItem(choose_group_from_table.value(0).toString());
    }
    choose->addItem("Свободное плавание");
    choose->addItem("Групповая тренировка");
    choose->addItem("Аквааэробика");
    count = new dynamic_item(this);
    count->setText("кол-во");
    appear = new Dinamic_Items(this);
    appear->setText("Добавить");
    answer = new dynamic_layout();
    ui->gridLayout->addWidget(back, 0, 2);
    ui->gridLayout->addWidget(last_name, 3, 1);
    ui->gridLayout->addWidget(choose, 3, 2);
    ui->gridLayout->addWidget(count, 3, 3);
    ui->gridLayout->addWidget(choose_group, 3, 4);
    ui->gridLayout->addWidget(appear, 4, 4);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_5()));
    connect(appear, SIGNAL(clicked()), this, SLOT(add_trains()));
}

void administrator_choose::come_back_5()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->change_time_or_group->show();
    ui->number_of_members->show();
    ui->write_off_the_workout->show();
    ui->check_status->show();
    ui->add_trains->show();
    ui->delete_or_block_card->show();
    ui->add_user->show();
    ui->add_trains->blockSignals(false);
    back->hide();
    delete back;
    choose->hide();
    delete choose;
    answer->hide();
    delete answer;
    appear->hide();
    delete appear;
    last_name->hide();
    delete last_name;
    count->hide();
    delete count;
    choose_group->hide();
    delete choose_group;
}

void administrator_choose:: add_trains()
{
    QString choose_1 = choose->currentText();
    QString number = count->text();
    QString l_name = last_name->text();
    QString group = choose_group->currentText();
    QSqlQuery visitor_id;
    visitor_id.exec("SELECT id_user FROM users WHERE last_Name = \'"+l_name+"\'");
    visitor_id.next();
    QString v_id = visitor_id.value(0).toString();
    QSqlQuery check;
    QSqlQuery vvod;
    QString time_limits;
    check.exec("SELECT id_card  FROM cards WHERE id_card = \'"+v_id+"\' AND train = \'"+choose_1+"\'");
    if(check.next())
    {
        vvod.exec("UPDATE cards SET count = \'"+number+"\', time_limits = 30 WHERE id_card = \'"+v_id+"\' AND train = \'"+choose_1+"\'");
        answer->setText("Данные успешно обновлены");
    }
    else
    {
        vvod.exec("INSERT INTO cards (id_card,train, count, time_limits, groupsss) VALUES (\'"+v_id+"\',\'"+choose_1+"\',\'"+number+"\', 30, \'"+group+"\')");
        answer->setText("Данные успешно обновлены");
    }
    ui->gridLayout->addWidget(answer, 5, 1);
}

void administrator_choose::on_delete_or_block_card_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->number_of_members->hide();
    ui->change_time_or_group->hide();
    ui->write_off_the_workout->hide();
    ui->check_status->hide();
    ui->add_trains->hide();
    ui->add_user->hide();
    ui->delete_or_block_card->blockSignals(true);
    back = new Dinamic_Items(this);
    back->setText("Назад");
    last_name = new dynamic_item(this);
    last_name->setText("Фамилия");
    deletes = new Dinamic_Items(this);
    deletes->setText("Удалить");
    block = new Dinamic_Items(this);
    block->setText("Заблокировать");
    answer = new dynamic_layout();
    ui->gridLayout->addWidget(back, 0, 2);
    ui->gridLayout->addWidget(last_name, 3, 1);
    ui->gridLayout->addWidget(deletes, 4, 1);
    ui->gridLayout->addWidget(block, 4, 2);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_6()));
    connect(deletes, SIGNAL(clicked()), this, SLOT(deletess()));
    connect(block, SIGNAL(clicked()), this, SLOT(blocks()));
}

void administrator_choose::come_back_6()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->change_time_or_group->show();
    ui->number_of_members->show();
    ui->write_off_the_workout->show();
    ui->check_status->show();
    ui->add_trains->show();
    ui->delete_or_block_card->show();
    ui->add_user->show();
    ui->delete_or_block_card->blockSignals(false);
    back->hide();
    delete back;
    answer->hide();
    delete answer;
    last_name->hide();
    delete last_name;
    deletes->hide();
    delete deletes;
    block->hide();
    delete block;
}

void administrator_choose::deletess()
{
    QString l_name = last_name->text();
    QSqlQuery del;
    del.exec("DELETE FROM users WHERE last_name = \'"+l_name+"\'");
    answer->setText("Пользователь удалён");
    ui->gridLayout->addWidget(answer, 5, 1);
}

void administrator_choose::blocks()
{
    QString l_name = last_name->text();
    QSqlQuery blo;
    blo.exec("UPDATE users SET marks = 1 WHERE last_name = \'"+l_name+"\'");
    answer->setText("Пользователь заблокирован");
    ui->gridLayout->addWidget(answer, 5, 1);
}

void administrator_choose::on_add_user_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->number_of_members->hide();
    ui->change_time_or_group->hide();
    ui->write_off_the_workout->hide();
    ui->check_status->hide();
    ui->add_trains->hide();
    ui->delete_or_block_card->hide();
    ui->add_user->blockSignals(true);
    back = new Dinamic_Items(this);
    back->setText("Назад");
    first_name = new dynamic_item(this);
    first_name->setText("Имя");
    last_name = new dynamic_item(this);
    last_name->setText("Фамилия");
    middle_name = new dynamic_item(this);
    middle_name->setText("Отчество");
    date_of_birth = new dynamic_item(this);
    date_of_birth->setText("Дата рождения");
    passport_seria = new dynamic_item(this);
    passport_seria->setText("Паспор(серия)");
    passport_number = new dynamic_item(this);
    passport_number->setText("Паспорт(номер)");
    appear = new Dinamic_Items(this);
    appear->setText("Добавить");
    choose_benefits = new dynamic_combobox(this);
    QSqlQuery benefits;
    benefits.exec("SELECT NAME FROM benefits");
    while(benefits.next())
    {
        //qDebug()<<(benefits.value(0).toString());
        choose_benefits->addItem(benefits.value(0).toString());
    }
    choose_benefits->addItem("Нет");
    choose_marks = new dynamic_combobox(this);
    QSqlQuery marks;
    marks.exec("SELECT NAME FROM marks");
    while(marks.next())
    {
        //qDebug()<<(marks.value(0).toString());
        choose_marks->addItem(marks.value(0).toString());
    }
    choose_marks->addItem("Нет");
    answer = new dynamic_layout();
    ui->gridLayout->addWidget(back, 0, 2);
    ui->gridLayout->addWidget(last_name, 3, 1);
    ui->gridLayout->addWidget(first_name, 3, 2);
    ui->gridLayout->addWidget(middle_name, 3, 3);
    ui->gridLayout->addWidget(passport_seria, 4, 1);
    ui->gridLayout->addWidget(passport_number, 4, 2);
    ui->gridLayout->addWidget(choose_benefits, 5, 1);
    ui->gridLayout->addWidget(choose_marks, 5, 2);
    ui->gridLayout->addWidget(appear, 5, 3);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_7()));
    connect(appear, SIGNAL(clicked()), this, SLOT(add_user()));
}

void administrator_choose::come_back_7()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->change_time_or_group->show();
    ui->number_of_members->show();
    ui->write_off_the_workout->show();
    ui->check_status->show();
    ui->add_trains->show();
    ui->delete_or_block_card->show();
    ui->add_user->show();
    ui->add_user->blockSignals(false);
    back->hide();
    delete back;
    answer->hide();
    delete answer;
    appear->hide();
    delete appear;
    first_name->hide();
    delete first_name;
    last_name->hide();
    delete last_name;
    middle_name->hide();
    delete middle_name;
    passport_seria->hide();
    delete passport_seria;
    passport_number->hide();
    delete passport_number;
    choose_benefits->hide();
    delete choose_benefits;
    choose_marks->hide();
    delete choose_marks;
}

void administrator_choose::add_user()
{
    QString f_name = first_name->text();
    QString l_name = last_name->text();
    QString m_name = middle_name->text();
    QString d_of_birth = date_of_birth->text();
    QString p_seria = passport_seria->text();
    QString p_number = passport_number->text();
    QString benefits = choose_benefits->currentText();
    QString marks = choose_marks->currentText();
    QString ben_id;
    QString mark_id;
    if(benefits !="Нет")
    {
        QSqlQuery ben;
        ben.exec("SELECT id_benefit FROM benefits WHERE NAME = \'"+benefits+"\'");
        ben.next();
        ben_id = ben.value(0).toString();
    }
    else
    {
        ben_id = "NULL";
    }
    if(marks !="Нет")
    {
        QSqlQuery mark;
        mark.exec("SELECT id_mark FROM marks WHERE NAME = \'"+marks+"\'");
        mark.next();
        mark_id = mark.value(0).toString();
    }
    else
    {
        mark_id = "NULL";
    }
    QSqlQuery vvod;
    vvod.exec("INSERT INTO users (first_name, last_name, middle_name, date_of_birth, passport_seria, passport_number, benefitss, marks) "
              "VALUES(\'"+f_name+"\',\'"+l_name+"\', \'"+m_name+"\', "
              "\'"+d_of_birth+"\', \'"+p_seria+"\', \'"+p_number+"\', \'"+ben_id+"\', \'"+mark_id+"\');");
    answer->setText("Пользователь успешно добавлен!");
    ui->gridLayout->addWidget(answer, 6, 1);
}
