#ifndef FIGURE_WINDOW_H
#define FIGURE_WINDOW_H

#include <QPushButton>
#include <QLabel>
#include "mainwindow.h"
#include "api.h"
#include "field.h"
#include <QtWidgets>

class figure_window : public QDialog
{
    Q_OBJECT

    Api a;
    Field f;
    const QSize WINDOW_SIZE { 430, 430 };
    const QSize BUTTON_SIZE { 160, 30 };
    QPushButton* glider_button;
    QPushButton* spaceship_button;
    QWidget* parent;
    QLabel* figure_label;
public:
    explicit figure_window(QWidget* parent);
private slots:
    void create_spaceship();
    void create_glider();
};

#endif // FIGURE_WINDOW_H
