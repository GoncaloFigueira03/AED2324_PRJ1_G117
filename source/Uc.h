#ifndef CODE_UC_H
#define CODE_UC_H

#include "structs.h"
#include "Class.h"
#include "Menu.h"

using namespace std;

class Uc {
public:
    /** @brief Checks if a given ucCode exists in the classes_per_uc file
     * @note Time Complexity: O(n)
     *  @param ucCode The ucCode to check
     *  @note If the return is true, the ucCode exists
     *  @return bool
     */
    static bool isUc(string ucCode);

    /** @brief Gets the Schedule of a Given Uc
     *  @param ucCode Uc Code
     *  @return vector<classes> Schedule of a Given Uc
     */
    static vector<classes> getUcSchedule(string ucCode);

    /** @brief Prints the Students in a Given Uc
     *  @param ucCode Uc Code
     */
    static void printStudentsInAUc(string ucCode);

    /** @brief Gets the Student Count of a Given Uc
     *  @param ucCode Uc Code
     *  @return int Student Count of a Given Uc
     */
    static int getStudentCount(string ucCode);
};

#endif //CODE_UC_H
