# Buy menu sample

FSM to show different menus with options and wait user input. The FSM contain the
states from requirements. A menu class is managed by FSM to isolate different
menus and behaviour.

# Requirements

* The FSM shall contain the following states:
    * main_menu
    * submenu_1
    * submenu_2
    * submenu_3
    * submenu_4
    * submenu_5
    * submenu_8
* Each state is a menu with several options.
* The user can select any option of the current menu, or cancel and go to main menu.
* Choose any option will call a function to do any of the following actions:
    * launch_mainmenu or submenu: Print a menu with options and wait the user's input
    * print_result:
* Every menu or submenu shall contain:
    * title: Describing what menu is used for.
    * options: List of every option inside.
    * callbacks: A function pointer to the action to do when selected.
    * arg: Arguments for the function to the action to do when selected.
* main_menu shall contain:
    * title: "Choose a weapon to buy"
    * options: ["Pistols", "Shotguns", "SMG", "Rifles", "MachineGuns", "Primary ammo", "Secondary ammo", "Equipment"]
    * callbacks: [launch_mainmenu, launch_mainmenu, launch_mainmenu, launch_mainmenu, launch_mainmenu, print_result, print_result, launch_mainmenu]
    * args: [launch_submenu_1, launch_submenu_2, launch_submenu_3, launch_submenu_4, launch_submenu_5, ["Primary ammo", "100$"], ["Secondary ammo", "60$"], launch_submenu_8]
* submenu_1 shall contain:
    * title: "Choose a pistol"
    * options: ["USP .45ACP Tactical", "Glock 18C Select Fire", "Desert Eagle .50 AE", "SIG P228", "FN Five-Seven"]
    * callbacks: [print_result, print_result, print_result, print_result, print_result]
    * args: ["400$", "400$", "650$", "600$", "750$"]
* submenu_2 shall contain:
    * title: "Choose a shotgun"
    * options: ["M3 Super 90 Combat", "XM1014"]
    * callbacks: [print_result, print_result]
    * args: ["1700$", "3000$"]
* submenu_3 shall contain:
    * title: "Choose a sub machine gun"
    * options: ["MP5 Navy", "Streyr TMP", "FN P90", "MAC-10", "H&K UMP"]
    * callbacks: [print_result, print_result, print_result, print_result, print_result]
    * args: ["1500$", "1250$", "2350$", "1400$", "1700$"]
* submenu_4 shall contain:
    * title: "Choose a rifle"
    * options: ["AK47", "M4A1 Carbine/COLT", "SG552 Commando", "Steyr AUG", "Steyr Scout Sniper Rifle", "Artic Warfare Magnum", "SIG SG-550", "G3/SG1 Sniper Rifle"]
    * callbacks: [print_result, print_result, print_result, print_result, print_result, print_result, print_result, print_result]
    * args: ["2500$", "3100$", "3500$", "3500$", "2750$", "4750$", "4200$", "5000$"]
* submenu_5 shall contain:
    * title: "Choose a machineGun"
    * options: ["FN M249 PARA"]
    * callbacks: [print_result]
    * args: ["5750$"]
* submenu_8 shall contain:
    * title: "Choose a equipment"
    * options: ["Armor", "Armor|Helmet", "Flash", "Grenade", "Smoke", "Defuser", "NightVision", "Shield"]
    * callbacks: [print_result, print_result, print_result, print_result, print_result, print_result, print_result, print_result]
    * args: ["650$", "1000$", "200$", "300$", "300$", "200$", "1250$", "1000$"]

# Build diagram

* `uml`: This folder contain an UML that describe the FSM.
* In order to build it, package ```plantuml``` and ```graphviz``` are required.
* To install in Fedora: ```sudo dnf install plantuml.noarch graphviz.x86_64```
