#ifndef SIZE_WINDOW_H
#define SIZE_WINDOW_H

#include <QLabel>
#include <QSpinBox>
#include "mainwindow.h"
#include "field_window.h"
#include "field.h"
#include "api.h"
#include "initialize_window.h"

class size_window : public QWidget
{
    Q_OBJECT

    QWidget* parent;
    Api a;
    Field f;
    int mode;
    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 200, 30 };
    QPushButton* next_button;
    QPushButton* back_button;
    QLabel* size_field_x;
    QLabel* size_field_y;
    QSpinBox* size_Field_x;
    QSpinBox* size_Field_y;
    QLabel* create_label(QString text, int coordinate_x, int coordinate_y);
    QSpinBox* create_spin_box(int min, int max, int coordinate_x, int coordinate_y);
public:
    size_window(QWidget* parent, int mode);
private slots:   
    void print_field();
    void close_size_window();
};

#endif // SIZE_WINDOW_H
