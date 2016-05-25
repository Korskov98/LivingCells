#include "size_window.h"

size_window::size_window(QWidget* parent) : QWidget(parent)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Ввод размера поля");
    QPixmap background(":/4065.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);
    size_field_x = create_label("Размер поля по x:", WINDOW_SIZE.width() - 480, WINDOW_SIZE.height() - 350);
    size_Field_x = create_spin_box(1, 6, WINDOW_SIZE.width() - 200, WINDOW_SIZE.height() - 350);
    size_field_y = create_label("Размер поля по y:", WINDOW_SIZE.width() - 480, WINDOW_SIZE.height() - 300);
    size_Field_y = create_spin_box(1, 5, WINDOW_SIZE.width() - 200, WINDOW_SIZE.height() - 300);
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
    a.initialize_field(f);
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
