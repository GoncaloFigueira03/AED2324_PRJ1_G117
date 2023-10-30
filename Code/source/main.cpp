#include <iostream>

#include "App.h"
#include "Menu.h"
#include "Student.h"
#include "Class.h"
#include "Uc.h"
#include "SchedulePrinter.h"

int main() {
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

        string txtOption1;
        string txtOption2;

        cout << endl << "Please type the number corresponding to de wanted option:";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1: //View the Schedule of a Student
                cout << "Insert the Name or Code of the Desired Student:";
                cin >> txtOption1;

                SchedulePrinter::printStudentSchedule(txtOption1);
                cout << endl;
                break;

            case 2: //View the Schedule of a Class
                cout << "Insert the Code of the Desired Class:";
                cin >> txtOption1;

                SchedulePrinter::printClassSchedule(txtOption1);
                break;

            case 3: //View the Schedule of an Uc
                cout << "Insert the Code of the Desired Uc:";
                cin >> txtOption1;

                SchedulePrinter::printUcSchedule(txtOption1);
                break;

            case 4: //View the Students Enrolled in a Class of a given Uc
                cout << "Insert the Code of the Desired Class:";
                cin >> txtOption1;

                cout << "Insert the Code of the Desired Uc:";
                cin >> txtOption2;

                Class::printStudentsPerClassOfAGivenUc(txtOption1, txtOption2);
                cout << endl;
                break;

            case 5: //View the Students Enrolled in an Uc
                cout << "Insert the Code of the Desired Uc:";
                cin >> txtOption1;

                Uc::printStudentsInAUc(txtOption1);
                cout << endl;
                break;

            case 6: //Enroll a New Student
                break;

            case 7: //Request a Student Schedule Change
                while (true) {
                    cout << "========================[OPTIONS]========================" << endl << endl
                         << "1 - Request a Class Schedule Change;" << endl
                         << "2 - Request an Uc Change;" << endl
                         << "0 - Go Back." << endl << endl
                         << "========================[OPTIONS]========================" << endl;

                    cout << endl << "Please type the number corresponding to de wanted option:";
                    cin >> option;
                    cout << endl;

                    if (option == 1) {
                        //Request a Class Schedule Change
                        break;
                    }
                    else if (option == 2) {
                        //Request an Uc Change
                        break;
                    }
                    else if (option == 0) {
                        break;
                    }
                    else {
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
}