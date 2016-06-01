#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H
#include "api.h"
#include "field.h"

/**
  @brief Класс консольного меню

  Этот класс, посредством консоли, взаимодействует с пользователем.
  */

class console_ui
{
public:
    /**
     * @brief Вывести главное меню
     */
    void print_menu();
    /**
     * @brief Вывести промежуточное меню
     * @param f поле
     * @param a объект класса Api
     */
    void secondary_menu(Field &f, Api a);
    /**
     * @brief Вывести меню задания клеток поля
     * @param f поле
     * @param a объект класса Api
     * @param x размер поля по оси x
     * @param y размер поля по оси y
     */
    void input_menu(Field &f, Api a, int x, int y);
};

#endif // CONSOLE_UI_H
