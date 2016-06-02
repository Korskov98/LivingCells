#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Жизнь");
    QPalette pal;
    pal.setColor(QPalette::Background, QColor(0, 200, 100, 255));
    this->setPalette(pal);
    new_random_model_button = new QPushButton("Создать новую случайную модель", this);
    new_random_model_button->resize(BUTTON_SIZE);
    new_random_model_button->move(WINDOW_SIZE.width() - 450,WINDOW_SIZE.height() - 400);
    connect(new_random_model_button, SIGNAL(clicked()), SLOT(create_model_random()));
    load_button = new QPushButton("Загрузить модель", this);
    load_button->resize(BUTTON_SIZE);
    load_button->move(WINDOW_SIZE.width() - 450,WINDOW_SIZE.height() - 300);
    connect(load_button, SIGNAL(clicked()), SLOT(load_model()));
    new_model_button = new QPushButton("Создать новую модель вручную", this);
    new_model_button->resize(BUTTON_SIZE);
    new_model_button->move(WINDOW_SIZE.width() - 450,WINDOW_SIZE.height() - 350);
    connect(new_model_button, SIGNAL(clicked()), SLOT(create_model()));
    figure_button = new QPushButton("Сделать модель с фигурой", this);
    figure_button->resize(BUTTON_SIZE);
    figure_button->move(WINDOW_SIZE.width() - 450,WINDOW_SIZE.height() - 250);
    connect(figure_button, SIGNAL(clicked()), SLOT(figure_menu()));
    exit_button = new QPushButton("Выход", this);
    exit_button->resize(BUTTON_SIZE);
    exit_button->move(WINDOW_SIZE.width() - 450, WINDOW_SIZE.height() - 150);
    connect(exit_button, SIGNAL(clicked()), SLOT(close_menu()));
}

void MainWindow::figure_menu()
{
    figure_window* figure = new figure_window(this);
    figure->exec();
    delete figure;
}

void MainWindow::close_menu()
{
    exit_window* exit_menu = new exit_window(this);
    exit_menu->exec();
    delete exit_menu;
}

void MainWindow::create_model_random()
{
    size_window* size_menu = new size_window(0,1);
    size_menu->show();
    this->close();
}

void MainWindow::create_model()
{
    size_window* size_menu = new size_window(0,2);
    size_menu->show();
    this->close();
}

void MainWindow::load_model()
{
    Api a;
    Field f;
    a.load_field(f);
    field_window* field = new field_window(0,a,f);
    field->show();
    this->close();
}
