#include "size_window.h"

size_window::size_window(QWidget* parent, int mode) : QWidget(parent)
{
    this->mode = mode;
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Ввод размера поля");
    QPalette pal;
    pal.setColor(QPalette::Background, QColor(0, 200, 100, 255));
    this->setPalette(pal);
    size_field_x = create_label("Размер поля по x:", WINDOW_SIZE.width() - 480, WINDOW_SIZE.height() - 350);
    size_Field_x = create_spin_box(1, 10, WINDOW_SIZE.width() - 200, WINDOW_SIZE.height() - 350);
    size_field_y = create_label("Размер поля по y:", WINDOW_SIZE.width() - 480, WINDOW_SIZE.height() - 300);
    size_Field_y = create_spin_box(1, 10, WINDOW_SIZE.width() - 200, WINDOW_SIZE.height() - 300);
    next_button = new QPushButton("Далее", this);
    next_button->resize(BUTTON_SIZE);
    next_button->move(WINDOW_SIZE.width() - 400, WINDOW_SIZE.height() - 200);
    connect(next_button, SIGNAL(clicked()), SLOT(print_field()));
    back_button = new QPushButton("Назад", this);
    back_button->resize(BUTTON_SIZE);
    back_button->move(WINDOW_SIZE.width() - 400, WINDOW_SIZE.height() - 150);
    connect(back_button, SIGNAL(clicked()), SLOT(close_size_window()));
}

void size_window::print_field()
{
    a.initialize_settings(f,size_Field_x->value(),size_Field_y->value());
    if (mode == 1){
        a.initialize_field(f);
    }else{
        for (int i = 0; i < f.get_x(); i++){
            for (int j = 0; j < f.get_y(); j++){
                initialize_window* init = new initialize_window(this, &a, &f, i, j);
                init->exec();
                delete init;
            }
        }
    }
    field_window* field = new field_window(0,a,f);
    field->show();
    this->close();
}

QLabel *size_window::create_label(QString text, int coordinate_x, int coordinate_y)
{
    QLabel* label = new QLabel(this);
    label->move(coordinate_x, coordinate_y);
    label->setText(text);
    label->show();
    return label;
}

QSpinBox* size_window::create_spin_box(int min, int max, int coordinate_x, int coordinate_y)
{
    QSpinBox* spin_box = new QSpinBox(this);
    spin_box->setRange(min, max);
    spin_box->move(coordinate_x, coordinate_y);
    spin_box->show();
    return spin_box;
}

void size_window::close_size_window()
{
    MainWindow* w = new MainWindow(0);
    w->show();
    this->close();
}
