#ifndef CODE_CLASS_H
#define CODE_CLASS_H

#include "structs.h"
#include "Class.h"
#include "Menu.h"

#include <stack>

class Class {
public:
    /**
     * @brief Checks if a class exists in the classes.csv file
     * @note Time Complexity: O(n)
     * @param classCode Class Code
     * @note If the return is true, the class exists
     * @return bool
     */
    static bool isClass(string classCode);

    /**
     * @brief Prints the Students in a Given Class
     * @param classCode Class Code
     * @param sortOption Sorted by Student Name or Student Number
     */
    static void printStudentsInAClass(string classCode, char sortOption);

    /**
     * @brief Gets the Uc Codes of a Given Class
     * @param classCode Class Code
     * @return vector<string> Uc Codes of a Given Class
     */
    static vector<string> getClassUcCodes(string classCode);

    /**
     * @brief Gets the Class Schedule of a Given Uc
     * @param classUcCodes Class Uc Codes
     * @return vector<classes> Class Schedule of a Given Uc
     */
    static vector<classes> getClassSchedule(string classUcCodes);

    // Prints the Students of a Class of a Given Uc
    /**
     * @brief Prints the Students of a Class of a Given Uc
     * @param classCode Class Code
     * @param ucCode Uc Code
     */
    static void printStudentsPerClassOfAGivenUc(string classCode, string ucCode);
};

#endif //CODE_CLASS_H
