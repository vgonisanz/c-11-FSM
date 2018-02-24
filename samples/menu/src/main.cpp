#include <stdio.h>
#include <iostream>

#include "menu.h"

int main(int argc, char **argv)
{
    printf("Hello sample!\n");

    Menu mainMenu = Menu();

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
    return 0;
}
