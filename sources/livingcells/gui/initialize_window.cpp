#include "initialize_window.h"

initialize_window::initialize_window(QWidget *parent, Api *a, Field *f, int i, int j) : QDialog(parent)
{
    this->parent = parent;
    this->f = f;
    this->a = a;
    this->x = i;
    this->y = j;
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Выбор состояния клетки");
    QPixmap background(":/4065.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);
    status_cell =  new QLabel(this);
    status_cell->move(WINDOW_SIZE.width() - 325, WINDOW_SIZE.height()  - 160);
    status_cell->setText(QString("Введите состояние клетки %1 строки, %2 столбца").arg(y+1).arg(x+1));
    status_cell->show();
    live_button = new QPushButton("Живая", this);
    live_button->resize(BUTTON_SIZE);
    live_button->move(WINDOW_SIZE.width() - 275, WINDOW_SIZE.height() - 50);
    connect(live_button, SIGNAL(clicked()), SLOT(clicked_button_live()));
    dead_button = new QPushButton("Мёртвая", this);
    dead_button->resize(BUTTON_SIZE);
    dead_button->move(WINDOW_SIZE.width() - 275, WINDOW_SIZE.height() - 100);
    connect(dead_button, SIGNAL(clicked()), SLOT(clicked_button_dead()));
}

void initialize_window::clicked_button_live()
{
    a->set_cell(*f,x,y,"L");
    this->close();
}

void initialize_window::clicked_button_dead()
{
    a->set_cell(*f,x,y,"D");
    this->close();
}
