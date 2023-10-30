
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

void StudentSchedule::isTClassOverTPOrPLV2(classes tClass, vector<classes> secondClasses, vector<classes> studentClassesFixed) {
    for (auto it_secondClasses:secondClasses) {
        if (tClass.Weekday == it_secondClasses.Weekday && ((stoi(tClass.StartHour) + stoi(tClass.Duration)) > stoi(it_secondClasses.StartHour))) {
            break;
        }
        else {
            studentClassesFixed.push_back(tClass);
        }
    }
}

bool StudentSchedule::isTClassOverTPOrPL(classes tClass, classes secondClass) {
    if (tClass.Weekday == secondClass.Weekday &&
        ((stoi(tClass.StartHour) + stoi(tClass.Duration)) > stoi(secondClass.StartHour))) {
        return true;
    }

    return false;
}

vector<classes> StudentSchedule::getStudentClasses(list<std::string> studentUcCodesWithClassCodes) {
    vector<classes> studentClasses;
    vector<classes> studentClassesFixed;

    vector<classes> readClasses = studentReader.read_classes();

    for (auto it_studentUcCodesWithClassCodes:studentUcCodesWithClassCodes) {
        for (auto it_readClasses:readClasses) {
            if (it_studentUcCodesWithClassCodes == it_readClasses.UcCode + it_readClasses.ClassCode) {
                studentClasses.push_back(it_readClasses);
            }
        }
    }

    for (auto it_studentClasses:studentClasses) {
        if (it_studentClasses.Type == "T") {
            for (auto it_studentClasses2:studentClasses) {
                if (it_studentClasses2.Type == "PL" || it_studentClasses2.Type == "TP") {
                    if (isTClassOverTPOrPL(it_studentClasses, it_studentClasses2)) {
                        break;
                    }
                }
                else {
                    studentClassesFixed.push_back(it_studentClasses);
                }
            }
        }
        else {
            studentClassesFixed.push_back(it_studentClasses);
        }
    }

/*
    for (auto it_studentClasses:studentClasses) {
        if (it_studentClasses.Type == "T") {
            StudentSchedule::isTClassOverTPOrPLV2(it_studentClasses, studentClasses, studentClassesFixed);
        }
        else
            studentClassesFixed.push_back(it_studentClasses);
    }
*/

    return studentClassesFixed;
}

vector<classes> StudentSchedule::getStudentSchedule(string studentNameOrCode) {
    vector<string> studentClassCodes = getStudentClassCodes(studentNameOrCode);
    vector<string> studentUcCodes = getStudentUcCodes(studentNameOrCode);

    list<string> studentUcCodesWithClassCodes = pairStudentUcCodesWithClassCodes(studentUcCodes, studentClassCodes);

    vector<classes> studentClasses = getStudentClasses(studentUcCodesWithClassCodes);

    return studentClasses;
}