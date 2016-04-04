#include "console_ui.h"
#include <iostream>

void console_ui::print_menu()
{
    std::cout << "1. Создать новую модель." << std::endl;
    std::cout << "2. Загрузить модель." << std::endl;
    std::cout << "0. Выход." << std::endl;
    int choice;
    Api a;
    Field f;
    while(choice != 0) {
            std::cin >> choice;
            switch (choice)
            {
                case 1:
                    std::cout << "Введите размер поля." << std::endl;
                    int x,y;
                    std::cin >> x >> y;
                    a.initialize_settings(f,x,y);
                    a.initialize_field(f);
                    a.print_field(f);
                    this->secondary_menu(f,a);
                    break;
            }
    }
}

void console_ui::secondary_menu(Field &f, Api a)
{
    std::cout << "1. Следующее поколение." << std::endl;
    std::cout << "2. Сохранить модель." << std::endl;
    std::cout << "0. Назад в главное меню." << std::endl;
    int choice;
    while (choice != 0) {
        std::cin >> choice;
        switch (choice) {
        case 1:
            f.change_field();
            a.print_field(f);
            this->secondary_menu(f,a);
            break;
        }
    }
}
