
#include "Uc.h"

Reader ucReader;

bool Uc::isUc(string ucCode) {
    vector<classes_per_uc> readUcs = ucReader.read_classes_per_uc();

    for (auto it_readUcs:readUcs) {
        if (ucCode == it_readUcs.UcCode) {
            return true;
        }
    }

    return false;
}

vector<classes> Uc::getUcSchedule(string ucCode) {
    vector<classes> ucSchedule;

    vector<classes> readClasses = ucReader.read_classes();

    for (auto it_readClasses:readClasses) {
        if (it_readClasses.UcCode == ucCode) {
            ucSchedule.push_back(it_readClasses);
        }
    }

    return ucSchedule;
}

void Uc::printStudentsInAUc(string ucCode) {
    vector<students_classes> readStudentInAUc = ucReader.read_students_classes();

    stack<students_classes> studentsInAUcStack;

    for (auto it_readStudentInAUc:readStudentInAUc) {
        if (it_readStudentInAUc.UcCode == ucCode) {
            studentsInAUcStack.push(it_readStudentInAUc);
        }
    }

    while (!studentsInAUcStack.empty()) {
        cout << studentsInAUcStack.top().StudentCode + ' ' + studentsInAUcStack.top().StudentName << endl;
        studentsInAUcStack.pop();
    }
}

int Uc::getStudentCount(string ucCode) {
    int classStudentsNumbers;

    vector<students_classes> readStudentClasses = ucReader.read_students_classes();

    for (auto it_readStudentClasses:readStudentClasses) {
        if (ucCode == it_readStudentClasses.UcCode) {
            classStudentsNumbers++;
        }
    }

    return classStudentsNumbers;
}