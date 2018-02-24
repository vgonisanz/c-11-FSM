#include "menu.h"

int main(int argc, char **argv)
{
    printf("Hello sample!\n");

    Menu mainMenu = Menu("main_menu");
    mainMenu.run();
    return 0;
}
