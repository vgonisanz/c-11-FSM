#pragma once

#include <stdio.h>
#include <iostream>
#include <string>

class Menu
{
private:
    std::string _name;

public:
    Menu(std::string name);
    ~Menu();

    void run();
};
