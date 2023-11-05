#ifndef CODE_WRITER_H
#define CODE_WRITER_H

#include "structs.h"
#include "Schedule.h"

#include <fstream>

using namespace std;

class ScheduleWriter {
private:
    // The Reader
    Reader reader;

public:
    /**
     * @brief Initializes the Schedule Writer
     * @param reader The file Reader
     */
    explicit ScheduleWriter(Reader &reader);

    /**
     * @brief Writes the Schedule Changes to the students_classes.csv File
     * @note Time Complexity: O(n)
     * @param lastChange Is the first change on the Queue Request to be Written
     * @return bool
     */
    bool write(studentClassChange lastChange);

    /**
     * @brief Writes the Schedule Changes Logs to changes.csv File
     * @note Time Complexity: O(n)
     * @param lastChange Is the first change on the Queue Request to be Written
     * @return
     */
    bool writeChanges(studentClassChange lastChange);
};

#endif //CODE_WRITER_H
