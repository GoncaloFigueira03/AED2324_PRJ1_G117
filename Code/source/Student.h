
#ifndef CODE_STUDENT_H
#define CODE_STUDENT_H

#include "structs.h"
#include "App.h"
#include "Menu.h"

using namespace std;

class StudentSchedule {
public:
    // Is Student a Real Student
    static bool isStudent(string studentCode);

    // Gets Student Code
    static string getStudentCode(string studentNameOrCode);

    // Gets the Class Codes of a Student
    static vector<string> getStudentClassCodes(string studentCode);

    // Gets the Uc Codes of a Student
    static vector<string> getStudentUcCodes(string studentCode);

    // Pairs the Uc Codes with the Class Codes
    static list<string> pairStudentUcCodesWithClassCodes(vector<string> ucCodes, vector<string> classCodes);

    // Outputs a Vector with the Classes of a Student
    static vector<classes> getStudentClasses(list<string> studentUcCodesWithClassCodes);

    // Outputs a Vector with the Final Schedule of a Student (without overlapping classes)
    static vector<classes> getStudentSchedule(string studentCode);

    // Prints the Student Classes
    static void printStudentClasses(string studentCode);

    // Prints the Student Ucs
    static void printStudentUcs(string studentCode);

    // Checks if there are Overlapping T Classes with PL or TP Classes
    static bool isTClassOverTPOrPL(classes tClass, classes secondClass);

    // Different version of isTClassOverTPOrPL (still work in progress)
    static void isTClassOverTPOrPLV2(classes tClass, vector<classes> secondClasses, vector<classes> studentClassesFixed);

};
#endif //CODE_STUDENT_H
