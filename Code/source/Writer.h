
#ifndef CODE_WRITER_H
#define CODE_WRITER_H

#include <fstream>
#include "structs.h"
#include "Schedule.h"

using namespace std;

class ScheduleWriter {
private:
    // The Reader
    Reader reader;

public:
    // Initializes the Schedule Writer
    ScheduleWriter(Reader &reader);

    // Writes the Schedule Changes to the students_classes.csv File
    bool write();
};

#endif //CODE_WRITER_H
