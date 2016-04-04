#ifndef API_H
#define API_H
#include "field.h"

class Api
{
public:
    void initialize_settings(Field &f, int f_x, int f_y);
    void initialize_field(Field &f);
    void save_field();
    void load_field();
    void print_field(Field &f);
};

#endif // API_H
