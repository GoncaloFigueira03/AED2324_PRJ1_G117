
#include "Sort.h"

vector<students_classes> Sort::sortStudentsClasses(vector<students_classes> studentsClasses) {
    for (int i = 0; i < studentsClasses.size(); i++) {
        for (int j = i + 1; j < studentsClasses.size(); j++) {
            if (studentsClasses[i].StudentCode > studentsClasses[j].StudentCode) {
                students_classes temp = studentsClasses[i];
                studentsClasses[i] = studentsClasses[j];
                studentsClasses[j] = temp;
            }
        }
    }

    return studentsClasses;
}