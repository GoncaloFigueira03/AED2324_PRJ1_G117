
#ifndef CODE_SCHEDULE_H
#define CODE_SCHEDULE_H

#include "App.h"
#include "Student.h"

#include <queue>

using namespace std;

struct studentClassChange {
    string studentNameOrCode;
    string newClassCode;
    string oldClassCode;
    string newUcCode;
    string oldUcCode;
};

class Scheduler {
private:
    // The Maximum Number of Ucs a Student can have
    const int maxUcsPerStudent = 7;

    // The Maximum Number of Students a Class can have
    const int maxStudentsPerClass = 30;

    // The Maximum Difference in the Number of Students between Classes in order to Change a Student's Class
    const int maxStudentsPerClassChangeGap = 4;

    // Stores the Information About Student Classes Changes
    stack<studentClassChange> studentsClassesChangesStack;

public:
    // TODO: implement
    int getMaxUcsPerStudent();

    int getMaxStudentsPerClass();

    int getMaxStudentsPerClassChangeGap();

    int getClassStudentsNumberAvg(char classYear);

    static void addUcToStudent(queue <string> studentInfo);

    static void requestChangeInStudentClass(studentClassChange studentClassChange);

    static int getStudentUcsNumber(string studentNameOrCode);

    static int getClassStudentsNumber(string classCode);

    static bool doesUcBelongToClass(string ucCode, string classCode);

    static bool isClassFull(string classCode);

    static bool isChangeGapRespected(string classCode);

    static bool isScheduleChangeValid(string studentNameOrCode, string newClassCode, string newUcCode, string oldClassCode, string oldUcCode);
};

#endif //CODE_SCHEDULE_H
