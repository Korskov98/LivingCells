#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H
#include "api.h"
#include "field.h"


class console_ui
{
public:
    void print_menu();
    void secondary_menu(Field &f, Api a);
    void input_menu(Field &f, Api a, int x, int y);
};

#endif // CONSOLE_UI_H
