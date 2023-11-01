
#include "Writer.h"

ScheduleWriter::ScheduleWriter(Reader &reader) { }

bool ScheduleWriter::write(studentClassChange studentClassChange) {

    ofstream outputFile;
    outputFile.open("../students_classes_output.csv");
    if (!outputFile.is_open()) {
        cout << "Could not open file" << endl;

        return false;
    }

    outputFile << "StudentCode,StudentName,UcCode,ClassCode\r\n";

    vector<students_classes> readStudentsClasses = reader.read_students_classes();

    for (auto it_readStudentClasses:readStudentsClasses) {
        if (it_readStudentClasses.StudentCode == studentClassChange.studentCode && it_readStudentClasses.UcCode == studentClassChange.oldUcCode && it_readStudentClasses.ClassCode == studentClassChange.oldClassCode) {
            continue;
        }
        else {
            outputFile << it_readStudentClasses.StudentCode << "," << it_readStudentClasses.StudentName << "," << it_readStudentClasses.UcCode << "," << it_readStudentClasses.ClassCode << "\r\n";
        }
    }

    outputFile.close();

    remove("../students_classes.csv");
    rename("../students_classes_output.csv", "../students_classes.csv");

    return true;
}