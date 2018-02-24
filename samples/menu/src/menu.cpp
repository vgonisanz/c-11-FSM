#include <stdio.h>

#include "menu.h"

Menu::Menu(std::string name):
_name("")
{
    _name = name;
    std::cout << "Creating Menu: " << _name.c_str() << std::endl;
}

Menu::~Menu()
{
    std::cout << "Destroying Menu: " << _name.c_str() << std::endl;
}

void Menu::run()
{
    std::cout << "Running Menu: " << _name.c_str() << std::endl;

    int choice;
    bool end = true;
    while (end != false)
    {
        std::cout << " 1 - Start the game.\n";
        std::cout << " 2 - Story.\n";
        std::cout << " 3 - Help.\n";
        std::cout << " 4 - Exit.\n";
        std::cout << " Enter your choice and press return: ";

        std::cin >> choice;

        switch (choice)
        {
            case 1:
            std::cout << "game start!\n";
            // rest of code here
            break;
            case 2:
            std::cout << "Story so far....\n";
            // rest of code here
            break;
            case 3:
            std::cout << "Ahahah, you really think I will help you?\n";
            // rest of code here
            break;
            case 4:
            std::cout << "End of Program.\n";
            end = false;
            break;
            default:
            std::cout << "Not a Valid Choice. \n";
            std::cout << "Choose again.\n";
            std::cin >> choice;
            break;
        }
    }
}
