#ifndef CODE_MENU_H
#define CODE_MENU_H

#include "structs.h"
#include "Reader.h"
#include "SchedulePrinter.h"
#include "Schedule.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Menu {
public:
    /**
     * @brief Initializes the Menu
     */
    static void initMenu();

    /**
     * @brief Displays the Menu
     */
    static void displayMenu();

    /**
     * @brief Adds a Student to a Class
     */
    static void addMenu();

    /**
     * @brief Displays the Remove Menu
     */
    static void removeMenu();

    /**
     * @brief Changes a Student's Class
     */
    static void changeMenu();

    /**
     * @brief Displays the Requests Menu
     */
    static void requestsMenu();

    /**
     * @brief Displays the Student Menu
     */
    static void studentMenu();

    /**
     * @brief Displays the Class Menu
     */
    static void classMenu();

    /**
     * @brief Displays the Uc Menu
     */
    static void ucMenu();
};

#endif //CODE_MENU_H
