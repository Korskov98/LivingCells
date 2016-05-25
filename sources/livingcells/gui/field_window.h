#ifndef FIELD_WINDOW_H
#define FIELD_WINDOW_H

#include <QWidget>
#include "mainwindow.h"
#include "api.h"
#include "field.h"

class field_window : public QWidget
{
    Q_OBJECT

    QWidget* parent;
    Api a;
    Field f;
    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 200, 30 };
    const QSize CELL_SIZE { 50, 50 };
    QPushButton* next_generation_button;
    QPushButton* back_button;
public:
    field_window(QWidget* parent,Api a,Field f);
    void print_field();
private slots:
    void next_generation();
    void back_in_main_menu();
};

#endif // FIELD_WINDOW_H
