#ifndef CODE_SCHEDULE_H
#define CODE_SCHEDULE_H

#include "App.h"
#include "Student.h"
#include "Writer.h"

#include <queue>
#include <stack>

using namespace std;

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

    // Stores the Information about the Requests that were not Successfully Processed
    vector<string> processRequestFailedMessages;

public:
    studentClassChange lastChange;

    /**
     * @brief Gets the Maximum Number of Ucs a Student can have
     * @return int maxUcsPerStudent
     */
    int getMaxUcsPerStudent();

    /**
     * @brief Gets the Maximum Number of Students a Class can have
     * @return int maxStudentsPerClass
     */
    int getMaxStudentsPerClass();

    /**
     * @brief Gets the Maximum Difference in the Number of Students between Classes in order to Change a Student's Class
     * @return int maxStudentsPerClassChangeGap
     */
    int getMaxStudentsPerClassChangeGap();

    /**
     * @brief Gets Class Students Number Average
     * @param classYear It's the Class Year
     * @param ucCode It's the Uc Code
     * @return int classStudentsNumberAvg
     */
    int getClassStudentsNumberAvg(char classYear, string ucCode);

    /**
     * @brief Add an Uc to a Student
     * @param studentInfo It's a queue with the Addition Request Information of the Student
     */
    static void addUcToStudent(queue <string> studentInfo);

    /**
     * @brief Remove an Uc from a Student
     * @param studentInfo It's a queue with the Removal Request Information of the Student
     */
    static void removeUcFromStudent(queue <string> studentInfo);

    /**
     * @brief Change a Student's Class
     * @param studentInfo It's a queue with the Change Request Information of the Student
     */
    static void requestChangeInStudentClass(queue <string> studentInfo);

    /**
     * @brief Prints the Requests in the Request Queue
     */
    static void printRequests();

    /**
     * @brief Processes the Requests in the Request Queue
     */
    static void processRequest();

    /**
     * @brief Processes the Add Request
     * @note If the return is True, the Processing of the Request was Successful
     * @return bool
     */
    static bool processAddRequest();

    /**
     * @brief Processes the Remove Request
     * @note If the return is True, the Processing of the Request was Successful
     * @return bool
     */
    static bool processRemoveRequest();

    /**
     * @brief Processes the Change Request
     * @note If the return is True, the Processing of the Request was Successful
     * @return bool
     */
    static void processChangeRequest();

    /**
     * @brief Reverts the Last Change to the Student's Classes
     */
    static void revertLastChange();

    /**
     * @brief Prints the Processing Requests Success Logs
     */
    static void printRequestSuccessLogs();

    /**
     * @brief Prints the Processing Requests Fail Logs
     */
    static void printRequestFailLogs();

    /**
     * @brief Gets the Student's Ucs Count
     * @param studentNameOrCode
     * @return int Student Ucs Count
     */
    static int getStudentUcsNumber(string studentNameOrCode);

    /**
     * @brief Gets the Number of students Enrolled in a specific Class and Uc
     * @param studentNameOrCode
     * @return int Students Enrolled in a specific Class and Uc
     */
    static int getClassStudentsNumber(string classCode, string ucCode);

    /**
     * @brief Checks if the Given Uc Belongs to Given Class
     * @param ucCode Uc Code
     * @param classCode Class Code
     * @note If the return is True, the Uc Belongs to the Class
     * @return bool
     */
    static bool doesUcBelongToClass(string ucCode, string classCode);

    /**
     * @brief Checks if the Given Class of the Given Uc is Full
     * @param classCode Class Code
     * @param ucCode Uc Code
     * @note If the return is True, the Class of the Uc is Full
     * @return bool
     */
    static bool isClassFull(string classCode, string ucCode);

    /**
     * @brief Checks if the Difference in the Student Count of the Class of the Given Uc if Higher than the Maximum Difference in the Number of Students between Classes in order to Change a Student's Class
     * @param classCode Class Code
     * @param ucCode Uc Code
     * @return
     */
    static bool isChangeGapRespected(string classCode, string ucCode);

    /**
     * @brief Checks if the are no Overlapping TP or PL Classes in the Student Schedule After the Change
     * @param studentClassChange Student Class Change Information
     * @note If the return is True, the Change is Valid
     * @return bool
     */
    static bool isScheduleChangeValid(studentClassChange studentClassChange);
};

#endif //CODE_SCHEDULE_H
