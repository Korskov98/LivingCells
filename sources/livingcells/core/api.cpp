#include "api.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void Api::initialize_field(Field f){
    srand(time(NULL));
    for (int i; i < f.get_x(); ++i){
        for (int j; j < f.get_y(); ++j){
            f.set_cell(i,j,rand()%2);
        }
    }
}

