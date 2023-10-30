
#ifndef CODE_MENU_H
#define CODE_MENU_H

#include "structs.h"
#include "Reader.h"
#include "App.h"
#include "SchedulePrinter.h"

#include <stdio.h>
#include <iostream>

using namespace std;

class Menu {
public:
    // Initializes the Menu
    static void initMenu();

    // Display menu Option
    static void displayMenu();

    // Add menu Option
    static void addMenu();

    // Remove menu Option
    static void removeMenu();

    // Change menu Option
    static void changeMenu();

    // Requests menu Option
    static void requestsMenu();

    // Student menu Option
    static void studentMenu();

    // Class menu Option
    static void classMenu();

    // Uc menu Option
    static void ucMenu();
};

#endif //CODE_MENU_H
