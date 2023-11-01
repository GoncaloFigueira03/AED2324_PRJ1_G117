#include "Menu.h"

void Menu::initMenu() {
    cout << endl << "====================[OPTIONS]====================" << endl << endl;
    cout << "1 - Display" << endl;
    cout << "2 - Add" << endl;
    cout << "3 - Remove" << endl;
    cout << "4 - Change" << endl;
    cout << "5 - Requests" << endl;
    cout << "0 - Exit" << endl;
    cout << endl << "====================[OPTIONS]====================" << endl << endl;

    int option;

    cout << "Please type the number corresponding to de wanted option:";
    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
            displayMenu();
            break;
        case 2:
            //addMenu();
            break;
        case 3:
            //removeMenu();
            break;
        case 4:
            //changeMenu();
            break;
        case 5:
            //requestsMenu();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Option!" << endl;
            initMenu();
    }
}

void Menu::displayMenu() {
    cout << "====================[OPTIONS]====================" << endl << endl;
    cout << "1 - Student;" << endl;
    cout << "2 - Class;" << endl;
    cout << "3 - Uc;" << endl;
    cout << "0 - Go Back;" << endl << endl;
    cout << "====================[OPTIONS]====================" << endl << endl;

    int option;
    cout << "Please type the number corresponding to de wanted option:";
    cin >> option;

    switch (option) {
        case 1:
            studentMenu();
            break;
        case 2:
            classMenu();
            break;
        case 3:
            ucMenu();
            break;
        case 0:
            initMenu();
        default:
            cout << "Invalid Option!" << endl;
            displayMenu();
    }
}

void Menu::addMenu() {
    string txtOption1;
    string txtOption2;
    string txtOption3;

    cout << "Insert the Code of the Desired Uc:";
    cin >> txtOption1;

    cout << "Insert the Code of the Desired Class:";
    cin >> txtOption2;

    cout << "Insert the Name or Code of the Desired Student:";
    cin >> txtOption3;

    if (!Uc::isUc(txtOption1)) {
        cout << "Uc " + txtOption1 + " does not exist!" << endl;
        addMenu();
    }
    else if (Class::isClass(txtOption1)) {
        cout << "Class " + txtOption2 + " does not exist!" << endl;
        addMenu();
    }
    else if (StudentSchedule::isStudent(txtOption3)) {
        cout << "Student " + txtOption3 + " does not exist!" << endl;
        addMenu();
    }



}

void Menu::studentMenu() {
    cout << endl << "====================[OPTIONS]====================" << endl << endl;
    cout << "1 - View the Schedule of a Student;" << endl;
    cout << "2 - View the Classes of a Student;" << endl;
    cout << "3 - View the Ucs of a Student;" << endl;
    cout << "0 - Go Back;" << endl;
    cout << endl << "====================[OPTIONS]====================" << endl << endl;

    int option;
    string txtOption1;
    string txtOption2;
    cout << "Please type the number corresponding to de wanted option:";
    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
            while (true) {
                cout << "Insert the Name or Code of the Desired Student:";
                cin >> txtOption1;
                cout << endl;

                if (StudentSchedule::isStudent(txtOption1)) {
                    cout << "Student " + txtOption1 + " Schedule is:" << endl;
                    SchedulePrinter::printStudentSchedule(StudentSchedule::getStudentCode(txtOption1));
                    cout << endl;
                    break;
                }
                else {
                    cout << "Student " + txtOption1 + " does not exist!" << endl;
                }
            }

            initMenu();
        case 2:
            while (true) {
                cout << "Insert the Name or Code of the Desired Student:";
                cin >> txtOption1;
                cout << endl;

                if (StudentSchedule::isStudent(txtOption1)) {
                    cout << "Student " + txtOption1 + " Classes are:" << endl;
                    StudentSchedule::printStudentClasses(StudentSchedule::getStudentCode(txtOption1));
                    cout << endl;
                    break;
                } else {
                    cout << "Student " + txtOption1 + " does not exist!" << endl;
                }
            }

            initMenu();
        case 3:
            while (true) {
                cout << "Insert the Name or Code of the Desired Student:";
                cin >> txtOption1;
                cout << endl;

                if (StudentSchedule::isStudent(txtOption1)) {
                    cout << "Student " + txtOption1 + " Ucs are:" << endl;
                    StudentSchedule::printStudentUcs(StudentSchedule::getStudentCode(txtOption1));
                    cout << endl;
                    break;
                }
                else {
                    cout << "Student " + txtOption1 + " does not exist!" << endl;
                }
            }

            initMenu();
        case 0:
            displayMenu();
        default:
            cout << "Invalid Option!" << endl;
            studentMenu();
    }
}

