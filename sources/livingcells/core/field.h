#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include <vector>

/**
  @brief Класс Поле

  Этот класс моделирует объект поле на котором располагаются клетки.
  */

class Field
{
public:
    /**
     * @brief Конструктор
     * @param a размер поля по оси x
     * @param b размер поля по оси y
     */
    Field(const int a = 0, const int b = 0): x(a), y(b) {
        cells.resize(x);
        for (int i = 0; i < x; ++i){
            cells[i].resize(y);
        }
    }
    /**
     * @brief Получить размер поля по оси x
     * @return размер поля по оси x
     */
    int get_x() {return x;}
    /**
     * @brief Получить размер поля по оси y
     * @return размер поля по оси y
     */
    int get_y() {return y;}
    /**
     * @brief Получить клетку из поля
     * @param x_cell координата клетки по x
     * @param y_cell координата клетки по y
     * @return клетки из поля
     */
    Cell get_cell(const int x_cell, const int y_cell) {return cells[x_cell][y_cell];}
    /**
     * @brief Получить все клетки поля
     * @return двумерный массив клеток
     */
    std::vector<std::vector<Cell> > get_cells() {return cells;}
    /**
     * @brief Установить значение поля x, равное размеру поля по оси x
     * @param a размер поля по оси x
     */
    void set_x(const int a);
    /**
     * @brief Установить значение поля y, равное размеру поля по оси y
     * @param b размер поля по оси y
     */
    void set_y(const int b);
    /**
     * @brief Задать данные новой клетки
     * @param x_cell координата клетки по x
     * @param y_cell координата клетки по y
     * @param status состояние клетки
     */
    void set_cell(const int x_cell, const int y_cell, const int status);
    /**
     * @brief Задать массив клеток
     * @param c двумерный массив клеток
     */
    void set_cells(const std::vector<std::vector<Cell> > c) {cells = c;}
private:
    int x;
    int y;
    std::vector<std::vector<Cell> > cells;
};

#endif // FIELD_H
