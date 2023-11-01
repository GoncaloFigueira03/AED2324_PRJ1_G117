
#include "Writer.h"

Scheduler writeScheduler;

ScheduleWriter::ScheduleWriter(Reader &reader) { }

bool ScheduleWriter::write() {

    ofstream outputFile;
    outputFile.open("../students_classes_output.csv");
    if (!outputFile.is_open()) {
        cout << "Could not open file" << endl;

        return false;
    }

    outputFile << "StudentCode,StudentName,UcCode,ClassCode\r\n";

    vector<students_classes> readStudentsClasses = reader.v_students_classes;

    for (auto it_readStudentClasses: readStudentsClasses) {
        if (!(it_readStudentClasses.StudentCode == writeScheduler.lastChange.studentCode &&
              it_readStudentClasses.UcCode == writeScheduler.lastChange.oldUcCode &&
              it_readStudentClasses.ClassCode == writeScheduler.lastChange.oldClassCode)) {
            outputFile << it_readStudentClasses.StudentCode << "," << it_readStudentClasses.StudentName << ","
                       << it_readStudentClasses.UcCode << "," << it_readStudentClasses.ClassCode << "\r\n";
        }
    }

    if (writeScheduler.lastChange.newClassCode != "") {
        outputFile << writeScheduler.lastChange.studentCode << "," << writeScheduler.lastChange.studentName << ","
                   << writeScheduler.lastChange.newUcCode << "," << writeScheduler.lastChange.newClassCode << "\r\n";
    }

    outputFile.close();

    remove("../students_classes.csv");
    rename("../students_classes_output.csv", "../students_classes.csv");

    return true;
}