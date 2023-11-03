#include "Schedule.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

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

int Scheduler::getClassStudentsNumber(string classCode, string ucCode) {
    vector<students_classes> readStudentsClasses = studentClassesReader.read_students_classes();

    int count = 0;

    for (auto it_readStudentsClasses:readStudentsClasses) {
        if (it_readStudentsClasses.ClassCode == classCode && it_readStudentsClasses.UcCode == ucCode) {
            count++;
        }
    }

    return count;
}

int Scheduler::getClassStudentsNumberAvg(char classYear, string ucCode) {
    int totalStudentsInClassYear = 0;
    int numberOfClassesInClassYear = 0;

    vector<students_classes> readStudentsClasses = studentClassesReader.read_students_classes();

    for (auto it_readStudentClasses:readStudentsClasses) {
        if (classYear == it_readStudentClasses.ClassCode[0]) {
            totalStudentsInClassYear += getClassStudentsNumber(it_readStudentClasses.ClassCode, it_readStudentClasses.UcCode);
            numberOfClassesInClassYear++;
        }
    }

    return totalStudentsInClassYear / numberOfClassesInClassYear;
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

bool Scheduler::isClassFull(string classCode, string ucCode) {
    if (getClassStudentsNumber(classCode, ucCode) >= scheduler.getMaxStudentsPerClass()) {
        return true;
    }

    return false;
}

bool Scheduler::isChangeGapRespected(string classCode, string ucCode) {
    if (abs(scheduler.getClassStudentsNumber(classCode, ucCode) - scheduler.getClassStudentsNumberAvg(classCode[0], ucCode)) <= scheduler.getMaxStudentsPerClassChangeGap() || scheduler.getClassStudentsNumberAvg(classCode[0], ucCode) <= 1) {
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

    scheduler.lastChange.type = "Add";
    scheduler.lastChange.studentName = StudentSchedule::getStudentName(scheduler.lastChange.studentCode);
    scheduler.lastChange.oldUcCode = "";
    scheduler.lastChange.oldClassCode = "";
    scheduler.requestQueue.push(scheduler.lastChange);
}

void Scheduler::removeUcFromStudent(queue <string> studentInfo) {
    scheduler.lastChange.studentCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.oldUcCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.oldClassCode = studentInfo.front();
    studentInfo.pop();

    scheduler.lastChange.type = "Remove";
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

    scheduler.lastChange.type = "Change";
    scheduler.lastChange.studentName = StudentSchedule::getStudentName(scheduler.lastChange.studentCode);
    scheduler.requestQueue.push(scheduler.lastChange);
}

void Scheduler::processRequest() {
    if (scheduler.requestQueue.empty()) {
        cout << "There are no Requests to Process" << endl;
        return;
    }

    scheduler.lastChange = scheduler.requestQueue.front();
    scheduler.requestQueue.pop();

    if (scheduler.lastChange.type == "Add") {
        if(processAddRequest()) {
            cout << GREEN << "The Request was Processed Successfully" << RESET << endl;
        }
        else {
            cout << RED << "The Processing Request Failed" << RESET << endl;
        }
    }
    else if (scheduler.lastChange.type == "Remove") {
        if(processRemoveRequest()) {
            cout << GREEN << "The Request was Processed Successfully" << RESET << endl;
        }
        else {
            cout << RED << "The Processing Request Failed" << RESET << endl;
        }
    }
    else if (scheduler.lastChange.type == "Change") {
        processChangeRequest();
    }
    else {
        cout << "The Request Type is Invalid" << endl;
    }
}

bool Scheduler::processAddRequest() {
    if (!(scheduler.getStudentUcsNumber(scheduler.lastChange.studentCode) <= scheduler.getMaxUcsPerStudent())) {
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentName + ", " + scheduler.lastChange.studentCode + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: " + scheduler.lastChange.studentName + " already has the Maximum Number of Ucs");

        return false;
    }
    else if (isClassFull(scheduler.lastChange.newClassCode, scheduler.lastChange.newUcCode)) {
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: Class " + scheduler.lastChange.newClassCode + " is Full");

        return false;
    }
    else if (!isChangeGapRespected(scheduler.lastChange.newClassCode, scheduler.lastChange.newUcCode)) {
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: The Class Change Gap is not Respected");

        return false;
    }
    else if (!isScheduleChangeValid(scheduler.lastChange)) {
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: The Schedule enters in Conflict therefore is not Valid");

        return false;
    }
    else if(scheduleWriter.write(scheduler.lastChange)) {
        scheduler.studentsClassesChangesStack.push(scheduler.lastChange);

        return true;
    }
    else {
        scheduler.processRequestFailedMessages.push_back(
                "UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" +
                scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" +
                scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" +
                "The Error Message: The Uc was not added to the Student Successfully (Unknown Error)");
        return false;
    }
}

bool Scheduler::processRemoveRequest() {
    if (!(scheduler.getStudentUcsNumber(scheduler.lastChange.studentCode) <= scheduler.getMaxUcsPerStudent())) {
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentName + ", " + scheduler.lastChange.studentCode + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: " + scheduler.lastChange.studentName + " already has the Maximum Number of Ucs");

        return false;
    }
    else if (isClassFull(scheduler.lastChange.oldClassCode, scheduler.lastChange.oldUcCode)) {
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: Class " + scheduler.lastChange.newClassCode + " is Full");

        return false;
    }
    else if (!isScheduleChangeValid(scheduler.lastChange)) {
        scheduler.processRequestFailedMessages.push_back("UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" + scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" + scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" + "The Error Message: The Schedule enters in Conflict therefore is not Valid");

        return false;
    }
    else if(scheduleWriter.write(scheduler.lastChange)) {
        scheduler.studentsClassesChangesStack.push(scheduler.lastChange);

        return true;
    }
    else {
        scheduler.processRequestFailedMessages.push_back(
                "UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" +
                scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" +
                scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" +
                "The Error Message: The Uc was not added to the Student Successfully (Unknown Error)");
        return false;
    }
}

void Scheduler::processChangeRequest() {
    if (scheduler.processRemoveRequest()) {
        if (scheduler.processAddRequest()) {
            cout << GREEN << "The Request was Processed Successfully" << RESET << endl;
            scheduler.studentsClassesChangesStack.push(scheduler.lastChange);
            return;
        }
        else {
            cout << RED << "The Processing Request Failed" << RESET << endl;
            scheduler.processRequestFailedMessages.push_back(
                    "UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" +
                    scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" +
                    scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" +
                    "The Error Message: The Uc was not added to the Student Successfully Do to an Error in the Add Request");
            revertLastChange();
        }
    }
    else {
        cout << RED << "The Processing Request Failed" << RESET << endl;
        scheduler.processRequestFailedMessages.push_back(
                "UP" + scheduler.lastChange.studentCode + ", " + scheduler.lastChange.studentName + ", [" +
                scheduler.lastChange.oldUcCode + ", " + scheduler.lastChange.oldClassCode + "] -> [" +
                scheduler.lastChange.newUcCode + ", " + scheduler.lastChange.newClassCode + "]\n" +
                "The Error Message: The Uc was not added to the Student Successfully Do to an Error in the Remove Request");
    }
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

    if(scheduleWriter.write(scheduler.lastChange)) {
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