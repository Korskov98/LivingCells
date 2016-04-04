#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H
#include "api.h"
#include "field.h"


class console_ui
{
public:
    void print_menu();
    void secondary_menu(Field &f, Api a);
};

#endif // CONSOLE_UI_H
