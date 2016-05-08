#ifndef API_H
#define API_H
#include "field.h"
#include "string"

class Api
{
public:
    void initialize_settings(Field &f, int f_x, int f_y);
    void initialize_field(Field &f);
    void save_field(Field &f);
    void load_field(Field &f);
    void print_field(Field &f);
    void change_field(Field &f);
    void set_cell(Field &f, int x, int y, std::string status);
};

#endif // API_H
