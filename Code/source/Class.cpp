
#include "Class.h"

Reader classReader;

bool Class::isClass(std::string classCode) {
    vector<classes> readClasses = classReader.read_classes();

    for (auto it_readClasses:readClasses) {
        if (classCode == it_readClasses.ClassCode) {
            return true;
        }
    }

    return false;
}

void Class::printStudentsInAClass(std::string classCode) {
    vector<students_classes> readStudentsClasses = classReader.read_students_classes();

    stack<students_classes> studentsClassesStack;

    for (auto it_readStudentsClasses:readStudentsClasses) {
        if (classCode == it_readStudentsClasses.ClassCode) {
            if (studentsClassesStack.empty())
                studentsClassesStack.push(it_readStudentsClasses);

            else if (studentsClassesStack.top().StudentCode != it_readStudentsClasses.StudentCode ) {
                studentsClassesStack.push(it_readStudentsClasses);
            }
        }
    }

    cout << endl;

    while (!studentsClassesStack.empty()) {
        cout << studentsClassesStack.top().StudentName + ' ' + studentsClassesStack.top().StudentCode << endl;
        studentsClassesStack.pop();
    }
}

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

stack<int> Class::getClassStudentsNumbers(char classYear) {
    stack<int> classStudentsNumbers;

    vector<string> classCodes;

    vector<students_classes> readStudentClasses = classReader.read_students_classes();

    for (auto it_readStudentClasses:readStudentClasses) {
        if (classYear == it_readStudentClasses.ClassCode[0]) {
            classCodes.push_back(it_readStudentClasses.ClassCode);
        }
    }

    for (auto it_classCodes:classCodes) {
        int classStudentsNumber = 0;

        for (auto it_readStudentClasses:readStudentClasses) {
            if (it_classCodes == it_readStudentClasses.ClassCode) {
                classStudentsNumber++;
            }
        }

        classStudentsNumbers.push(classStudentsNumber);
    }

    return classStudentsNumbers;
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

    stack<students_classes> studentsClassesStack;

    for (auto it_readStudentsClasses:readStudentsClasses) {
        if (classCode == it_readStudentsClasses.ClassCode && ucCode == it_readStudentsClasses.UcCode) {
            if (studentsClassesStack.empty())
                studentsClassesStack.push(it_readStudentsClasses);

            else if (studentsClassesStack.top().StudentCode != it_readStudentsClasses.StudentCode ) {
                studentsClassesStack.push(it_readStudentsClasses);
            }
        }
    }

    cout << endl;

    while (!studentsClassesStack.empty()) {
        cout << studentsClassesStack.top().StudentName + ' ' + studentsClassesStack.top().StudentCode << endl;
        studentsClassesStack.pop();
    }
}