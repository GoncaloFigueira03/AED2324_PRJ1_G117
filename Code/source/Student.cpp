
#include "Student.h"

Reader studentReader;

vector<string> StudentSchedule::getStudentClassCodes(std::string studentNameOrCode) {
    vector<string> studentClassCodes;

    vector<students_classes> readStudentsClasses = studentReader.read_students_classes();

    for (auto it_StudentsClasses:readStudentsClasses) {
        if (studentNameOrCode == it_StudentsClasses.StudentName || studentNameOrCode == it_StudentsClasses.StudentCode) {
            studentClassCodes.push_back(it_StudentsClasses.ClassCode);

        }
    }

    return studentClassCodes;
}

vector<string> StudentSchedule::getStudentUcCodes(std::string studentNameOrCode) {
    vector<string> studentUcCodes;

    vector<students_classes> readStudentsClasses = studentReader.read_students_classes();

    for (auto it_StudentsClasses:readStudentsClasses) {
        if (studentNameOrCode == it_StudentsClasses.StudentName || studentNameOrCode == it_StudentsClasses.StudentCode) {
            studentUcCodes.push_back(it_StudentsClasses.UcCode);

        }
    }

    return studentUcCodes;
}

list<string> StudentSchedule::pairStudentUcCodesWithClassCodes(vector<std::string> ucCodes, vector<std::string> classCodes) {
    list<string> studentUcCodesWithClassCodes;

    for (auto it_ucCodes:ucCodes) {
        for (auto it_classCodes:classCodes) {
            studentUcCodesWithClassCodes.push_back(it_ucCodes + it_classCodes);
        }
    }

    return studentUcCodesWithClassCodes;
}

vector<string> StudentSchedule::getStudentClasses(list<std::string> studentUcCodesWithClassCodes) {
    vector<string> studentClasses;

    vector<classes> readClasses = studentReader.read_classes();

    for (auto it_studentUcCodesWithClassCodes:studentUcCodesWithClassCodes) {
        for (auto it_readClasses:readClasses) {
            if (it_studentUcCodesWithClassCodes == it_readClasses.UcCode + it_readClasses.ClassCode) {
                studentClasses.push_back(it_readClasses.Weekday + " " + it_readClasses.StartHour + " " + it_readClasses.Duration + " " + it_readClasses.Type);

                cout << it_readClasses.Weekday + " " + it_readClasses.StartHour + " " + it_readClasses.Duration + " " + it_readClasses.Type << endl;
            }
        }
    }

    return studentClasses;
}

vector<string> StudentSchedule::getStudentSchedule(std::string studentNameOrCode) {
    vector<string> studentSchedule;

    vector<string> studentClassCodes = getStudentClassCodes(studentNameOrCode);
    vector<string> studentUcCodes = getStudentUcCodes(studentNameOrCode);

    list<string> studentUcCodesWithClassCodes = pairStudentUcCodesWithClassCodes(studentUcCodes, studentClassCodes);

    vector<string> studentClasses = getStudentClasses(studentUcCodesWithClassCodes);

    return studentClasses;
}