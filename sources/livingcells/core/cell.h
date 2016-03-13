#ifndef CELL_H
#define CELL_H


class Cell
{
public:
    Cell(): x(0), y(0), status(false) {}
    Cell(const int a, const int b, const bool st): x(a), y(b), status(st) {}
    int get_x() {return x;}
    int get_y() {return y;}
    bool get_status() {return status;}
    void set_x(const int a) {this->x = a;}
    void set_y(const int b) {this->y = b;}
    void set_status(const bool st) {this->status = st;}
    int search_living();
    int search_dead();
private:
    int x;
    int y;
    bool status;
};

#endif // CELL_H
