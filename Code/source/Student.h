
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

    static vector<string> getStudentSchedule(string studentNameOrCode);

};
#endif //CODE_STUDENT_H
