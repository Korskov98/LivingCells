#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QInputDialog>
#include "size_window.h"
#include "exit_window.h"
#include "field.h"
#include "api.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 660, 540 };
    const QSize BUTTON_SIZE { 180, 30 };
    QPushButton* new_model_button;
    QPushButton* exit_button;
public:
    MainWindow(QWidget *parent);
private slots:
    void close_menu();
    void create_model();
};

#endif // MAINWINDOW_H
