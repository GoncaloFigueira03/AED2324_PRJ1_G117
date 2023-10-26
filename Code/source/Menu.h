
#ifndef CODE_MENU_H
#define CODE_MENU_H

#include "structs.h"
#include "Reader.h"
#include "App.h"

#include <stdio.h>
#include <iostream>

class Menu
{
public:
    static void viewStudentSchedule(string studentNameOrCode);

    static void viewClassSchedule(string classCode);

    static void viewUcSchedule(string ucCode);
};

#endif //CODE_MENU_H
