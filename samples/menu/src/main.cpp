#include "menu.h"
#include "state_machine.h"

#include <functional>

/* enum std::string TODO use class enum cpp11 */
void print(std::string message)
{
    std::cout << message << std::endl;
}

int main(int argc, char **argv)
{
    std::cout << "Hello sample!" << std::endl;

    //std::vector<std::string> main_options = { "Pistols", "Shotguns", "SMG", "Rifles", "MachineGuns", "Primary ammo", "Secondary ammo", "Equipment" };
    //Menu mainMenu = Menu("main_menu", main_options);
    //mainMenu.run();

    auto print_value = [](const std::string& value) { std::cout << "'" << value << "' "; };
    auto print_current_state = [](const std::string& state) { std::cout << "Current state: '" << state << "' "; };

    std::vector<std::string> states = { "Main Menu", "Pistols", "Shotguns" /*, "SMG", "Rifles", "MachineGuns", "Primary ammo", "Secondary ammo", "Equipment" */ };
    std::string initialState = "Main Menu";
    std::vector<std::string> events = { "next_event" };
    std::vector<std::vector<std::string>> transitions;
    transitions.push_back({"Main Menu", "next_event", "Pistols"});
    transitions.push_back({"Pistols", "next_event", "Shotguns"});
    transitions.push_back({"Shotguns", "next_event", "Main Menu"});

    std::cout << "States availables: ";
    std::for_each(states.begin(), states.end(), print_value);
    std::cout << std::endl;

    std::cout << "Initial state: ";
    print_value(initialState);
    std::cout << std::endl;

    std::cout << "Events: ";
    std::for_each(events.begin(), events.end(), print_value);
    std::cout << std::endl;

    /* At this point we create a FSM to control the logic of the front end */
    FSM buyMenuFSM(states, initialState, events, transitions);

    /* Bind all methods required by menu class */
    buyMenuFSM.getStateByName(states[0])->run = std::bind(&print, states[0]);
    buyMenuFSM.getStateByName(states[1])->run = std::bind(&print, states[1]);
    buyMenuFSM.getStateByName(states[2])->run = std::bind(&print, states[2]);
    //buyMenuFSM.getStateByName(states[3])->run = std::bind(&print, states[3]);
    //buyMenuFSM.getStateByName(states[4])->run = std::bind(&print, states[4]);
    //buyMenuFSM.getStateByName(states[5])->run = std::bind(&print, states[5]);
    //buyMenuFSM.getStateByName(states[6])->run = std::bind(&print, states[6]);
    //buyMenuFSM.getStateByName(states[7])->run = std::bind(&print, states[7]);
    //buyMenuFSM.getStateByName(states[8])->run = std::bind(&print, states[8]);

    if(!buyMenuFSM.startFSM())
    {
        std::cerr << "Cannot start FSM. Aborting!" << std::endl;
        return -1;
    }

    /* TODO: User cin translation */
    buyMenuFSM.propagateEvent("next_event");

    //print_current_state(buyMenuFSM.getCurrentState());

    return 0;
}
