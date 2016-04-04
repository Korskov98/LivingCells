#include "api.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void Api::initialize_settings(Field &f, int f_x, int f_y)
{
    f.set_x(f_x);
    f.set_y(f_y);
}

void Api::initialize_field(Field &f){
    srand(time(0));
    for (int i = 0; i < f.get_x(); i++){
        for (int j = 0; j < f.get_y(); j++){
            f.set_cell(i,j,rand()%2);
        }
    }
}

void Api::print_field(Field &f)
{
    for (int i = 0; i < f.get_x(); i++){
        for (int j = 0; j < f.get_y(); j++){
            Cell c = f.get_cell(i,j);
            switch (c.get_status()) {
            case false:
                std::cout<<"D ";
                break;
            case true:
                std::cout<<"L ";
                break;
            }
        }
        std::cout<<endl;
    }
}

