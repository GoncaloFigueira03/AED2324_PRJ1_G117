
#include "Student.h"

Reader studentReader;

vector<string> StudentSchedule::getStudentClassCodes(std::string studentNameOrCode) {
    vector<string> studentClassCodes;

    vector<students_classes> readStudentsClasses = studentReader.read_students_classes();

    for (auto it_StudentsClasses:readStudentsClasses) {
        if (studentNameOrCode == it_StudentsClasses.StudentName || studentNameOrCode == it_StudentsClasses.StudentCode) {
            studentClassCodes.push_back(it_StudentsClasses.ClassCode);

            cout << it_StudentsClasses.ClassCode << endl;
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

            cout << it_StudentsClasses.UcCode << endl;
        }
    }

    return studentUcCodes;

}