#include "field.h"
#include "cell.h"

void Field::set_x(const int a){
    x = a;
    cells.resize(x);
}

void Field::set_y(const int b)
{
    y = b;
    for (int i = 0; i < x; i++){
        cells[i].resize(y);
    }
}

void Field::set_cell(const int x_cell, const int y_cell, const int status)
{
    Cell c(x_cell,y_cell,status);
    cells[x_cell][y_cell] = c;
}
