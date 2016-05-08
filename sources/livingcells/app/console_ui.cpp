#include "console_ui.h"
#include <iostream>
#include <fstream>
#include "string"

void console_ui::print_menu()
{
    int choice = -1;
    Api a;
    Field f;
    while(choice != 0) {
        std::cout << "1. Создать новую модель автоматически." << std::endl;
        std::cout << "2. Создать новую модель вручную." << std::endl;
        std::cout << "3. Загрузить модель." << std::endl;
        std::cout << "0. Выход." << std::endl;
        std::cin >> choice;
        int x,y;
        switch (choice)
        {
            case 1:
                std::cout << "Введите размер поля." << std::endl;
                std::cin >> x >> y;
                a.initialize_settings(f,x,y);
                a.initialize_field(f);
                a.print_field(f);
                this->secondary_menu(f,a);
            break;
            case 2:
                std::cout << "Введите размер поля." << std::endl;
                std::cin >> x >> y;
                a.initialize_settings(f,x,y);
                input_menu(f,a,x,y);
                a.print_field(f);
                this->secondary_menu(f,a);
            break;
            case 3:
                a.load_field(f);               
                a.print_field(f);
                std::cout << "Модель успешно загружена." << std::endl;
                this->secondary_menu(f,a);
            break;
            case 0:
            break;
            default:
                std::cout << "Некорректная команда." << std::endl;
            break;
        }
    }
}

void console_ui::secondary_menu(Field &f, Api a)
{
    int choice = -1;
    while (choice != 0) {
        std::cout << "1. Следующее поколение." << std::endl;
        std::cout << "2. Сохранить модель." << std::endl;
        std::cout << "0. Назад в главное меню." << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                a.change_field(f);
                a.print_field(f);
                this->secondary_menu(f,a);
            break;
            case 2:
                a.save_field(f);
                std::cout << "Модель успешно сохранена." << std::endl;
                this->secondary_menu(f,a);
            break;
            case 0:
            break;
            default:
                std::cout << "Некорректная команда." << std::endl;
                a.print_field(f);
                this->secondary_menu(f,a);
            break;
        }
        break;
    }
}

void console_ui::input_menu(Field &f, Api a, int x, int y)
{
    std::string status;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            std::cout << "Введите состояние клетки " << i+1 << " строки " << j+1 << " столбца." << std::endl;
            std::cin >> status;
            a.set_cell(f,i,j,status);
        }
    }
}
