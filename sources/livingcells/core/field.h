#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include "cell.h"

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
     */
    Field(): x(0), y(0) {}
    /**
     * @brief Конструктор
     * @param a размер поля по оси x
     * @param b размер поля по оси y
     */
    Field(const int a, const int b): x(a), y(b) {}
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
    void set_x(const int a) {this->x = a;}
    /**
     * @brief Установить значение поля y, равное размеру поля по оси y
     */
    void set_y(const int b) {this->y = b;}
    /**
     * @brief Запускает механизм смены поколения и изменения клеток
     */
    void change_field();
private:
    int x;
    int y;
    vector<vector<Cell> > cells;
};

#endif // FIELD_H
