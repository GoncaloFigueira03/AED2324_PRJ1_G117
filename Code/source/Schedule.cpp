#include "Schedule.h"

Scheduler scheduler;

Reader studentClassesReader;

int Scheduler::getMaxStudentsPerClass() {
    return maxStudentsPerClass;
}

int Scheduler::getMaxStudentsPerClassChangeGap() {
    return maxStudentsPerClassChangeGap;
}

int Scheduler::getMaxUcsPerStudent() {
    return maxUcsPerStudent;
}

int Scheduler::getClassStudentsNumber(string classCode) {
    vector<students_classes> readStudentsClasses = studentClassesReader.read_students_classes();

    int studentCount = 0;

    for (auto it_readStudentsClasses:readStudentsClasses) {
        if (classCode == it_readStudentsClasses.ClassCode) {
            studentCount++;
        }
    }

    return studentCount;
}

int Scheduler::getClassStudentsNumberAvg(char classYear) {
    int avgStudentNumbers = 0;
    int count = 0;

    while (!Class::getClassStudentsNumbers(classYear).empty()) {
        avgStudentNumbers += Class::getClassStudentsNumbers(classYear).top();
        Class::getClassStudentsNumbers(classYear).pop();
        count++;
    }

    return avgStudentNumbers / count;
}

int Scheduler::getStudentUcsNumber(string studentCode) {
    vector<string> studentUcCodes = StudentSchedule::getStudentUcCodes(studentCode);

    return studentUcCodes.size();
}

bool Scheduler::doesUcBelongToClass(string ucCode, string classCode) {
    vector<string> classUcCodes = Class::getClassUcCodes(classCode);

    for (int i = 0; i < classUcCodes.size(); i++) {
        if (classUcCodes[i] == ucCode) {
            return true;
        }
    }

    return false;
}

bool Scheduler::isClassFull(string classCode) {
    if (getClassStudentsNumber(classCode) >= scheduler.getMaxStudentsPerClass()) {
        return true;
    }

    return false;
}

bool Scheduler::isChangeGapRespected(string classCode) {
    if (scheduler.getClassStudentsNumber(classCode) - scheduler.getClassStudentsNumberAvg(classCode[0]) <= scheduler.getMaxStudentsPerClassChangeGap()) {
        return true;
    }

    return false;
}

bool Scheduler::isScheduleChangeValid(studentClassChange studentClassChange) {
    vector<classes> studentClasses = StudentSchedule::getStudentSchedule(studentClassChange.studentCode);

    vector<classes> readClasses = studentClassesReader.read_classes();

    classes newStudentClass;

    if (studentClassChange.oldClassCode == "" && studentClassChange.oldUcCode == "") {
        for (auto it_readClasses: readClasses) {
            if (studentClassChange.newClassCode == it_readClasses.ClassCode && studentClassChange.newUcCode == it_readClasses.UcCode) {
                newStudentClass = it_readClasses;
            }
        }

        for (auto it_studentClasses: studentClasses) {
            if (it_studentClasses.Weekday == newStudentClass.Weekday &&
                it_studentClasses.StartHour == newStudentClass.StartHour
                && (it_studentClasses.Type == "TP" || it_studentClasses.Type == "PL") &&
                (newStudentClass.Type == "TP" || newStudentClass.Type == "PL")) {
                return false;
            }
        }
    }

    else {
        for (auto it_readClasses: readClasses) {
            if (studentClassChange.newClassCode == it_readClasses.ClassCode && studentClassChange.newUcCode == it_readClasses.UcCode) {
                newStudentClass = it_readClasses;
            }
        }

        for (auto it_studentClasses: studentClasses) {
            if (it_studentClasses.Weekday == newStudentClass.Weekday && it_studentClasses.StartHour == newStudentClass.StartHour && (it_studentClasses.Type == "TP" || it_studentClasses.Type == "PL") &&
                (newStudentClass.Type == "TP" || newStudentClass.Type == "PL") && it_studentClasses.ClassCode != studentClassChange.oldClassCode && it_studentClasses.UcCode != studentClassChange.oldUcCode) {
                return false;
            }
        }
    }

    return true;
}

void Scheduler::addUcToStudent(queue <string> studentInfo) {
    studentClassChange studentClassChange;

    studentClassChange.studentCode = studentInfo.front();
    studentInfo.pop();

    studentClassChange.newUcCode = studentInfo.front();
    studentInfo.pop();

    studentClassChange.newClassCode = studentInfo.front();
    studentInfo.pop();

    if (!scheduler.getStudentUcsNumber(studentClassChange.studentCode) <= scheduler.getMaxUcsPerStudent()) {
        cout << "The Student already has the Maximum Number of Ucs" << endl;
        return;
    }
    else if (!scheduler.doesUcBelongToClass(studentClassChange.newUcCode, studentClassChange.newClassCode)) {
        cout << "The Uc does not belong to the Class" << endl;
        return;
    }
    else if (!isClassFull(studentClassChange.newClassCode)) {
        cout << "The Class is Full" << endl;
        return;
    }
    else if (!isChangeGapRespected(studentClassChange.newClassCode)) {
        cout << "The Class Change Gap is not Respected" << endl;
        return;
    }
    else if (!isScheduleChangeValid(studentClassChange)) {
        cout << "The Schedule enters in Conflict therefore is not Valid" << endl;
        return;
    }

    studentClassChange.studentFullName = StudentSchedule::getStudentFullName(studentClassChange.studentCode);

    scheduler.studentsClassesChangesStack.push(studentClassChange);

    cout << "The Uc was added to the Student Successfully" << endl;
    return;
}

void Scheduler::requestChangeInStudentClass(studentClassChange studentClassChange) {
    if (scheduler.isClassFull(studentClassChange.newClassCode)) {
        cout << "The Class is Full" << endl;
        return;
    }
    else if (!scheduler.isChangeGapRespected(studentClassChange.newClassCode)) {
        cout << "The Class Change Gap is not Respected" << endl;
        return;
    }
    else if (!scheduler.isScheduleChangeValid(studentClassChange)) {
        cout << "The Schedule enters in Conflict therefore is not Valid" << endl;
        return;
    }
}