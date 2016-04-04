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

void Field::change_field(){
    Field new_f(x,y);
    new_f.cells = this->cells;
    for (int i = 0; i < x; ++i){
        for (int j = 0; j < x; ++j){
            Cell c = cells[i][j];
            int number = c.search_living(cells);
            if ((c.get_status() == 0) && (number == 3)){
                new_f.set_cell(i,j,1);
            }else{
            if ((c.get_status() == 1) && ((number == 3) || (number == 2))){
                new_f.set_cell(i,j,1);
            }else{
                new_f.set_cell(i,j,0);
            }
            }
        }
    }
    this->cells = new_f.cells;
}
