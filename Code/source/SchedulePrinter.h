
#ifndef CODE_SCHEDULEPRINTER_H
#define CODE_SCHEDULEPRINTER_H

#include "Student.h"
#include "Class.h"
#include "Uc.h"
#include "structs.h"

using namespace std;

class SchedulePrinter{
public:

    static vector<vector<string>> studentScheduleBuilder(string studentCode);

    static vector<vector<string>> classScheduleBuilder(string classCode);

    static vector<vector<string>> ucScheduleBuilder(string ucCode);

    static void printSchedule(vector<vector<string>> schedule);
};

#endif //CODE_SCHEDULEPRINTER_H
