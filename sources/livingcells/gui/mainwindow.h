#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QInputDialog>
#include "size_window.h"
#include "exit_window.h"
#include "figure_window.h"
#include "field.h"
#include "api.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 300, 30 };
    QPushButton* new_random_model_button;
    QPushButton* load_button;
    QPushButton* figure_button;
    QPushButton* new_model_button;
    QPushButton* exit_button;
public:
    MainWindow(QWidget *parent);
private slots:
    void figure_menu();
    void close_menu();
    void create_model_random();
    void create_model();
    void load_model();
};

#endif // MAINWINDOW_H
