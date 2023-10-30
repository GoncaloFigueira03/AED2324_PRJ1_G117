#include "Menu.h"

Reader reader;

vector<classes_per_uc> readClassesPerUc = reader.read_classes_per_uc();

vector<classes> readClasses = reader.read_classes();

vector<students_classes> readStudentsClasses = reader.read_students_classes();

void Menu::viewStudentSchedule(std::string studentNameOrCode) {
    cout << "Student " + studentNameOrCode + " Schedule is:" << endl;

    for (auto it_StudentsClasses:readStudentsClasses) {
        if (studentNameOrCode == it_StudentsClasses.StudentName || studentNameOrCode == it_StudentsClasses.StudentCode) {
            cout << it_StudentsClasses.ClassCode + ' ' + it_StudentsClasses.UcCode << endl;
        }
    }
}

void Menu::viewClassSchedule(std::string classCode) {

}

void Menu::viewUcSchedule(std::string ucCode) {

}