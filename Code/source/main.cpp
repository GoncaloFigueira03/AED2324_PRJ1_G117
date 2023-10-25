#include <iostream>

#include "App.h"


int main(int argc, char **argv)
{
    Reader reader;

    vector<classes_per_uc> cu = reader.read_classes_per_uc();

    vector<classes> c = reader.read_classes();

    vector<students_classes> sc = reader.read_students_classes();

    //Menu CLI
    cout << endl;

    while (true) {
        cout << "========================[OPTIONS]========================" << endl << endl
             << "1 - View the Schedule of a Student;" << endl
             << "2 - View the Schedule of a Class;" << endl
             << "3 - View the Schedule of an Uc;" << endl
             << "4 - View the Students Enrolled in a Class of a given Uc;" << endl
             << "5 - View the Students Enrolled in a Uc;" << endl
             << "6 - Request the Enrolment of a New Student;" << endl
             << "7 - Request a Student Schedule Change;" << endl
             << "8 - Exit." << endl << endl
             << "========================[OPTIONS]========================" << endl;

        int option;

        cout << endl << "Please type the number corresponding to de wanted option:";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1: //View the Schedule of a Student
                break;

            case 2: //View the Schedule of a Class
                break;

            case 3: //View the Schedule of an Uc
                break;

            case 4: //View the Students Enrolled in a Class of a given Uc
                break;

            case 5: //View the Students Enrolled in an Uc
                break;

            case 6: //Enroll a New Student
                break;

            case 7: //Request a Student Schedule Change
                while (true)
                {
                    cout << "========================[OPTIONS]========================" << endl << endl
                         << "1 - Request a Class Schedule Change;" << endl
                         << "2 - Request a Class Schedule Change;" << endl
                         << "0 - Go Back." << endl << endl
                         << "========================[OPTIONS]========================" << endl;

                    cout << endl << "Please type the number corresponding to de wanted option:";
                    cin >> option;
                    cout << endl;

                    if (option == 1)
                    {
                        //Request a Class Schedule Change
                        break;
                    }
                    else if (option == 2)
                    {
                        //Request an Uc Change
                        break;
                    }
                    else if (option == 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Option!" << endl << endl;
                        continue;
                    }
                };
                break;

            case 8: //Exit the CLI
                return 0;

            default:
                cout << "Invalid Option!" << endl << endl;
        }
    }


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
