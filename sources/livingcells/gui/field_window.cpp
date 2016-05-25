#include "field_window.h"

field_window::field_window(QWidget *parent, Api a, Field f) : QWidget(parent)
{
    this->a = a;
    this->f = f;
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Поле");
    QPixmap background(":/4065.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);
    this->print_field();
    next_generation_button = new QPushButton("Следующее поколение", this);
    next_generation_button->resize(BUTTON_SIZE);
    next_generation_button->move(WINDOW_SIZE.width() - 400, WINDOW_SIZE.height() - 150);
    connect(next_generation_button, SIGNAL(clicked()), SLOT(next_generation()));
    back_button = new QPushButton("Назад в главное меню", this);
    back_button->resize(BUTTON_SIZE);
    back_button->move(WINDOW_SIZE.width() - 400, WINDOW_SIZE.height() - 100);
    connect(back_button, SIGNAL(clicked()), SLOT(back_in_main_menu()));
}

void field_window::print_field()
{
    for (int i = 0; i < f.get_x(); i++){
        for (int j = 0; j < f.get_y(); j++){
            Cell c = f.get_cell(i,j);
            bool status = c.get_status();
            if (status == 0){
                QPushButton* cell = new QPushButton("D",this);
                cell->resize(CELL_SIZE);
                cell->move(WINDOW_SIZE.width() - 450+(60*i), WINDOW_SIZE.height() - 450+(60*j));
            }else{
                QPushButton* cell = new QPushButton("L",this);
                cell->resize(CELL_SIZE);
                cell->move(WINDOW_SIZE.width() - 450+(60*i), WINDOW_SIZE.height() - 450+(60*j));
            }
        }
    }
}

void field_window::next_generation()
{
    a.change_field(f);
    field_window* field = new field_window(0,a,f);
    field->show();
    this->close();
}

void field_window::back_in_main_menu()
{
    MainWindow* w = new MainWindow(0);
    w->show();
    this->close();
}

