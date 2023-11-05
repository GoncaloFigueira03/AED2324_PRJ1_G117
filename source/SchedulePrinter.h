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
    /**
     * @brief Take the Class Times and return the Indexes for the Schedule
     * @param classTimes
     * @return classTimeIndexes The Time Indexes for the Schedule (Weekday Index, Start Hour Index and Duration Index)
     */
    static classTimeIndexes getClassTimes(classes classTimes);

    /**
     * @brief Build the Schedule
     * ;complexity O(n^2)
     * @param classesSchedule The Classes Schedule
     * @return vector<vector<string>> The Schedule Itself as a 2D vector
     */
    static vector<vector<string>> scheduleBuilder(vector<classes> classesSchedule);

    /**
     * @brief Print the Schedule
     * @param schedule The Schedule to Print
     */
    static void printSchedule(vector<vector<string>> schedule);

    /**
     * @brief Called to Print the Schedule of a Student
     * @param studentNameOrCode Student Name or Student Code
     */
    static void printStudentSchedule(string studentNameOrCode);

    /**
     * @brief Called to Print the Schedule of a Class
     * @param classCode Class Code
     */
    static void printClassSchedule(string classCode);

    /**
     * @brief Called to Print the Schedule of an Uc
     * @param ucCode Uc Code
     */
    static void printUcSchedule(string ucCode);
};

#endif //CODE_SCHEDULEPRINTER_H
