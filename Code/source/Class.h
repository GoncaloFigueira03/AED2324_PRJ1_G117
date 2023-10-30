#ifndef CODE_CLASS_H
#define CODE_CLASS_H

#include "structs.h"
#include "App.h"

class Class{
public:
    static vector<string> getClassUcCodes(string classCode);

    static classes getClassSchedulePerUc(string classUcCode);

    static vector<classes> getClassSchedule(string classUcCodes);

    static void printStudentsPerClassOfAGivenUc(string classCode, string ucCode);
};

#endif //CODE_CLASS_H
