#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include "cell.h"

using namespace std;


class Field
{
public:
    Field(): x(0), y(0) {}
    Field(const int a, const int b): x(a), y(b) {}
    int get_x() {return x;}
    int get_y() {return y;}
    void set_x(const int a) {this->x = a;}
    void set_y(const int b) {this->y = b;}
    void change_field();
private:
    int x;
    int y;
    vector<vector<Cell> > cells;
};

#endif // FIELD_H
