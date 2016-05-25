#ifndef EXIT_WINDOW_H
#define EXIT_WINDOW_H

#include <QPushButton>
#include <QLabel>
#include "mainwindow.h"
#include <QtWidgets>


class exit_window : public QDialog
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 300, 90 };
    const QSize BUTTON_SIZE { 120, 30 };
    QPushButton* yes_button;
    QPushButton* no_button;
    QWidget* parent;
    QLabel* exit_label;
public:
    explicit exit_window(QWidget* parent);
private slots:
    void close_app();
    void close_exit_window();
};

#endif // EXIT_WINDOW_H
