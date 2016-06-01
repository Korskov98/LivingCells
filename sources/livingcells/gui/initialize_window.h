#ifndef INITIALIZE_WINDOW_H
#define INITIALIZE_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QtWidgets>
#include "api.h"
#include "field.h"

class initialize_window : public QDialog
{
    Q_OBJECT

    QWidget* parent;
    Api* a;
    Field* f;
    int x;
    int y;
    const QSize WINDOW_SIZE { 430, 220 };
    const QSize BUTTON_SIZE { 200, 30 };
    QLabel* status_cell;
    QPushButton* live_button;
    QPushButton* dead_button;
public:
    explicit initialize_window(QWidget* parent, Api* a, Field* f, int i, int j);
private slots:
    void clicked_button_live();
    void clicked_button_dead();
};

#endif // INITIALIZE_WINDOW_H
