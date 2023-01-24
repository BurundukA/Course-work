//! @file mainwindow
//! @authors Бордукова А.А.
//! @brief Головной заголовок для системно-служебного функционала.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include "autorization.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //! @brief Создание формы главного окна
    ~MainWindow();
    //! @brief Удаление формы главного окна

private slots:
    void on_pushButton_clicked();
    //! @brief Выбор типа "Посетитель"
    void on_pushButton_3_clicked();
    //! @brief Выбор типа "Тренер"
    void on_pushButton_2_clicked();
    //! @brief Выбор типа "АДминистратор"

signals:
    void signal(QString a);
    //! @brief Передача типа выбранной учтёной записи

private:
    Ui::MainWindow *ui;
    Autorization *forusers;
    //!< Вызываемая форма

};
#endif // MAINWINDOW_H
