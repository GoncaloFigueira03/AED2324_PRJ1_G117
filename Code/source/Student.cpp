
#include "Student.h"

Reader studentReader;

bool StudentSchedule::isStudent(string studentNameOrCode) {
    vector<students_classes> readStudents = studentReader.read_students_classes();

    for (auto it_Students:readStudents) {
        if (studentNameOrCode == it_Students.StudentCode || studentNameOrCode == it_Students.StudentName) {
            return true;
        }
    }

    return false;
}

string StudentSchedule::getStudentCode(string studentFullName) {
    vector<students_classes> readStudents = studentReader.read_students_classes();

    for (auto it_Students:readStudents) {
        if (studentFullName == it_Students.StudentName) {
            return it_Students.StudentCode;
        }
    }
}

string StudentSchedule::getStudentFullName(string studentNameOrCode) {
    vector<students_classes> readStudents = studentReader.read_students_classes();

    vector<string> studentNames;

    string studentFullName;

    for (auto it_Students:readStudents) {
        if (studentNameOrCode == it_Students.StudentCode) {
            return it_Students.StudentName;
        }

        else if (studentNameOrCode == it_Students.StudentName) {
            studentNames.push_back(it_Students.StudentName);
        }
    }

    cout << "There are multiple students with the same name, please choose one:" << endl;
    for (auto it_studentNames: studentNames) {
        cout << it_studentNames << endl;
    }
    while (true) {
        cin >> studentFullName;
        for (auto it_studentNames: studentNames) {
            if (studentFullName == it_studentNames) {
                return it_studentNames;
            }
            else {
                cout << "Please choose a valid student name" << endl;
            }
        }
    }
}

vector<string> StudentSchedule::getStudentClassCodes(string studentCode) {
    vector<string> studentClassCodes;

    vector<students_classes> readStudentsClasses = studentReader.read_students_classes();

    for (auto it_StudentsClasses:readStudentsClasses) {
        if (studentCode == it_StudentsClasses.StudentCode) {
            studentClassCodes.push_back(it_StudentsClasses.ClassCode);

        }
    }

    return studentClassCodes;
}

vector<string> StudentSchedule::getStudentUcCodes(string studentCode) {
    vector<string> studentUcCodes;

    vector<students_classes> readStudentsClasses = studentReader.read_students_classes();

    for (auto it_StudentsClasses:readStudentsClasses) {
        if (studentCode == it_StudentsClasses.StudentCode) {
            studentUcCodes.push_back(it_StudentsClasses.UcCode);
        }
    }

    return studentUcCodes;
}

list<string> StudentSchedule::pairStudentUcCodesWithClassCodes(vector<string> ucCodes, vector<string> classCodes) {
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

vector<classes> StudentSchedule::getStudentClasses(list<string> studentUcCodesWithClassCodes) {
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

vector<classes> StudentSchedule::getStudentSchedule(string studentCode) {
    vector<string> studentClassCodes = getStudentClassCodes(studentCode);
    vector<string> studentUcCodes = getStudentUcCodes(studentCode);

    list<string> studentUcCodesWithClassCodes = pairStudentUcCodesWithClassCodes(studentUcCodes, studentClassCodes);

    vector<classes> studentClasses = getStudentClasses(studentUcCodesWithClassCodes);

    return studentClasses;
}

void StudentSchedule::printStudentClasses(string studentCode) {
    vector<string> studentClassCodes = getStudentClassCodes(studentCode);

    for (auto it_studentClassCodes:studentClassCodes) {
        cout << it_studentClassCodes << endl;
    }
}

void StudentSchedule::printStudentUcs(string studentCode) {
    vector<string> studentUcCodes = getStudentUcCodes(studentCode);

    for (auto it_studentUcCodes:studentUcCodes) {
        cout << it_studentUcCodes << endl;
    }
}