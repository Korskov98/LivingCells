#include "figure_window.h"

figure_window::figure_window(QWidget* parent) : QDialog(parent)
{
    this->parent = parent;
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Выбор фигуры");
    QPalette pal;
    pal.setColor(QPalette::Background, QColor(0, 200, 100, 255));
    this->setPalette(pal);
    figure_label =  new QLabel(this);
    figure_label->move(WINDOW_SIZE.width() - 283, WINDOW_SIZE.height()  - 380);
    figure_label->setText("Выберете фигуру");
    figure_label->show();
    glider_button = new QPushButton("Глайдер", this);
    glider_button->resize(BUTTON_SIZE);
    glider_button->move(WINDOW_SIZE.width() - 300, WINDOW_SIZE.height() - 350);
    connect(glider_button, SIGNAL(clicked()), SLOT(create_glider()));
    spaceship_button = new QPushButton("Космический корабль", this);
    spaceship_button->resize(BUTTON_SIZE);
    spaceship_button->move(WINDOW_SIZE.width() - 300, WINDOW_SIZE.height() - 300);
    connect(spaceship_button, SIGNAL(clicked()), SLOT(create_spaceship()));
}

void figure_window::create_spaceship()
{
    a.initialize_settings(f,10,10);
    a.set_cell(f,0,0,"L");
    a.set_cell(f,0,1,"D");
    a.set_cell(f,0,2,"L");
    for (int i = 3; i < 10; i++){
        a.set_cell(f,0,i,"D");
    }
    for (int i = 0; i < 3; i++){
        a.set_cell(f,1,i,"D");
    }
    a.set_cell(f,1,3,"L");
    for (int i = 4; i < 10; i++){
        a.set_cell(f,1,i,"D");
    }
    for (int i = 0; i < 3; i++){
        a.set_cell(f,2,i,"D");
    }
    a.set_cell(f,2,3,"L");
    for (int i = 4; i < 10; i++){
        a.set_cell(f,2,i,"D");
    }
    a.set_cell(f,3,0,"L");
    a.set_cell(f,3,1,"D");
    a.set_cell(f,3,2,"D");
    a.set_cell(f,3,3,"L");
    for (int i = 4; i < 10; i++){
        a.set_cell(f,3,i,"D");
    }
    a.set_cell(f,4,0,"D");
    a.set_cell(f,4,1,"L");
    a.set_cell(f,4,2,"L");
    a.set_cell(f,4,3,"L");
    for (int i = 4; i < 10; i++){
        a.set_cell(f,4,i,"D");
    }
    for (int i = 5; i < 10; i++){
        for (int j = 0; j < 10; j++){
            a.set_cell(f,i,j,"D");
        }
    }
    field_window* field = new field_window(0,a,f);
    field->show();
    this->close();
    this->parent->close();
}

void figure_window::create_glider()
{
    a.initialize_settings(f,10,10);
    a.set_cell(f,0,0,"L");
    for (int i = 1; i < 10; i++){
        a.set_cell(f,0,i,"D");
    }
    a.set_cell(f,1,0,"D");
    a.set_cell(f,1,1,"L");
    a.set_cell(f,1,2,"L");
    for (int i = 3; i < 10; i++){
        a.set_cell(f,1,i,"D");
    }
    a.set_cell(f,2,0,"L");
    a.set_cell(f,2,1,"L");
    for (int i = 2; i < 10; i++){
        a.set_cell(f,2,i,"D");
    }
    for (int i = 3; i < 10; i++){
        for (int j = 0; j < 10; j++){
            a.set_cell(f,i,j,"D");
        }
    }
    field_window* field = new field_window(0,a,f);
    field->show();
    this->close();
    this->parent->close();
}

