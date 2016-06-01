#ifndef API_H
#define API_H
#include "field.h"
#include "string"

/**
  @brief Класс Api

  Этот класс предоставляет методы ядра.
  */

class Api
{
public:
    /**
     * @brief Задать размеры поля
     * @param f поле
     * @param f_x размер поля по оси x
     * @param f_y размер поля по оси y
     */
    void initialize_settings(Field &f, int f_x, int f_y);
    /**
     * @brief Инициализировать поле случайными клетками
     * @param f поле
     */
    void initialize_field(Field &f);
    /**
     * @brief Сохранить поле в файл
     * @param f поле
     */
    void save_field(Field &f);
    /**
     * @brief Загрузить поле из файла
     * @param f поле
     */
    void load_field(Field &f);
    /**
     * @brief Вывести поле в консоль
     * @param f поле
     */
    void print_field(Field &f);
    /**
     * @brief Сменить поколение и изменить поле
     * @param f поле
     */
    void change_field(Field &f);
    /**
     * @brief Задать клетку поля
     * @param f поле
     * @param x координата клетки по оси x
     * @param y координата клетки по оси y
     * @param status статус клетки
     */
    void set_cell(Field &f, int x, int y, std::string status);
};

#endif // API_H
