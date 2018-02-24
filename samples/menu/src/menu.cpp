#include "menu.h"

Menu::Menu(std::string name, std::vector<std::string> options):
_name("")
{
    std::cout << "Creating Menu: " << name.c_str() << std::endl;
    _name = name;
    _options = options;
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
        int counter = 0;
        for (auto &option : _options)
        {
            counter++;
            std::cout << counter << ".-" << option.c_str() << std::endl;
        }
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
