
#include "Menu.h"

#define RESET "\033[0m"
#define BOLDWHITE "\033[1m\033[37m"

int main() {
    system("CLS");
    cout << endl << BOLDWHITE << "---WELCOME TO THE SCHEDULER---" << endl << endl;
    cout << RESET << "This program was developed by:" << endl;
    cout << "Goncalo Figueira - UP202108804" << endl;
    cout << "Tomas Ferreira - UP202002749" << endl << endl;

    system("PAUSE");
    system("CLS");

    Menu::initMenu();

    return 0;
}