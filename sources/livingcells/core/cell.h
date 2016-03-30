#ifndef CELL_H
#define CELL_H
#include <vector>

using namespace std;

/**
  @brief Класс Клетка

  Этот класс моделирует объект клетка из которых будет состоять поле.
  */

class Cell
{
public:
    /**
     * @brief Конструктор
     * @param a координата по оси x
     * @param b координата по оси y
     * @param st состояние клетки
     */
    Cell(const int a = 0, const int b = 0, const int st = false): x(a), y(b), status(st) {}
    /**
     * @brief Получить координату по оси x
     * @return координата по оси x
     */
    int get_x() {return x;}
    /**
     * @brief Получить координату по оси y
     * @return координата по оси y
     */
    int get_y() {return y;}
    /**
     * @brief Получить состояние клетки
     * @return состояние клетки
     */
    int get_status() {return status;}
    /**
     * @brief Установить значение поля x, равное координате по оси x
     */
    void set_x(const int a) {x = a;}
    /**
     * @brief Установить значение поля y, равное координате по оси y
     */
    void set_y(const int b) {y = b;}
    /**
     * @brief Установить значение поля status, равное состоянию клетки
     */
    void set_status(const int st) {status = st;}
    /**
     * @brief Подсчёт колличества соседних живых клеток
     */
    int search_living(vector<vector<Cell> > c);
    /**
     * @brief Подсчёт колличества соседних живых клеток
     */
    int search_dead(vector<vector<Cell> > c);
private:
    int x;
    int y;
    int status;
};

#endif // CELL_H
