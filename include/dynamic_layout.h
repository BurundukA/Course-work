//! @file dynamic_layout
//! @authors Бордукова А.А.
//! @brief Заголовок для системно-служебного функционала.
#ifndef DYNAMIC_LAYOUT_H
#define DYNAMIC_LAYOUT_H

#include <QAbstractItemModel>
#include <QLabel>

class dynamic_layout : public QLabel
{
    Q_OBJECT

public:
    explicit dynamic_layout(QWidget *parent = nullptr);
    ~dynamic_layout();

private:
};

#endif // DYNAMIC_LAYOUT_H
