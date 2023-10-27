
#ifndef CODE_SCHEDULEPRINTER_H
#define CODE_SCHEDULEPRINTER_H

#include "Student.h"
#include "Class.h"
#include "Uc.h"

class SchedulePrinter{
public:
    static void printSchedule(std::vector<std::vector<std::string>> schedule);
};

#endif //CODE_SCHEDULEPRINTER_H
