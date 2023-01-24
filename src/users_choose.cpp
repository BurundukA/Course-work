#include "users_choose.h"
#include "ui_users_choose.h"
#include <QMessageBox>
#include <QLabel>
#include <QStatusBar>

users_choose::users_choose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::users_choose)
{
    ui->setupUi(this);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    //connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    //connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));
    this->setWindowTitle("Выбор посетителя");
}

users_choose::~users_choose()
{
    delete ui;
}
void users_choose::get_id(QString id)
{
    id_user = id;
    //qDebug()<<id_user;
}

void users_choose::on_pushButton_clicked()
{
    appear = new Dinamic_Items(this);
    back = new Dinamic_Items(this);
    vvod = new dynamic_item(this);
    vvod->setText("Введите фамилию тренера");
    appear->setText("Найти");
    back->setText("Назад");
    ui->pushButton_2->hide();
    ui->number_of_visits->hide();
    ui->time_limits->hide();
    ui->pushButton->blockSignals(true);
    answer = new dynamic_layout();
    /*QGridLayout *l = new QGridLayout();
    l->addWidget(appear, 0, 1);
    l->addWidget(vvod, 0, 0);
    ui->horizontalLayout->addLayout(l);*/
    ui->gridLayout->addWidget(back, 0, 2);
    ui->gridLayout->addWidget(vvod, 2, 1);
    ui->gridLayout->addWidget(appear, 2, 2);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back()));
    connect(appear, SIGNAL(clicked()), this, SLOT(get_trainer()));
}

void users_choose::get_trainer()
{
    QString surname = vvod->text();
    QSqlQuery trainer;
    if (trainer.exec("SELECT * FROM trainers WHERE last_name = \'"+ surname+"\'"))
    {
        if(trainer.next())
        {
            answer->setText(trainer.value(2).toString() + "\n"+
                          trainer.value(1).toString()+ "\n"+
                          trainer.value(3).toString()+ "\n"+
                          trainer.value(4).toString()+ "\n"+
                          trainer.value(5).toString());
            ui->gridLayout->addWidget(answer, 3, 1);
        }
        else
            QMessageBox::information(this, "Ошибка","Фамилия тренера введена с ошибкой!");
    }
}


void users_choose::on_pushButton_3_clicked()
{
    this->close();
    emit return_to_autorization();
}
void users_choose::come_back()
{
    //qDebug()<< "ergrejiy9w";
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->number_of_visits->show();
    ui->time_limits->show();
    ui->pushButton->blockSignals(false);
    appear->hide();
    delete appear;
    vvod->hide();
    delete vvod;
    back->hide();
    delete back;
    answer->hide();
    delete answer;
   // ui->gridLayout->addWidget(ui->pushButton, 1, 1);
    //ui->gridLayout->addWidget(ui->pushButton_2, 2, 1);
}


void users_choose::on_pushButton_2_clicked()
{
    appear = new Dinamic_Items(this);
    back = new Dinamic_Items(this);
    first_name = new dynamic_item(this);
    last_name = new dynamic_item(this);
    middle_name = new dynamic_item(this);
    date_of_birth= new dynamic_item(this);
    answer = new dynamic_layout();
    QSqlQuery person;
    //qDebug()<<id_user;
    person.exec("SELECT first_name, last_name, middle_name, date_of_birth FROM users WHERE id_user = \'" +id_user+ "\'");
    person.next();
    first_name->setText(person.value(0).toString());
    last_name->setText(person.value(1).toString());
    middle_name->setText(person.value(2).toString());
    date_of_birth->setText(person.value(3).toString());
    appear->setText("Изменить");
    back->setText("Назад");
    ui->pushButton->hide();
    ui->number_of_visits->hide();
    ui->time_limits->hide();
    ui->pushButton_2->blockSignals(true);
    ui->gridLayout->addWidget(back, 0, 2);
    ui->gridLayout->addWidget(first_name, 2, 1);
    ui->gridLayout->addWidget(last_name, 3, 1);
    ui->gridLayout->addWidget(middle_name, 4, 1);
    ui->gridLayout->addWidget(date_of_birth, 5, 1);
    ui->gridLayout->addWidget(appear, 5, 2);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_1()));
    connect(appear, SIGNAL(clicked()), this, SLOT(change_personal_data()));
}

void users_choose::come_back_1()
{
    //qDebug()<< "ergrejiy9w";
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->number_of_visits->show();
    ui->time_limits->show();
    ui->pushButton_2->blockSignals(false);
    first_name->hide();
    delete first_name;
    last_name->hide();
    delete last_name;
    middle_name->hide();
    delete middle_name;
    date_of_birth->hide();
    delete date_of_birth;
    appear->hide();
    delete appear;
    back->hide();
    delete back;
    answer->hide();
    delete answer;
}

void users_choose::change_personal_data()
{
    QString f_name = first_name->text();
    QString l_name = last_name->text();
    QString m_name = middle_name->text();
    QString d_of_birth = date_of_birth->text();
    QSqlQuery vvod;
    //qDebug()<<d_of_birth <<id_user;
    QSqlQuery query;
   vvod.exec("UPDATE users SET first_name = \'" + f_name +
                 "\' ,last_name = \'" + l_name +
                 "\', middle_name = \'" + m_name+
             "\', date_of_birth = \'" + d_of_birth+
                 "\' WHERE id_user = \'"+id_user+"\'");
   answer->setText("Данныке успешно обновлены!");
   ui->gridLayout->addWidget(answer, 6, 1);

}


void users_choose::on_number_of_visits_clicked()
{
    back = new Dinamic_Items(this);
    back->setText("Назад");
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->time_limits->hide();
    ui->number_of_visits->blockSignals(true);
    answer = new dynamic_layout();
    QString data;
    ui->gridLayout->addWidget(back, 0, 2);
    QSqlQuery trains;
    int row =2;
    int column = 1;
    trains.exec("SELECT train, count FROM cards WHERE id_card = \'" + id_user+ "\'");
    while (trains.next()) {
            data.append(trains.value(0).toString());
            data.append("->");
            data.append(trains.value(1).toString());
            data.append("\n");
        }
    //qDebug()<<data;
    answer->setText(data);
    ui->gridLayout->addWidget(answer, 4 ,1);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_2()));
}

void users_choose::come_back_2()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->time_limits->show();
    ui->number_of_visits->show();
    ui->number_of_visits->blockSignals(false);
    ui->time_limits->blockSignals(false);
    back->hide();
    delete back;
    answer->hide();
    delete answer;
}



void users_choose::on_time_limits_clicked()
{
    back = new Dinamic_Items(this);
    back->setText("Назад");
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->number_of_visits->hide();
    ui->time_limits->blockSignals(true);
    answer = new dynamic_layout();
    QString data;
    ui->gridLayout->addWidget(back, 0, 2);
    QSqlQuery trains;
    int row =2;
    int column = 1;
    trains.exec("SELECT train, time_limits FROM cards WHERE id_card = \'" + id_user+ "\'");
    while (trains.next()) {
            data.append(trains.value(0).toString());
            data.append("->");
            data.append(trains.value(1).toString());
            data.append("\n");
        }
    //qDebug()<<data;
    answer->setText(data);
    ui->gridLayout->addWidget(answer, 5 ,1);
    connect(back, SIGNAL(clicked()), this, SLOT(come_back_2()));
}

void users_choose::come_back_3()
{
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->number_of_visits->show();
    ui->time_limits->show();
    back->hide();
    delete back;
    answer->hide();
    delete answer;
}

