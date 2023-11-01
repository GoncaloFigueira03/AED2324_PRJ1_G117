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
            addMenu();
            break;
        case 3:
            removeMenu();
            break;
        case 4:
            changeMenu();
            break;
        case 5:
            requestsMenu();
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

    queue<string> studentInfo;
    while (true) {
        cout << "Insert the Code of the Desired Uc:";
        cin >> txtOption2;
        if (Uc::isUc(txtOption2)) {
            break;
        }
        cout << "Uc " + txtOption2 + " does not exist!" << endl;
    }

    while (true) {
        cout << "Insert the Code of the Desired Class:";
        cin >> txtOption3;
        if (Class::isClass(txtOption3)) {
            break;
        }
        cout << "Class " + txtOption3 + " does not exist!" << endl;
    }

    if (!Scheduler::doesUcBelongToClass(txtOption2, txtOption3)) {
        cout << "Uc " + txtOption2 + " does not belong to Class " + txtOption3 + "!" << endl;
        addMenu();
    }

    while (true) {
        cout << "Insert the Name or Code of the Desired Student:";
        cin >> txtOption1;
        if (StudentSchedule::isStudent(StudentSchedule::getStudentCode(txtOption1))) {
            break;
        }
        else
            cout << "Student " + txtOption1 + " does not exist!" << endl;
    }

    studentInfo.push(StudentSchedule::getStudentCode(txtOption1));
    studentInfo.push(txtOption2);
    studentInfo.push(txtOption3);

    Scheduler::addUcToStudent(studentInfo);
    initMenu();
}

void Menu::removeMenu() {
    string txtOption1;
    string txtOption2;
    string txtOption3;

    queue<string> studentInfo;
    while (true) {
        cout << "Insert the Code of the Desired Uc:";
        cin >> txtOption2;
        if (Uc::isUc(txtOption2)) {
            break;
        }
        cout << "Uc " + txtOption2 + " does not exist!" << endl;
    }

    while (true) {
        cout << "Insert the Code of the Desired Class:";
        cin >> txtOption3;
        if (Class::isClass(txtOption3)) {
            break;
        }
        cout << "Class " + txtOption3 + " does not exist!" << endl;
    }

    if (!Scheduler::doesUcBelongToClass(txtOption2, txtOption3)) {
        cout << "Uc " + txtOption2 + " does not belong to Class " + txtOption3 + "!" << endl;
        addMenu();
    }

    while (true) {
        cout << "Insert the Name or Code of the Desired Student:";
        cin >> txtOption1;
        if (StudentSchedule::isStudent(txtOption1)) {
            break;
        }
        cout << endl << "Student " + txtOption1 + " does not exist!" << endl;
    }

    studentInfo.push(StudentSchedule::getStudentCode(txtOption1));
    studentInfo.push(txtOption2);
    studentInfo.push(txtOption3);

    Scheduler::removeUcFromStudent(studentInfo);

    initMenu();
}

void Menu::changeMenu() {
    string txtOption1;
    string txtOption2;
    string txtOption3;
    string txtOption4;
    string txtOption5;

    queue<string> studentInfo;

    vector<classes> studentClasses;

    while (true) {
        cout << "Insert Student Name: ";
        cin >> txtOption1;

        if (StudentSchedule::isStudent(txtOption1)) {
            studentClasses = StudentSchedule::getStudentSchedule(StudentSchedule::getStudentCode(txtOption1));
            studentInfo.push(StudentSchedule::getStudentCode(txtOption1));
            break;
        }
        cout << "Student " + txtOption1 + " does not exist!" << endl;
    }

    cout << "Current Student Classes: " << endl;
    for (auto it_studentClasses:studentClasses) {
        cout << it_studentClasses.UcCode << " " << it_studentClasses.ClassCode << endl;
    }

    while (true) {
        cout << "Type the Uc Code and Class Code to change (separated by a space): ";
        cin >> txtOption4 >> txtOption5;

        if (StudentSchedule::doesClassBelongToStudent(StudentSchedule::getStudentCode(txtOption1), txtOption5, txtOption4)) {
            break;
        }

        cout << "Student " + txtOption1 + " does not have Class " + txtOption5 + " of Uc " + txtOption4 + "!" << endl;
    }

    while (true) {
        cout << "Insert the Uc Code and Class Code of the new Class (separated by a space): ";
        cin >> txtOption2 >> txtOption3;

        if (Scheduler::doesUcBelongToClass(txtOption2, txtOption3)) {
            break;
        }

        cout << "Uc " + txtOption2 + " does not belong to Class " + txtOption3 + "!" << endl;
    }

    studentInfo.push(txtOption2);
    studentInfo.push(txtOption3);
    studentInfo.push(txtOption4);
    studentInfo.push(txtOption5);

    Scheduler::requestChangeInStudentClass(studentInfo);
    initMenu();
}

void Menu::requestsMenu() {
    cout << endl << "====================[OPTIONS]====================" << endl << endl;
    cout << "1 - View Requests;" << endl;
    cout << "2 - Process Requests;" << endl;
    cout << "3 - View Successful Requests;" << endl;
    cout << "4 - View Failed Requests;" << endl;
    cout << "5 - Revert Last Request;" << endl;
    cout << "0 - Go Back;" << endl;
    cout << endl << "====================[OPTIONS]====================" << endl << endl;

    int option;
    cout << "Please type the number corresponding to de wanted option:";
    cin >> option;
    cout << endl;

    while (true) {
        switch (option) {
            case 1: // View Requests
                Scheduler::printRequests();
                requestsMenu();

            case 2: // Process Requests
                Scheduler::processRequest();
                cout << "Requests Processed!" << endl;
                requestsMenu();

            case 3: // View Successful Requests
                Scheduler::printRequestSuccessLogs();
                requestsMenu();

            case 4: // View Failed Requests
                Scheduler::printRequestFailLogs();
                requestsMenu();

            case 5: // Revert Last Request
                Scheduler::revertLastChange();
                cout << "Last Request Reverted!" << endl;
                requestsMenu();

            case 0: // Go Back
                initMenu();

            default:
                cout << "Invalid Option!" << endl;
                requestsMenu();
        }
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