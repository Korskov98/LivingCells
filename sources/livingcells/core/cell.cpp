#include "cell.h"

int Cell::check(Cell c){
    if (c.get_status() != 0){
        return 1;
    }else{
        return 0;
    }
}

int Cell::search_living(const std::vector<std::vector<Cell> > c){
    int number = 0;
    if (x - 1 != -1){
        Cell cell = c[x-1][y];
        number += this->check(cell);
    }
    if ((x - 1 != -1) && (y - 1 != -1)){
        Cell cell = c[x-1][y-1];
        number += this->check(cell);
    }
    if (y - 1 != -1){
        Cell cell = c[x][y-1];
        number += this->check(cell);
    }
    if ((x + 1 != (int) c.size()) && (y - 1 != -1)) {
        Cell cell = c[x+1][y-1];
        number += this->check(cell);
    }
    if (x + 1 != (int) c.size()){
        Cell cell = c[x+1][y];
        number += this->check(cell);
    }
    if ((x + 1 != (int) c.size()) && (y + 1 != (int) c[x].size())) {
        Cell cell = c[x+1][y+1];
        number += this->check(cell);
    }
    if (y + 1 != (int) c[x].size()){
        Cell cell = c[x][y+1];
        number += this->check(cell);
    }
    if ((x - 1 != -1) && (y + 1 != (int) c[x].size())){
        Cell cell = c[x-1][y+1];
        number += this->check(cell);
    }
    return number;
}
