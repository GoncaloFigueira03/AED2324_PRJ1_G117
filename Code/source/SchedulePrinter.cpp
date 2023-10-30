
#include "SchedulePrinter.h"

classTimeIndexes SchedulePrinter::getClassTimes(classes classTimes) {
    list<string> classTimeStamp = {"8", " ", "8.5", " ", "9", " ", "9.5", " ", "10", " ", "10.5", " ",
                                   "11", " ", "11.5", " ", "12", " ", "12.5", " ", "13", " ", "13.5", " ",
                                   "14", " ", "14.5", " ", "15", " ", "15.5", " ", "16", " ", "16.5", " ",
                                   "17", " ", "17.5", " ", "18", " ", "18.5", " ", "19", " "};

    list<string> classTimeWeekday = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    classTimeIndexes classTimeIndexes;

    for (int i = 1; i < 47; i++) {
        if (classTimes.StartHour == classTimeStamp.front()) {
            classTimeIndexes.startHourIndex = i;
        }

        classTimeStamp.pop_front();
    }

    for (int i = 1; i < 6; i++) {
        if (classTimes.Weekday == classTimeWeekday.front()) {
            classTimeIndexes.weekdayIndex = i;
        }

        classTimeWeekday.pop_front();
    }

    classTimeIndexes.durationIndex = classTimes.Duration;

    return classTimeIndexes;
}

vector<vector<string>> SchedulePrinter::scheduleBuilder(vector<classes> classesSchedule) {
    vector<vector<string>> printableSchedule(6, vector<string>(47));

    for (auto it_classesSchedule:classesSchedule) {
        classTimeIndexes classTimes = getClassTimes(it_classesSchedule);

        if (classTimes.durationIndex == "1") {
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex] = ' ' + it_classesSchedule.UcCode + "  ";
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 1] = ' ' + it_classesSchedule.ClassCode + "   ";
            if (it_classesSchedule.Type == "PL" || it_classesSchedule.Type == "TP")
                printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 2] = ' ' + it_classesSchedule.Type + "        ";
            else
                printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 2] = ' ' + it_classesSchedule.Type + "         ";
        } else if (classTimes.durationIndex == "1.5") {
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex] = "           ";
            if (it_classesSchedule.UcCode == "UP001")
                printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 1] = ' ' + it_classesSchedule.UcCode + "     ";
            else
                printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 1] = ' ' + it_classesSchedule.UcCode + "  ";
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 2] = ' ' + it_classesSchedule.ClassCode + "   ";
            if (it_classesSchedule.Type == "PL" || it_classesSchedule.Type == "TP")
                printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 3] = ' ' + it_classesSchedule.Type + "        ";
            else
                printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 3] = ' ' + it_classesSchedule.Type + "         ";
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 4] = "           ";
        } else if (classTimes.durationIndex == "2") {
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex] = "           ";
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 1] = "           ";
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 2] = ' ' + it_classesSchedule.UcCode + "  ";
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 3] = ' ' + it_classesSchedule.ClassCode + "   ";
            if (it_classesSchedule.Type == "PL" || it_classesSchedule.Type == "TP")
                printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 4] = ' ' + it_classesSchedule.Type + "        ";
            else
                printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 4] = ' ' + it_classesSchedule.Type + "         ";
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 5] = "           ";
            printableSchedule[classTimes.weekdayIndex][classTimes.startHourIndex + 6] = "           ";
        }
    }

    return printableSchedule;
}

void SchedulePrinter::printSchedule(vector<vector<string>> schedule) {

    // Print the Time Slots
    string startTime = "08:00";

    for (int i = 1; i <= 46; ++i) {

        if (i%2 == 0) {
            schedule[0][i] = "---------------|";
            continue;
        }

        // Manipulate Time
        int hour = (startTime[0] - '0') * 10 + (startTime[1] - '0');
        int minute = (startTime[3] - '0') * 10 + (startTime[4] - '0');

        std::stringstream start;
        start << std::setw(2) << std::setfill('0') << hour << ":";
        start << std::setw(2) << std::setfill('0') << minute;

        minute += 30;
        if (minute >= 60) {hour++;minute -= 60;}

        std::stringstream end;
        end << std::setw(2) << std::setfill('0') << hour << ":";
        end << std::setw(2) << std::setfill('0') << minute;

        schedule[0][i] = " " + start.str() + " - " + end.str() + " |";

        startTime = end.str();
    }

    // Print the Schedule
    cout << endl;
    cout << "///////////////|  Monday   |  Tuesday  | Wednesday | Thursday  |  Friday" << endl;
    cout << "---------------|-----------|-----------|-----------|-----------|-----------|" << std::endl;

    for (int i = 1; i <= 46; i++) {
        cout << schedule[0][i];

        for (int j = 1; j < 6; j++) {
            if (schedule[j][i] == "" && i%2 != 0) {
                schedule[j][i] = "           ";
            }else if (schedule[j][i] == "" && i%2 == 0) {
                schedule[j][i] = "-----------";
            }
            cout << schedule[j][i] << "|";
        }
        cout << endl;
    }
    cout << endl;
}

void SchedulePrinter::printStudentSchedule(string studentNameOrCode) {
    vector<classes> studentSchedule = StudentSchedule::getStudentSchedule(studentNameOrCode);

    printSchedule(scheduleBuilder(studentSchedule));
}

void SchedulePrinter::printClassSchedule(string classCode) {
    vector<classes> classSchedule = Class::getClassSchedule(classCode);

    printSchedule(scheduleBuilder(classSchedule));
}

void SchedulePrinter::printUcSchedule(std::string ucCode) {
    vector<classes> ucSchedule = Uc::getUcSchedule(ucCode);

    printSchedule(scheduleBuilder(ucSchedule));
}