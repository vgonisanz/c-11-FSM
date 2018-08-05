#include "menu.h"
#include "state_machine.h"

#include <functional>
#include <memory>

/* Lambdas for printing */
auto print_value = [](const std::string& value) { std::cout << "'" << value << "' "; };
auto print_current_state = [](const std::string& state) { std::cout << "Current state: '" << state << "' "; };

std::shared_ptr<FSM> buy_menu;
std::vector<std::string> states { "Main Menu", "Pistols", "Shotguns" /*, "SMG", "Rifles", "MachineGuns", "Primary ammo", "Secondary ammo", "Equipment" */ };
std::string initialState = states.at(0);
std::vector<std::string> events = { "next_event" };
std::vector<std::vector<std::string>> transitions;

/* enum std::string TODO use class enum cpp11 */
void print(std::string message)
{
    std::cout << message << std::endl;
}

void initialize_values()
{
    transitions.push_back({"Main Menu", "next_event", "Pistols"});
    transitions.push_back({"Pistols", "next_event", "Shotguns"});
    transitions.push_back({"Shotguns", "next_event", "Main Menu"});

    std::cout << " > States availables: " << std::endl << " --> ";
    std::for_each(states.begin(), states.end(), print_value);
    std::cout << std::endl;

    std::cout << " > Initial state: "  << std::endl << " --> ";
    print_value(initialState);
    std::cout << std::endl;

    std::cout << " > Events: "  << std::endl << " --> ";
    std::for_each(events.begin(), events.end(), print_value);
    std::cout << std::endl;

    std::cout << std::endl << "Creating FSM..." << std::endl;

    buy_menu = std::make_shared<FSM>(states, initialState, events, transitions);
}

int main(int argc, char **argv)
{
    std::cout << "FSM buy menu sample manual:" << std::endl;

    //std::vector<std::string> main_options = { "Pistols", "Shotguns", "SMG", "Rifles", "MachineGuns", "Primary ammo", "Secondary ammo", "Equipment" };
    //Menu mainMenu = Menu("main_menu", main_options);
    //mainMenu.run();


    initialize_values();

    /* At this point we create a FSM to control the logic of the front end */
    //FSM buyMenuFSM(states, initialState, events, transitions);

    /* Bind all methods required by menu class */
    buy_menu->getStateByName(states[0])->run = std::bind(&print, states[0]);
    buy_menu->getStateByName(states[1])->run = std::bind(&print, states[1]);
    buy_menu->getStateByName(states[2])->run = std::bind(&print, states[2]);
    //buy_menu->getStateByName(states[3])->run = std::bind(&print, states[3]);
    //buy_menu->getStateByName(states[4])->run = std::bind(&print, states[4]);
    //buy_menu->getStateByName(states[5])->run = std::bind(&print, states[5]);
    //buy_menu->getStateByName(states[6])->run = std::bind(&print, states[6]);
    //buy_menu->getStateByName(states[7])->run = std::bind(&print, states[7]);
    //buy_menu->getStateByName(states[8])->run = std::bind(&print, states[8]);

    std::cout << std::endl << "Starting FSM..." << std::endl;

    if(!buy_menu->startFSM())
    {
        std::cerr << "Cannot start FSM. Aborting!" << std::endl;
        return -1;
    }

    /* TODO: User cin translation */
    buy_menu->propagateEvent("next_event");

    //print_current_state(buy_menu->getCurrentState());

    return 0;
}
