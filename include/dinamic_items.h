//! @file dinamic_items
//! @authors Бордукова А.А.
//! @brief Заголовок для системно-служебного функционала.
#ifndef DINAMIC_ITEMS_H
#define DINAMIC_ITEMS_H

#include <QAbstractItemModel>
#include <QPushButton>

class Dinamic_Items : public QPushButton
{
    Q_OBJECT

public:
    explicit Dinamic_Items(QWidget *parent = nullptr);
    ~Dinamic_Items();

private:
};

#endif // DINAMIC_ITEMS_H
