#include "Schedule.h"

Scheduler scheduler;

Reader studentClassesReader;

ScheduleWriter scheduleWriter(studentClassesReader);

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
    scheduler.lastChange.studentCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.newUcCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.newClassCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.studentName = StudentSchedule::getStudentName(scheduler.lastChange.studentCode);
    scheduler.requestQueue.push(scheduler.lastChange);
}

void Scheduler::removeUcFromStudent(queue <string> studentInfo) {
    scheduler.lastChange.studentCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.oldUcCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.oldClassCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.studentName = StudentSchedule::getStudentName(scheduler.lastChange.studentCode);
    scheduler.lastChange.newUcCode = "";
    scheduler.lastChange.newClassCode = "";
    scheduler.requestQueue.push(scheduler.lastChange);
}

void Scheduler::requestChangeInStudentClass(queue <string> studentInfo) {
    scheduler.lastChange.studentCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.newUcCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.newClassCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.oldUcCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.oldClassCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.studentName = StudentSchedule::getStudentName(scheduler.lastChange.studentCode);
    scheduler.requestQueue.push(scheduler.lastChange);
}

void Scheduler::processRequest() {
    scheduler.lastChange = scheduler.requestQueue.front();
    scheduler.requestQueue.pop();

    if (!(scheduler.getStudentUcsNumber(scheduler.lastChange.studentCode) <= scheduler.getMaxUcsPerStudent())) {
        cout << "The Processing Request Failed" << endl;
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentName + ", " + scheduler.lastChange.studentCode + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: " + scheduler.lastChange.studentName + " already has the Maximum Number of Ucs");

        return;
    }
    else if (isClassFull(scheduler.lastChange.newClassCode)) {
        cout << "The Processing Request Failed" << endl;
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: Class " + scheduler.lastChange.newClassCode + " is Full");

        return;
    }
    else if (!isChangeGapRespected(scheduler.lastChange.newClassCode)) {
        cout << "The Processing Request Failed" << endl;
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: The Class Change Gap is not Respected");

        return;
    }
    else if (!isScheduleChangeValid(scheduler.lastChange)) {
        cout << "The Processing Request Failed" << endl;
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: The Schedule enters in Conflict therefore is not Valid");

        return;
    }

    if(scheduleWriter.write()) {
        cout << "The Request was Processed Successfully" << endl;
        scheduler.studentsClassesChangesStack.push(scheduler.lastChange);
    }
    else
        cout << "The Processing Request Failed" << endl;
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: The Uc was not added to the Student Successfully (Unknown Error)");
}

void Scheduler::revertLastChange() {
    scheduler.lastChange = scheduler.studentsClassesChangesStack.top();
    scheduler.studentsClassesChangesStack.pop();

    string newUcCodeBuffer = scheduler.lastChange.newUcCode;
    string newClassCodeBuffer = scheduler.lastChange.newClassCode;

    scheduler.lastChange.newUcCode = scheduler.lastChange.oldUcCode;
    scheduler.lastChange.newClassCode = scheduler.lastChange.oldClassCode;
    scheduler.lastChange.oldUcCode = newUcCodeBuffer;
    scheduler.lastChange.oldClassCode = newClassCodeBuffer;

    if(scheduleWriter.write()) {
        cout << "The Reversion was Successful" << endl;

        return;
    }

    cout << "The Reversion was Not Successful" << endl;

    return;
}

void Scheduler::printRequests() {
    cout << "The Following Requests were Made:" << endl;
    for (int i = 0; i < scheduler.requestQueue.size(); i++) {
        cout << "UP" << scheduler.requestQueue.front().studentCode << ", " << scheduler.requestQueue.front().studentName << ", [" << scheduler.requestQueue.front().oldUcCode << ", " << scheduler.requestQueue.front().oldClassCode << "] -> [" << scheduler.requestQueue.front().newUcCode << ", " << scheduler.requestQueue.front().newClassCode << "]" << endl;
        scheduler.requestQueue.push(scheduler.requestQueue.front());
        scheduler.requestQueue.pop();
    }
}

void Scheduler::printRequestSuccessLogs() {
    cout << "The Following Requests were Successful:" << endl;
    for (int i=0; i < scheduler.studentsClassesChangesStack.size(); i++) {
        cout << "UP" << scheduler.studentsClassesChangesStack.top().studentCode << ", " << scheduler.studentsClassesChangesStack.top().studentName << ", [" << scheduler.studentsClassesChangesStack.top().oldUcCode << ", " << scheduler.studentsClassesChangesStack.top().oldClassCode << "] -> [" << scheduler.studentsClassesChangesStack.top().newUcCode << ", " << scheduler.studentsClassesChangesStack.top().newClassCode << "]" << endl;
        scheduler.studentsClassesChangesStack.push(scheduler.studentsClassesChangesStack.top());
        scheduler.studentsClassesChangesStack.pop();
    }
}

void Scheduler::printRequestFailLogs() {
    cout << "The Following Requests Failed:" << endl;
    for (auto it_processRequestFailedMessages:scheduler.processRequestFailedMessages) {
        cout << it_processRequestFailedMessages << endl;
    }
}