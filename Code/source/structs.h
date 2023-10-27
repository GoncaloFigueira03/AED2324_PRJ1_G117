
#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct classes_per_uc {
    string UcCode;
    string ClassCode;
};

struct classes {
    string ClassCode;
    string UcCode;
    string Weekday;
    string StartHour;
    string Duration;
    string Type;
};

struct students_classes {
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
};

#endif