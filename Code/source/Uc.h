
#ifndef CODE_UC_H
#define CODE_UC_H

#include "structs.h"
#include "App.h"
#include "Class.h"

class Uc{
public:
    static vector<string> getUcClassCodes(string ucCode);

    static vector<string> getUcSchedule(string ucCode);

    static void printStudentsInAUc(string ucCode);
};

#endif //CODE_UC_H
