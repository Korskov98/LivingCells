#include "console_ui.h"
#include <iostream>
#include <fstream>

void console_ui::print_menu()
{
    int choice = -1;
    Api a;
    Field f;
    while(choice != 0) {
        std::cout << "1. Create new model." << std::endl;
        std::cout << "2. Load model." << std::endl;
        std::cout << "0. Exit." << std::endl;
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                std::cout << "Enter size field." << std::endl;
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
    int choice = -1;
    while (choice != 0) {
        std::cout << "1. Next generation." << std::endl;
        std::cout << "2. Save model." << std::endl;
        std::cout << "0. Back in main menu." << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1:
            a.change_field(f);
            a.print_field(f);
            this->secondary_menu(f,a);
            break;
        case 2:
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
            this->secondary_menu(f,a);
            break;
        }
        break;
    }
}
