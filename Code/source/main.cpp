
#include "Menu.h"

Scheduler mainScheduler;

int main() {
    cout << "Welcome to the Scheduler" << endl;
    if (mainScheduler.lastChange.studentCode != "") {
        cout << mainScheduler.lastChange.studentCode << mainScheduler.lastChange.studentName
             << mainScheduler.lastChange.newUcCode << mainScheduler.lastChange.newClassCode << endl;
    }
    else {
        cout << "No last change" << endl;
    }

    Menu::initMenu();

    return 0;
}