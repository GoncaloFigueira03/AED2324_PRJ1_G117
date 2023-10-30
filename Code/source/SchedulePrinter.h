
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
    // Take the Class Times and return the Indexes for the Schedule
    static classTimeIndexes getClassTimes(classes classTimes);

    // Build the Schedule
    static vector<vector<string>> scheduleBuilder(vector<classes> classesSchedule);

    // Print the Schedule
    static void printSchedule(vector<vector<string>> schedule);

    // Call in order to Print the Schedule of a Student
    static void printStudentSchedule(string studentNameOrCode);

    // Call in order to Print the Schedule of a Class
    static void printClassSchedule(string classCode);

    //  Call in order to Print the Schedule of an Uc
    static void printUcSchedule(string ucCode);
};

#endif //CODE_SCHEDULEPRINTER_H
