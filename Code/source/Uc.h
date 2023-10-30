
#ifndef CODE_UC_H
#define CODE_UC_H

#include "structs.h"
#include "App.h"
#include "Class.h"

class Uc {
public:
    // Gets the Class Codes of a Given Uc
    static vector<string> getUcClassCodes(string ucCode);

    // Gets the Schedule of a Given Uc
    static vector<classes> getUcSchedule(string ucCode);

    // Prints the Students in a Given Uc
    static void printStudentsInAUc(string ucCode);
};

#endif //CODE_UC_H
