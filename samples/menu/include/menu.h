#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Menu
{
private:
    std::string _name;
    std::vector<std::string> _options;

public:
    Menu(std::string name, std::vector<std::string> options);
    ~Menu();

    //void printResult();

    void run();
};
