
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

void Class::printStudentsInAClass(string classCode, char sortOption) {
    vector<students_classes> readStudentsClasses = classReader.read_students_classes();

    stack<students_classes> studentsClassesStack;
    stack<students_classes> studentsClassesStackTmp;

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

    if (sortOption == 'C' || sortOption == 'c') {
        while (!studentsClassesStack.empty()){
            students_classes studentsClassesTmp = studentsClassesStack.top();
            studentsClassesStack.pop();

            while (!studentsClassesStackTmp.empty() && studentsClassesStackTmp.top().StudentCode < studentsClassesTmp.StudentCode) {
                studentsClassesStack.push(studentsClassesStackTmp.top());
                studentsClassesStackTmp.pop();
            }

            studentsClassesStackTmp.push(studentsClassesTmp);
        }
    }
    else if (sortOption == 'N' || sortOption == 'n') {
        while (!studentsClassesStack.empty()){
            students_classes studentsClassesTmp = studentsClassesStack.top();
            studentsClassesStack.pop();

            while (!studentsClassesStackTmp.empty() && studentsClassesTmp.StudentName > studentsClassesStackTmp.top().StudentName) {
                studentsClassesStack.push(studentsClassesStackTmp.top());
                studentsClassesStackTmp.pop();
            }

            studentsClassesStackTmp.push(studentsClassesTmp);
        }
    }

    while (!studentsClassesStackTmp.empty()) {
        cout << studentsClassesStackTmp.top().StudentCode + ' ' + studentsClassesStackTmp.top().StudentName << endl;
        studentsClassesStackTmp.pop();
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

stack<int> Class::getClassStudentsNumbers(char classYear, string ucCode) {
    stack<int> classStudentsNumbers;

    vector<string> classCodes;

    vector<students_classes> readStudentClasses = classReader.read_students_classes();

    for (auto it_readStudentClasses:readStudentClasses) {
        if (classYear == it_readStudentClasses.ClassCode[0] && ucCode == it_readStudentClasses.UcCode) {
            classCodes.push_back(it_readStudentClasses.UcCode);
        }
    }

    for (auto it_classCodes:classCodes) {
        int classStudentsNumber = 0;

        for (auto it_readStudentClasses:readStudentClasses) {
            if (it_classCodes == it_readStudentClasses.UcCode) {
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