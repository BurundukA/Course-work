//! @file dynamic_item
//! @authors Бордукова А.А.
//! @brief Заголовок для системно-служебного функционала.
#ifndef DYNAMIC_ITEM_H
#define DYNAMIC_ITEM_H

#include <QAbstractItemModel>
#include<QLineEdit>

class dynamic_item : public QLineEdit
{
    Q_OBJECT

public:
    explicit dynamic_item(QWidget *parent = nullptr);
    ~dynamic_item();

private:
};

#endif // DYNAMIC_ITEM_H
