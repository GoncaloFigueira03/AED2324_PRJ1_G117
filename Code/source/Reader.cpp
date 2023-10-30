
#include "Reader.h"

vector<classes_per_uc> Reader::read_classes_per_uc() {
    vector<classes_per_uc> classesPerUc;

    ifstream fileClassesPerUc;

    fileClassesPerUc.open("../classes_per_uc.csv");
    if (!fileClassesPerUc.is_open()) {
        return classesPerUc;
    }

    string buffer;
    getline(fileClassesPerUc, buffer, '\n');
    while (getline(fileClassesPerUc, buffer, '\n')) {
        stringstream line(buffer);
        string newBuffer;
        classes_per_uc newClassPerUc;
        getline(line, newBuffer, ',');
        newClassPerUc.UcCode = newBuffer;
        getline(line, newBuffer, '\r');
        newClassPerUc.ClassCode = newBuffer;
        classesPerUc.push_back(newClassPerUc);
    }

    fileClassesPerUc.close();
    return classesPerUc;
}

vector<classes> Reader::read_classes() {
    vector<classes> readClasses;

    ifstream fileClasses;

    fileClasses.open("../classes.csv");
    if (!fileClasses.is_open()) {
        return readClasses;
    }

    string buffer;
    getline(fileClasses, buffer);
    while (getline(fileClasses, buffer)) {
        stringstream line(buffer);
        string newBuffer;
        classes newClass;
        getline(line, newBuffer, ',');
        newClass.ClassCode = newBuffer;
        getline(line, newBuffer, ',');
        newClass.UcCode = newBuffer;
        getline(line, newBuffer, ',');
        newClass.Weekday = newBuffer;
        getline(line, newBuffer, ',');
        newClass.StartHour = newBuffer;
        getline(line, newBuffer, ',');
        newClass.Duration = newBuffer;
        getline(line, newBuffer, '\r');
        newClass.Type = newBuffer;
        readClasses.push_back(newClass);
    }

    fileClasses.close();
    return readClasses;
}

vector<students_classes> Reader::read_students_classes() {
    vector<students_classes> studentClasses;

    ifstream fileStudentClasses;

    fileStudentClasses.open("../students_classes.csv");
    if (!fileStudentClasses.is_open()) {
        return studentClasses;
    }

    string buffer;
    getline(fileStudentClasses, buffer, '\n');
    while (getline(fileStudentClasses, buffer, '\n')) {
        stringstream line(buffer);
        string newBuffer;
        students_classes newStudentClass;
        getline(line, newBuffer, ',');
        newStudentClass.StudentCode = newBuffer;
        getline(line, newBuffer, ',');
        newStudentClass.StudentName = newBuffer;
        getline(line, newBuffer, ',');
        newStudentClass.UcCode = newBuffer;
        getline(line, newBuffer, '\r');
        newStudentClass.ClassCode = newBuffer;
        studentClasses.push_back(newStudentClass);
    }

    fileStudentClasses.close();
    return studentClasses;
}