#include "autorization.h"
#include "qsqlquery.h"
#include "ui_autorization.h"



Autorization::Autorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Autorization)
{
    ui->setupUi(this);
    us_choose = new users_choose();
    tr_choose = new trainers_choose();
    ad_choose = new administrator_choose();
    connect(us_choose,&users_choose::return_to_autorization, this, &Autorization::show);
    connect(this, &Autorization::pass_id, us_choose, &users_choose::get_id);
    connect(tr_choose,&trainers_choose::return_to_autorization, this, &Autorization::show);
    connect(this, &Autorization::pass_id, tr_choose, &trainers_choose::get_id);
    connect(ad_choose,&administrator_choose::return_to_autorization, this, &Autorization::show);
    connect(this, &Autorization::pass_id, ad_choose, &administrator_choose::get_id);
    this->setWindowTitle("Авторизация");
}


Autorization::~Autorization()
{
    delete ui;
}

void Autorization::on_pushButton_clicked()
{
    //qDebug()<<user_type;
    if(user_type == "users_accounts")
    {
   QString login = ui->login->text();
   QString password = ui->password->text();
   //qDebug()<<user_type;
       QSqlQuery qry;
       if (qry.exec("SELECT login, password FROM \'" + user_type + "\'WHERE login=\'" + login +
                    "\' AND password=\'" + password + "\'"))
       {
           if (qry.next()) {
               {
              us_choose->show();
              QSqlQuery get_id;
              get_id.exec("SELECT id_user FROM \'" + user_type + "\'WHERE login=\'" + login +
                                  "\' AND password=\'" + password + "\'");
              get_id.next();
              //qDebug()<<get_id.value(0).toString();
             QString id = get_id.value(0).toString();
               emit pass_id(id);
              this->close();
               }
           }
           else {
               //qDebug()<<qry.value(0).toString();
               QMessageBox::information(this, "Ошибка","Неверный логин пользователся или пароль!");
           }
       }
       else {
           QMessageBox::information(this, "Опибка","Неверный логин пользователся или пароль!!!");
       }
    }
    if(user_type == "trainers_accounts")
    {
   QString login = ui->login->text();
   QString password = ui->password->text();
   //qDebug()<<user_type;
       QSqlQuery qry;
       if (qry.exec("SELECT login, password FROM \'" + user_type + "\'WHERE login=\'" + login +
                    "\' AND password=\'" + password + "\'"))
       {
           if (qry.next()) {
              // qDebug()<<qry.value(0).toString();
              tr_choose->show();
              QSqlQuery get_id;
              get_id.exec("SELECT id_trainer FROM \'" + user_type + "\'WHERE login=\'" + login +
                                  "\' AND password=\'" + password + "\'");
              get_id.next();
              //qDebug()<<get_id.value(0).toString();
             QString id = get_id.value(0).toString();
             //qDebug()<<id;
               emit pass_id(id);
              this->close();
           }
           else {
               QMessageBox::information(this, "Ошибка","Неверный логин пользователся или пароль!");
           }
       }
       else {
           QMessageBox::information(this, "Опибка","Неверный логин пользователся или пароль!");
       }
    }
    if(user_type == "administrator_accounts")
    {
        QString u_type = "trainers_accounts";
   QString login = ui->login->text();
   QString password = ui->password->text();
   //qDebug()<<user_type;
       QSqlQuery qry;
       if (qry.exec("SELECT login, password FROM \'" + u_type + "\'WHERE login=\'" + login +
                    "\' AND password=\'" + password + "\'"))
       {
           if (qry.next()) {
              // qDebug()<<qry.value(0).toString();
              ad_choose->show();
              QSqlQuery get_id;
              get_id.exec("SELECT id_trainer FROM \'" + u_type + "\'WHERE login=\'" + login +
                                  "\' AND password=\'" + password + "\'");
              get_id.next();
              //qDebug()<<get_id.value(0).toString();
             QString id = get_id.value(0).toString();
             //qDebug()<<id;
               emit pass_id(id);
              this->close();
           }
           else {
               QMessageBox::information(this, "Ошибка","Неверный логин пользователся или пароль!");
           }
       }
       else {
           QMessageBox::information(this, "Опибка","Неверный логин пользователся или пароль!");
       }
    }
}

void Autorization::slot(QString a)
{
    user_type = a;
}


void Autorization::on_pushButton_3_clicked()
{
    this->close();
    emit return_to_main_window();
}

