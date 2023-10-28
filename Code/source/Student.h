
#ifndef CODE_STUDENT_H
#define CODE_STUDENT_H

#include "structs.h"
#include "App.h"
#include "Menu.h"

class StudentSchedule
{
public:
    static vector<string> getStudentClassCodes(string studentNameOrCode);

    static vector<string> getStudentUcCodes(string studentNameOrCode);

    static list<string> pairStudentUcCodesWithClassCodes(vector<string> ucCodes, vector<string> classCodes);

    static vector<classes> getStudentClasses(list<string> studentUcCodesWithClassCodes);

    static vector<classes> getStudentSchedule(string studentNameOrCode);

    static bool isTClassOverTPOrPL(classes tClass, classes secondClass);

    static void isTClassOverTPOrPLV2(classes tClass, vector<classes> secondClasses, vector<classes> studentClassesFixed);

};
#endif //CODE_STUDENT_H
