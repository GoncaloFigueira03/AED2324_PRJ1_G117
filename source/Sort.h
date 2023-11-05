#ifndef CODE_SORT_H
#define CODE_SORT_H

#include "structs.h"
#include "Reader.h"

class Sort {
public:
    /**
     * @brief Sorts a vector of students_classes by the number of students
     * ;complexity O(n^2)
     * @param students_classes It's the vector of students_classes to be sorted
     * @return vector<students_classes> It's the sorted vector of students_classes
     */
    static vector<students_classes> sortStudentsClasses(vector<students_classes> studentsClasses);
};

#endif //CODE_SORT_H
