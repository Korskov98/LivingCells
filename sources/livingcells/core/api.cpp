#include "api.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

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

void Api::save_field(Field &f)
{
    std::ofstream file;
    file.open("save.txt");
    file << f.get_x() << " " << f.get_y() << std::endl;
    for (int i = 0; i < f.get_x(); i++){
        for (int j = 0; j < f.get_y(); j++){
            Cell c = f.get_cell(i,j);
            if (c.get_status() == true){
                file << "L ";
            }else{
                file << "D ";
            }
        }
        file << std::endl;
    }
    file.close();
}

void Api::load_field(Field &f)
{
    std::ifstream file;
    file.open("save.txt");
    int x,y;
    file >> x >> y;
    f.set_x(x);
    f.set_y(y);
    std::string st;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            file >> st;
            if (st == "D"){
                f.set_cell(i,j,0);
            }else{
                f.set_cell(i,j,1);
            }
        }
    }
    file.close();
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
        std::cout<<std::endl;
    }
}

void Api::change_field(Field &f){
    int x = f.get_x(), y = f.get_y();
    Field new_f(x,y);
    new_f.set_cells(f.get_cells());
    for (int i = 0; i < x; ++i){
        for (int j = 0; j < y; ++j){
            Cell c = f.get_cell(i,j);
            int number = c.search_living(f.get_cells());
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
    f.set_cells(new_f.get_cells());
}

void Api::set_cell(Field &f, int x, int y, std::string status)
{
    if (status == "D"){
        f.set_cell(x,y,0);
    }else{
        f.set_cell(x,y,1);
    }
}
