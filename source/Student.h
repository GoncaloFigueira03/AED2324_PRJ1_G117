#ifndef CODE_STUDENT_H
#define CODE_STUDENT_H

#include "structs.h"
#include "App.h"
#include "Menu.h"
#include "Sort.h"

using namespace std;

class StudentSchedule {
public:
    /**
     * @brief Checks if a student exists in the students_classes.csv file
     * @param studentCode Student Code
     * @note If the return is true, the student exists
     * @return bool
     */
    static bool isStudent(string studentCode);

    /**
     * @brief Checks if a Student is enrolled in a Class of a certain Uc
     * @param studentCode Student Code
     * @param classCode Class Code
     * @param ucCode Uc Code
     * @note If the return is true, the student is enrolled in the class
     * @return bool
     */
    static bool doesClassBelongToStudent(string studentCode, string classCode, string ucCode);

    /**
     * @brief Gets the Student Code
     * @param studentNameOrCode Student Name or Code
     * @return string Student Code
     */
    static string getStudentCode(string studentNameOrCode);

    /**
     * @brief Gets the Student Name
     * @param studentCode Student Code
     * @return string Student Name
     */
    static string getStudentName(string studentCode);

    /**
     * @brief Gets the Student Classes
     * @param studentCode Student Code
     * @return vector<string> Student Class Codes
     */
    static vector<string> getStudentClassCodes(string studentCode);

    /**
     * @brief Gets the Student Ucs
     * @param studentCode Student Code
     * @return vector<string> Student Ucs
     */
    static vector<string> getStudentUcCodes(string studentCode);

    /**
     * @brief Pairs the Student Ucs with the Student Classes in a list
     * @param ucCodes Uc Codes
     * @param classCodes Class Codes
     * @return list<string> Student Uc Codes with Class Codes
     */
    static list<string> pairStudentUcCodesWithClassCodes(vector<string> ucCodes, vector<string> classCodes);

    /**
     * @brief Gets the Student Classes
     * @param studentUcCodesWithClassCodes List with Student Uc Codes and Class Codes
     * @return vector<classes> Student Classes
     */
    static vector<classes> getStudentClasses(list<string> studentUcCodesWithClassCodes);

    /**
     * @brief Gets the Student Schedule without Overlapping Classes
     * @param studentCode Student Code
     * @return vector<classes> Student Schedule
     */
    static vector<classes> getStudentSchedule(string studentCode);

    /**
     * @brief Prints the Student Classes
     * @param studentCode Student Code
     */
    static void printStudentClasses(string studentCode);

    /**
     * @brief Prints the Student Ucs
     * @param studentCode Student Code
     */
    static void printStudentUcs(string studentCode);

    /**
     * @brief Checks if there are Overlapping T Classes with PL or TP Classes
     * @param tClass T Class
     * @param secondClass Second Class
     * @note If the return is true, there are Overlapping T Classes with PL or TP Classes
     * @return bool
     */
    static bool isTClassOverTPOrPL(classes tClass, classes secondClass);
};
#endif //CODE_STUDENT_H
