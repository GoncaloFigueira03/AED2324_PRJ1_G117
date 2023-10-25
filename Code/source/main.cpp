
#include <iostream>
#include "App.h"


int main(int argc, char **argv)
{
    Reader reader;

    vector<classes_per_uc> cu = reader.read_classes_per_uc();

    vector<classes> c = reader.read_classes();

    vector<students_classes> sc = reader.read_students_classes();

    /*
    for (auto cu_:cu)
    {
        cout << cu_.UcCode + ' ' + cu_.ClassCode + '\n';
    }

    for (auto c_:c)
    {
        cout << c_.UcCode + ' ' + c_.ClassCode + ' ' + c_.Type + ' ' + c_.Duration + ' ' + c_.StartHour + ' ' + c_.Weekday + '\n';
    }

    for (auto sc_:sc)
    {
        cout << sc_.UcCode + ' ' + sc_.ClassCode + ' ' + sc_.StudentCode + ' ' + sc_.StudentName + '\n';
    }
    */

    return 0;
}
