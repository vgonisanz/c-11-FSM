#include "menu.h"

int main(int argc, char **argv)
{
    std::cout << "Hello sample!" << std::endl;

    std::vector<std::string> main_options = { "Pistols", "Shotguns", "SMG", "Rifles", "MachineGuns", "Primary ammo", "Secondary ammo", "Equipment" };
    Menu mainMenu = Menu("main_menu", main_options);
    mainMenu.run();
    return 0;
}
