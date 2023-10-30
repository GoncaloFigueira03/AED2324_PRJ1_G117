
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
    // Reads classes_per_uc.csv and returns a vector of classes_per_uc
    vector<classes_per_uc> read_classes_per_uc();

    // Reads classes.csv and returns a vector of classes
    vector<classes> read_classes();

    // Reads students_classes.csv and returns a vector of students_classes
    vector<students_classes> read_students_classes();
};

#endif