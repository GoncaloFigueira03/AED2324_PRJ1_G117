
#ifndef CODE_SCHEDULEPRINTER_H
#define CODE_SCHEDULEPRINTER_H

#include "Student.h"
#include "Class.h"
#include "Uc.h"
#include "structs.h"

#include <iomanip>

using namespace std;

class SchedulePrinter{
public:
    static classTimeIndexes getClassTimes(classes classTimes);

    static vector<vector<string>> studentScheduleBuilder(string studentNameOrCode);

    static vector<vector<string>> classScheduleBuilder(string classCode);

    static vector<vector<string>> ucScheduleBuilder(string ucCode);

    static void printSchedule(vector<vector<string>> schedule);

    static void printStudentSchedule(string studentNameOrCode);
};

#endif //CODE_SCHEDULEPRINTER_H
