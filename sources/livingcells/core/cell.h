#ifndef CELL_H
#define CELL_H

/**
  @brief Класс Клетка

  Этот класс моделирует объект клетка из которых будет состоять поле.
  */

class Cell
{
public:
    /**
     * @brief Конструктор
     */
    Cell(): x(0), y(0), status(false) {}
    /**
     * @brief Конструктор
     * @param a координата по оси x
     * @param b координата по оси y
     * @param st состояние клетки
     */
    Cell(const int a, const int b, const bool st): x(a), y(b), status(st) {}
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
    bool get_status() {return status;}
    /**
     * @brief Установить значение поля x, равное координате по оси x
     */
    void set_x(const int a) {this->x = a;}
    /**
     * @brief Установить значение поля y, равное координате по оси y
     */
    void set_y(const int b) {this->y = b;}
    /**
     * @brief Установить значение поля status, равное состоянию клетки
     */
    void set_status(const bool st) {this->status = st;}
    /**
     * @brief Подсчёт колличества соседних живых клеток
     */
    int search_living();
    /**
     * @brief Подсчёт колличества соседних живых клеток
     */
    int search_dead();
private:
    int x;
    int y;
    bool status;
};

#endif // CELL_H
