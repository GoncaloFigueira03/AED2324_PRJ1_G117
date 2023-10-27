
#include "Class.h"

Reader classReader;

vector<string> Class::getClassUcCodes(std::string classCode) {
    vector<string> classUcCodes;

    vector<classes> readClasses = classReader.read_classes();

    for (auto it_readClasses:readClasses) {
        if (classCode == it_readClasses.ClassCode) {
            classUcCodes.push_back(it_readClasses.UcCode);

            cout << it_readClasses.UcCode << endl;
        }
    }

    return classUcCodes;
}

vector<string> Class::getClassSchedulePerUc(string classUcCodes) {
    vector<string> classSchedulePerUc;

    vector<classes> readClasses = classReader.read_classes();

    for (auto it_readClasses:readClasses) {
        if (classUcCodes == it_readClasses.UcCode) {
            classSchedulePerUc.push_back(it_readClasses.Weekday);
            classSchedulePerUc.push_back(it_readClasses.StartHour);
            classSchedulePerUc.push_back(it_readClasses.Duration);
            classSchedulePerUc.push_back(it_readClasses.Type);

            cout << it_readClasses.Weekday << endl;
            cout << it_readClasses.StartHour << endl;
            cout << it_readClasses.Duration << endl;
            cout << it_readClasses.Type << endl;
        }
    }

    return classSchedulePerUc;
}

void Class::printClassSchedulePerUc(vector<std::string> classUcCodes) {
    for (auto it_classUcCodes:classUcCodes) {
        getClassSchedulePerUc(it_classUcCodes);
    }
}
/*
void Class::printStudentsPerClass(std::string classCode) {
    vector<string> studentsPerClass;

    vector<students_classes> readStudentsClasses = classReader.read_students_classes();

    for (auto it_readStudentsClasses:readStudentsClasses) {
        if (classCode == it_readStudentsClasses.ClassCode) {
            studentsPerClass.push_back(it_readStudentsClasses.StudentName);
            studentsPerClass.push_back(it_readStudentsClasses.StudentCode);

            cout << it_readStudentsClasses.StudentName << endl;
            cout << it_readStudentsClasses.StudentCode << endl;
        }
    }
}
*/