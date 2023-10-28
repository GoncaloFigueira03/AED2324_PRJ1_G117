
#include "SchedulePrinter.h"

Reader scheduleReader;

vector<vector<string>> SchedulePrinter::studentScheduleBuilder(string studentCode) {
    vector<vector<string>> printableSchedule(5, vector<string>(32));

    vector<classTime> = Class::getClassTimes();

    vector<classes> studentSchedule = StudentSchedule::getStudentSchedule(studentCode);

    for (auto it_studentSchedule:studentSchedule) {
        if (it_studentSchedule.Weekday == "Monday"){

        }
    }
}

void SchedulePrinter::printSchedule(vector<vector<string>> schedule) {

    //  Time slots

    schedule[0][1] = "08:00 - 08:30";
    schedule[0][2] = "08:30 - 09:00";
    schedule[0][3] = "09:00 - 09:30";
    schedule[0][4] = "09:30 - 10:00";
    schedule[0][5] = "10:00 - 10:30";
    schedule[0][6] = "10:30 - 11:00";
    schedule[0][7] = "11:00 - 11:30";
    schedule[0][8] = "11:30 - 12:00";
    schedule[0][9] = "12:00 - 12:30";
    schedule[0][10] = "12:30 - 13:00";
    schedule[0][11] = "13:00 - 13:30";
    schedule[0][12] = "13:30 - 14:00";
    schedule[0][13] = "14:00 - 14:30";
    schedule[0][14] = "14:30 - 15:00";
    schedule[0][15] = "15:00 - 15:30";
    schedule[0][16] = "15:30 - 16:00";
    schedule[0][17] = "16:00 - 16:30";
    schedule[0][18] = "16:30 - 17:00";
    schedule[0][19] = "17:00 - 17:30";
    schedule[0][20] = "17:30 - 18:00";
    schedule[0][21] = "18:00 - 18:30";
    schedule[0][22] = "18:30 - 19:00";
    schedule[0][23] = "19:00 - 19:30";

    //  Monday, Tuesday, Wednesday, Thursday, and Friday

    schedule[1][1] = "cringe";
    schedule[2][1] = "code";
    schedule[3][1] = "insert here";
    schedule[4][1] = "plz daddy here";

    // Print the schedule
    cout << "///////////////|  Monday   |  Tuesday  | Wednesday | Thursday  |  Friday   |" << std::endl;
    cout << "---------------|-----------|-----------|-----------|-----------|-----------|" << std::endl;

    for (int i = 1; i <= 31; ++i) {
        cout << " " << schedule[0][i] << " |";
        for (int j = 1; j < 5; ++j) {
            cout << schedule[j][i] << "|";
        }
        cout << endl;
        cout << "---------------|-----------|-----------|-----------|-----------|-----------|" << std::endl;
    }
}