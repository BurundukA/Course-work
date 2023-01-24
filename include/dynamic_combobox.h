//! @file dynamic_combobox
//! @authors Бордукова А.А.
//! @brief Заголовок для системно-служебного функционала.
#ifndef DYNAMIC_COMBOBOX_H
#define DYNAMIC_COMBOBOX_H

#include <QAbstractItemModel>
#include <QComboBox>

class dynamic_combobox: public QComboBox
{
    Q_OBJECT

public:
    explicit dynamic_combobox(QWidget *parent = nullptr);
    ~dynamic_combobox();

private:
};

#endif // DYNAMIC_COMBOBOX_H
