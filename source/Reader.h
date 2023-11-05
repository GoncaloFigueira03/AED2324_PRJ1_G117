#ifndef _READ_H_
#define _READ_H_

#include <list>
#include <vector>

#include "structs.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

class Reader {
public:
    /**
     * @brief Reads classes_per_uc.csv and returns a vector of classes_per_uc
     * ;complexity O(n)
     * @return vector<classes_per_uc>
     */
    vector<classes_per_uc> read_classes_per_uc();

    /**
     * @brief Reads classes.csv and returns a vector of classes
     * ;complexity O(n)
     * @return vector<classes>
     */
    vector<classes> read_classes();

    /**
     * @brief Reads students_classes.csv and returns a vector of students_classes
     * ;complexity O(n)
     * @return vector<students_classes>
     */
    vector<students_classes> read_students_classes();

    /**
     * @brief Reads changes.csv and returns a vector of studentClassChange
     * ;complexity O(n)
     * @return vector<studentClassChange>
     */
    vector<studentClassChange> read_changes();
};

#endif