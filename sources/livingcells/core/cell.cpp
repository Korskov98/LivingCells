#include "cell.h"

int Cell::search_dead(vector<vector<Cell> > c){
    int number = 0;
    Cell cell = c[x][y-1];
    if (cell.get_status() == 0){
        ++number;
    }
    cell = c[x-1][y-1];
    if (cell.get_status() == 0){
        ++number;
    }
    cell = c[x][y-1];
    if (cell.get_status() == 0){
        ++number;
    }
    cell = c[x+1][y-1];
    if (cell.get_status() == 0){
        ++number;
    }
    cell = c[x+1][y];
    if (cell.get_status() == 0){
        ++number;
    }
    cell = c[x+1][y+1];
    if (cell.get_status() == 0){
        ++number;
    }
    cell = c[x][y+1];
    if (cell.get_status() == 0){
        ++number;
    }
    cell = c[x-1][y+1];
    if (cell.get_status() == 0){
        ++number;
    }
    return number;
}

int Cell::search_living(vector<vector<Cell> > c){
    int number = 0;
    Cell cell = c[x-1][y];
    if (cell.get_status() != 0){
        ++number;
    }
    cell = c[x-1][y-1];
    if (cell.get_status() != 0){
        ++number;
    }
    cell = c[x][y-1];
    if (cell.get_status() != 0){
        ++number;
    }
    cell = c[x+1][y-1];
    if (cell.get_status() != 0){
        ++number;
    }
    cell = c[x+1][y];
    if (cell.get_status() != 0){
        ++number;
    }
    cell = c[x+1][y+1];
    if (cell.get_status() != 0){
        ++number;
    }
    cell = c[x][y+1];
    if (cell.get_status() != 0){
        ++number;
    }
    cell = c[x-1][y+1];
    if (cell.get_status() != 0){
        ++number;
    }
    return number;
}
