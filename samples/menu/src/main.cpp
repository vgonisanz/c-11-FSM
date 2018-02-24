#include "menu.h"

int main(int argc, char **argv)
{
    std::cout << "Hello sample!" << std::endl;

    Menu mainMenu = Menu("main_menu");
    mainMenu.run();
    return 0;
}
