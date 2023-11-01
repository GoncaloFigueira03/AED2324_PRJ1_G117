
#ifndef CODE_SCHEDULE_H
#define CODE_SCHEDULE_H

#include "App.h"
#include "Student.h"
#include "Writer.h"

#include <queue>
#include <stack>

using namespace std;

struct studentClassChange {
    string studentName;
    string studentCode;
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

    // Stores the Information about Requests
    queue<studentClassChange> requestQueue;

    vector<string> processRequestFailedMessages;

public:
    studentClassChange lastChange;

    int getMaxUcsPerStudent();

    int getMaxStudentsPerClass();

    int getMaxStudentsPerClassChangeGap();

    int getClassStudentsNumberAvg(char classYear);

    static void addUcToStudent(queue <string> studentInfo);

    static void removeUcFromStudent(queue <string> studentInfo);

    static void requestChangeInStudentClass(queue <string> studentInfo);

    static void printRequests();

    static void processRequest();

    static void revertLastChange();

    static void printRequestFailLogs();

    static int getStudentUcsNumber(string studentNameOrCode);

    static int getClassStudentsNumber(string classCode);

    static bool doesUcBelongToClass(string ucCode, string classCode);

    static bool isClassFull(string classCode);

    static bool isChangeGapRespected(string classCode);

    static bool isScheduleChangeValid(studentClassChange studentClassChange);
};

#endif //CODE_SCHEDULE_H
