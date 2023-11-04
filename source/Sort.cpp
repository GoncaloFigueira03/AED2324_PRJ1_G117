
#include "Sort.h"

vector<students_classes> Sort::sortStudentsClasses(vector<students_classes> studentsClasses) {
    vector<students_classes> sortedStudentsClasses;

    for (auto it_StudentsClasses:studentsClasses) {
        if (sortedStudentsClasses.empty()) {
            sortedStudentsClasses.push_back(it_StudentsClasses);
        }
        else {
            bool inserted = false;
            for (auto it_SortedStudentsClasses:sortedStudentsClasses) {
                if (it_StudentsClasses.StudentCode > it_SortedStudentsClasses.StudentCode) {
                    sortedStudentsClasses.insert(sortedStudentsClasses.begin(), it_StudentsClasses);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                sortedStudentsClasses.push_back(it_StudentsClasses);
            }
        }
    }

    return sortedStudentsClasses;
}