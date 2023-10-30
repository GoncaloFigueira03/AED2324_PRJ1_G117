
#include "Class.h"

Reader classReader;

vector<string> Class::getClassUcCodes(string classCode) {
    vector<string> classUcCodes;

    vector<classes> readClasses = classReader.read_classes();

    for (auto it_readClasses:readClasses) {
        if (classCode == it_readClasses.ClassCode) {
            classUcCodes.push_back(it_readClasses.UcCode);
        }
    }

    return classUcCodes;
}

classes Class::getClassSchedulePerUc(string classUcCode) {
    classes classSchedulePerUc;

    vector<classes> readClasses = classReader.read_classes();

    for (auto it_readClasses:readClasses) {
        if (classUcCode == it_readClasses.UcCode) {
            classSchedulePerUc = it_readClasses;
        }
    }

    return classSchedulePerUc;
}

vector<classes> Class::getClassSchedule(string classCode) {
    vector<classes> classSchedule;

    vector<classes> readClasses = classReader.read_classes();

    for (auto it_readClasses:readClasses) {
        if (classCode == it_readClasses.ClassCode) {
            classSchedule.push_back(it_readClasses);
        }
    }

    return classSchedule;
}

void Class::printStudentsPerClassOfAGivenUc(std::string classCode, std::string ucCode) {
    vector<students_classes> readStudentsClasses = classReader.read_students_classes();

    for (auto it_readStudentsClasses:readStudentsClasses) {
        if (classCode == it_readStudentsClasses.ClassCode && ucCode == it_readStudentsClasses.UcCode) {
            cout << it_readStudentsClasses.StudentName + ' ' + it_readStudentsClasses.StudentCode << endl;
        }
    }
}