#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(WINDOW_SIZE);
    this->setWindowTitle("Жизнь");
    QPixmap background(":4065.jpg");
    QPalette pal;
    pal.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(pal);
    new_model_button = new QPushButton("Создать новую модель", this);
    new_model_button->resize(BUTTON_SIZE);
    new_model_button->move(WINDOW_SIZE.width() - 400,WINDOW_SIZE.height() - 400);
    connect(new_model_button, SIGNAL(clicked()), SLOT(create_model()));
    exit_button = new QPushButton("Выход", this);
    exit_button->resize(BUTTON_SIZE);
    exit_button->move(WINDOW_SIZE.width() - 400, WINDOW_SIZE.height() - 150);
    connect(exit_button, SIGNAL(clicked()), SLOT(close_menu()));
}

void MainWindow::close_menu()
{
    exit_window* exit_menu = new exit_window(this);
    exit_menu->exec();
    delete exit_menu;
}

void MainWindow::create_model()
{
    size_window* size_menu = new size_window(0);
    size_menu->show();
    this->close();
}