void Menu::classMenu() {
    cout << endl << "====================[OPTIONS]====================" << endl << endl;
    cout << "1 - View the Schedule of a Class;" << endl;
    cout << "2 - View the Students Enrolled in a Class;" << endl;
    cout << "3 - View the Students Enrolled in a Class of a given Uc;" << endl;
    cout << "0 - Go Back;" << endl;
    cout << endl << "====================[OPTIONS]====================" << endl << endl;

    int option;
    string txtOption1;
    string txtOption2;
    cout << "Please type the number corresponding to de wanted option:";
    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
            while (true) {
                cout << "Insert the Code of the Desired Class:";
                cin >> txtOption1;
                cout << endl;

                if (Class::isClass(txtOption1)) {
                    cout << "Class " + txtOption1 + " Schedule is:" << endl;
                    SchedulePrinter::printClassSchedule(txtOption1);
                    cout << endl;
                    break;
                }
                else {
                    cout << "Class " + txtOption1 + " does not exist!" << endl;
                }
            }

            classMenu();
        case 2:
            while (true) {
                cout << "Insert the Code of the Desired Class:";
                cin >> txtOption1;
                cout << endl;

                if (Class::isClass(txtOption1)) {
                    cout << "Class " + txtOption1 + " Students are:" << endl;
                    Class::printStudentsInAClass(txtOption1);
                    cout << endl;
                    break;
                } else {
                    cout << "Class " + txtOption1 + " does not exist!" << endl;
                }
            }

            classMenu();
        case 3:
            while (true) {
                cout << "Insert the Code of the Desired Class:";
                cin >> txtOption1;
                cout << endl;

                if (Class::isClass(txtOption1)) {
                    cout << "Insert the Code of the Desired Uc:";
                    cin >> txtOption2;
                    cout << endl;

                    if (Uc::isUc(txtOption2)) {
                        cout << "Students of Class " + txtOption1 + " of Uc " + txtOption2 + " are:" << endl;
                        Class::printStudentsPerClassOfAGivenUc(txtOption1, txtOption2);
                        cout << endl;
                        break;
                    }
                    else {
                        cout << "Uc " + txtOption2 + " does not exist!" << endl;
                    }
                }
                else {
                    cout << "Class " + txtOption1 + " does not exist!" << endl;
                }
            }

            classMenu();
        case 0:
            displayMenu();
        default:
            cout << "Invalid Option!" << endl;
            classMenu();
    }


}

void Menu::ucMenu() {
    cout << endl << "====================[OPTIONS]====================" << endl << endl;
    cout << "1 - View the Schedule of an Uc;" << endl;
    cout << "2 - View the Students Enrolled in an Uc;" << endl;
    cout << "0 - Go Back;" << endl;
    cout << endl << "====================[OPTIONS]====================" << endl << endl;

    int option;
    string txtOption1;
    cout << "Please type the number corresponding to de wanted option:";
    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
            while (true) {
                cout << "Insert the Code of the Desired Uc:";
                cin >> txtOption1;
                cout << endl;

                if (Uc::isUc(txtOption1)) {
                    cout << "Uc " + txtOption1 + " Schedule is:" << endl;
                    SchedulePrinter::printUcSchedule(txtOption1);
                    cout << endl;
                    break;
                }
                else {
                    cout << "Uc " + txtOption1 + " does not exist!" << endl;
                }
            }

            ucMenu();
        case 2:
            while (true) {
                cout << "Insert the Code of the Desired Uc:";
                cin >> txtOption1;
                cout << endl;

                if (Uc::isUc(txtOption1)) {
                    cout << "Students of Uc " + txtOption1 + " are:" << endl;
                    Uc::printStudentsInAUc(txtOption1);
                    cout << endl;
                    break;
                }
                else {
                    cout << "Uc " + txtOption1 + " does not exist!" << endl;
                }
            }

            ucMenu();
        case 0:
            displayMenu();
        default:
            cout << "Invalid Option!" << endl;
            ucMenu();
    }
}



