
#ifndef CODE_SCHEDULE_H
#define CODE_SCHEDULE_H

#include "App.h"

class Scheduler {
public:
    // TODO: implement
    static void requestChangeInStudentClass();

    static void requestChangeInStudentUc();

    static void addStudentToUc(string studentNameOrCode, string ucCode);

    static int getStudentUcsNumber(string studentNameOrCode);
};

#endif //CODE_SCHEDULE_H
