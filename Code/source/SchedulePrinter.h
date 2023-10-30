
#ifndef CODE_SCHEDULEPRINTER_H
#define CODE_SCHEDULEPRINTER_H

#include "Student.h"
#include "Class.h"
#include "Uc.h"
#include "structs.h"

#include <iomanip>

using namespace std;

class SchedulePrinter {
public:
    static classTimeIndexes getClassTimes(classes classTimes);

    static vector<vector<string>> scheduleBuilder(vector<classes> classesSchedule);

    static void printSchedule(vector<vector<string>> schedule);

    static void printStudentSchedule(string studentNameOrCode);

    static void printClassSchedule(string classCode);

    static void printUcSchedule(string ucCode);
};

#endif //CODE_SCHEDULEPRINTER_H
