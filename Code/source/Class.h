#ifndef CODE_CLASS_H
#define CODE_CLASS_H

#include "structs.h"
#include "App.h"

#include <stack>

class Class {
public:
    // Is Class a Real Class
    static bool isClass(string classCode);

    // Gets Students in a Given Class
    static void printStudentsInAClass(string classCode);

    // Gets the Uc Codes of a Given Class
    static vector<string> getClassUcCodes(string classCode);

    // Gets the ClassSchedule of a Given Uc
    static classes getClassSchedulePerUc(string classUcCode);

    // Gets the Class Schedule of a Given Uc
    static vector<classes> getClassSchedule(string classUcCodes);

    // Prints the Students of a Class of a Given Uc
    static void printStudentsPerClassOfAGivenUc(string classCode, string ucCode);
};

#endif //CODE_CLASS_H
