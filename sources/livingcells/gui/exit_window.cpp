#include "exit_window.h"

exit_window::exit_window(QWidget* parent) : QDialog(parent)
{
    this->parent = parent;
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Подтверждение выхода");
    QPixmap background(":/4065.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);
    exit_label =  new QLabel(this);
    exit_label->move(WINDOW_SIZE.width() - 283, WINDOW_SIZE.height()  - 80);
    exit_label->setText("Вы действительно хотите выйти?");
    exit_label->show();
    yes_button = new QPushButton("Да", this);
    yes_button->resize(BUTTON_SIZE);
    yes_button->move(WINDOW_SIZE.width() - 275, WINDOW_SIZE.height() - 50);
    connect(yes_button, SIGNAL(clicked()), SLOT(close_app()));
    no_button = new QPushButton("Нет", this);
    no_button->resize(BUTTON_SIZE);
    no_button->move(WINDOW_SIZE.width() - 125, WINDOW_SIZE.height() - 50);
    connect(no_button, SIGNAL(clicked()), SLOT(close_exit_window()));
}

void exit_window::close_app()
{
    this->close();
    this->parent->close();
}

void exit_window::close_exit_window()
{
    this->close();
}
