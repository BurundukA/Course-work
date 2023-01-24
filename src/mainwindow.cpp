#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    forusers = new Autorization();
    connect(this, &MainWindow::signal, forusers, &Autorization::slot);
    connect(forusers,&Autorization::return_to_main_window, this, &MainWindow::show);
    this->setWindowTitle("Выбор пользователя");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   forusers->show();
   emit signal("users_accounts");
   this->close();
}


void MainWindow::on_pushButton_3_clicked()
{
    forusers->show();
    emit signal("trainers_accounts");
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    forusers->show();
    emit signal("administrator_accounts");
    this->close();
}

