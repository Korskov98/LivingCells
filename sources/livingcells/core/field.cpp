#include "field.h"
#include "cell.h"

void Field::set_cell(const int x_cell, const int y_cell, const int status)
{
    Cell c = cells[x_cell][y_cell];
    c.set_status(status);
    cells[x_cell][y_cell] = c;
}

void Field::change_field(){
    Field new_f(x, y);
    for (int i = 0; i < x; ++i){
        for (int j = 0; j < x; ++j){
            Cell c = cells[i][j];
            int number = c.search_living(cells);
            if ((c.get_status() == 0) && (number == 3)){
                c.set_status(1);
            }
            if ((c.get_status() != 0) && ((number == 3) || (number == 2))){
                c.set_status(0);
            }
            new_f.cells[i][j] = c;
        }
    }
    this->cells = new_f.cells;
}
