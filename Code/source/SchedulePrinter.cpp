
#include "SchedulePrinter.h"

void SchedulePrinter::printSchedule(std::vector<std::vector<std::string>> schedule) {

    //  Time slots

    schedule[0][1] = "08:00 - 08:30";
    schedule[0][2] = "08:30 - 09:00";
    schedule[0][3] = "09:00 - 09:30";

    //  Monday, Tuesday, Wednesday, Thursday, and Friday

    schedule[1][1] = "cringe";
    schedule[2][1] = "code";
    schedule[3][1] = "insert here";
    schedule[4][1] = "plz daddy here";

    // Print the schedule
    std::cout << "///////////////|  Monday   |  Tuesday  | Wednesday | Thursday  |  Friday   |" << std::endl;
    std::cout << "---------------|-----------|-----------|-----------|-----------|-----------|" << std::endl;

    for (int i = 1; i <= 31; ++i) {
        std::cout << " " << schedule[0][i] << " |";
        for (int j = 1; j < 5; ++j) {
            std::cout << schedule[j][i] << "|";
        }
        std::cout << std::endl;
        std::cout << "---------------|-----------|-----------|-----------|-----------|-----------|" << std::endl;
    }
}