#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include <vector>

using namespace std;

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
     * @brief Установить значение поля x, равное размеру поля по оси x
     */
    Cell get_cell(const int x_cell, const int y_cell) {return cells[x_cell][y_cell];}
    void set_x(const int a) {x = a;}
    /**
     * @brief Установить значение поля y, равное размеру поля по оси y
     */
    void set_y(const int b) {y = b;}
    /**
     * @brief Запускает механизм смены поколения и изменения клеток
     */
    void set_cell(const int x_cell, const int y_cell, const int status);
    void change_field();
private:
    int x;
    int y;
    vector<vector<Cell> > cells;
};

#endif // FIELD_H
