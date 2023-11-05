
#include "Writer.h"

ScheduleWriter::ScheduleWriter(Reader &reader) { }

bool ScheduleWriter::write(studentClassChange lastChange) {

    ofstream outputFile;
    outputFile.open("../students_classes_output.csv");
    if (!outputFile.is_open()) {
        cout << "Could not open file" << endl;

        return false;
    }

    outputFile << "StudentCode,StudentName,UcCode,ClassCode\n";

    vector<students_classes> readStudentsClasses = reader.read_students_classes();

    for (auto it_readStudentClasses: readStudentsClasses) {
        if (it_readStudentClasses.StudentCode == lastChange.studentCode && it_readStudentClasses.StudentName == lastChange.studentName && it_readStudentClasses.UcCode == lastChange.oldUcCode && it_readStudentClasses.ClassCode == lastChange.oldClassCode) {
            continue;
        }
        else {
            outputFile << it_readStudentClasses.StudentCode << "," << it_readStudentClasses.StudentName << "," << it_readStudentClasses.UcCode << "," << it_readStudentClasses.ClassCode << "\n";
        }
    }

    if (lastChange.newClassCode != "" && lastChange.newUcCode != "") {
        outputFile << lastChange.studentCode << "," << lastChange.studentName << "," << lastChange.newUcCode << "," << lastChange.newClassCode << "\n";
    }

    outputFile.close();

    remove("../students_classes.csv");
    rename("../students_classes_output.csv", "../students_classes.csv");

    if (writeChanges(lastChange) == false) {
        cout << "Could not log the changes to the file" << endl;
    }

    return true;
}

bool ScheduleWriter::writeChanges(studentClassChange lastChange) {

    ofstream changeFile;
    changeFile.open("../changes_output.csv");
    if (!changeFile.is_open()) {
        cout << "Could not open file" << endl;

        return false;
    }

    changeFile << "Type,StudentCode,StudentName,OldUcCode,OldClassCode,NewUcCode,NewClassCode\n";
    changeFile << lastChange.type << "," << lastChange.studentCode << "," << lastChange.studentName << "," << lastChange.oldUcCode << "," << lastChange.oldClassCode << "," << lastChange.newUcCode << "," << lastChange.newClassCode << "\n";

    for (auto it_readChange: reader.read_changes()) {
        changeFile << it_readChange.type << "," << it_readChange.studentCode << "," << it_readChange.studentName << "," << it_readChange.oldUcCode << "," << it_readChange.oldClassCode << "," << it_readChange.newUcCode << "," << it_readChange.newClassCode << "\n";
    }

    changeFile.close();

    remove("../changes.csv");
    rename("../changes_output.csv", "../changes.csv");

    return true;
}