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

int Scheduler::getStudentUcsNumber(string studentNameOrCode) {
    vector<string> studentUcCodes = StudentSchedule::getStudentUcCodes(studentNameOrCode);

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

bool Scheduler::isScheduleChangeValid(string studentNameOrCode, string newClassCode, string newUcCode, string oldClassCode, string oldUcCode) {
    vector<classes> studentClasses = StudentSchedule::getStudentSchedule(studentNameOrCode);

    vector<classes> readClasses = studentClassesReader.read_classes();

    classes newStudentClass;

    if (oldClassCode == "" && oldUcCode == "") {
        for (auto it_readClasses: readClasses) {
            if (newClassCode == it_readClasses.ClassCode && newUcCode == it_readClasses.UcCode) {
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
            if (newClassCode == it_readClasses.ClassCode && newUcCode == it_readClasses.UcCode) {
                newStudentClass = it_readClasses;
            }
        }

        for (auto it_studentClasses: studentClasses) {
            if (it_studentClasses.Weekday == newStudentClass.Weekday && it_studentClasses.StartHour == newStudentClass.StartHour && (it_studentClasses.Type == "TP" || it_studentClasses.Type == "PL") &&
                (newStudentClass.Type == "TP" || newStudentClass.Type == "PL") && it_studentClasses.ClassCode != oldClassCode && it_studentClasses.UcCode != oldUcCode) {
                return false;
            }
        }
    }

    return true;
}

void Scheduler::addUcToStudent(queue <string> studentInfo) {
    string studentNameOrCode = studentInfo.front();
    studentInfo.pop();

    string ucCode = studentInfo.front();
    studentInfo.pop();

    string classCode = studentInfo.front();
    studentInfo.pop();

    if (!scheduler.getStudentUcsNumber(studentNameOrCode) <= scheduler.getMaxUcsPerStudent()) {
        cout << "The Student already has the Maximum Number of Ucs" << endl;
        return;
    }
    else if (!scheduler.doesUcBelongToClass(ucCode, classCode)) {
        cout << "The Uc does not belong to the Class" << endl;
        return;
    }
    else if (!isClassFull(classCode)) {
        cout << "The Class is Full" << endl;
        return;
    }
    else if (!isChangeGapRespected(classCode)) {
        cout << "The Class Change Gap is not Respected" << endl;
        return;
    }
    else if (!isScheduleChangeValid(studentNameOrCode, classCode, ucCode, "", "")) {
        cout << "The Schedule enters in Conflict therefore is not Valid" << endl;
        return;
    }

    studentClassChange studentClassChange;

    studentClassChange.studentNameOrCode = studentNameOrCode;
    studentClassChange.newClassCode = classCode;
    studentClassChange.newUcCode = ucCode;

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
    else if (!scheduler.isScheduleChangeValid(studentClassChange.studentNameOrCode, studentClassChange.newClassCode, studentClassChange.newUcCode,
                                              studentClassChange.oldClassCode, studentClassChange.oldUcCode)) {
        cout << "The Schedule enters in Conflict therefore is not Valid" << endl;
        return;
    }
}