
#include "Uc.h"

Reader ucReader;

vector<string> Uc::getUcClassCodes(std::string ucCode) {
    vector<string> ucClassCodes;

    vector<classes_per_uc> readClassesPerUc = ucReader.read_classes_per_uc();

    for (auto it_readClassesPerUc:readClassesPerUc) {
        if (it_readClassesPerUc.UcCode == ucCode) {
            ucClassCodes.push_back(it_readClassesPerUc.ClassCode);
        }
    }

    return ucClassCodes;
}

vector<classes> Uc::getUcSchedule(std::string ucCode) {
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
    vector<string> studentsInAUc;

    vector<students_classes> readStudentInAUc = ucReader.read_students_classes();

    for (auto it_readStudentInAUc:readStudentInAUc) {
        if (it_readStudentInAUc.UcCode == ucCode) {
            studentsInAUc.push_back(it_readStudentInAUc.StudentName);

            cout << it_readStudentInAUc.StudentName << endl;
        }
    }
}