#include "Menu.h"

#define RESET "\033[0m"
#define BOLDWHITE "\033[1m\033[37m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[93m"

void Menu::initMenu() {
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;
    cout << BOLDWHITE << "   1 - Display" << endl;
    cout << "   2 - Add" << endl;
    cout << "   3 - Remove" << endl;
    cout << "   4 - Change" << endl;
    cout << "   5 - Requests" << endl;
    cout << "   0 - Exit" << RESET <<  endl;
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;

    int option;

    cout << "Please type the number corresponding to de wanted option:";
    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
            system("CLS");
            displayMenu();
            break;
        case 2:
            system("CLS");
            addMenu();
            break;
        case 3:
            system("CLS");
            removeMenu();
            break;
        case 4:
            system("CLS");
            changeMenu();
            break;
        case 5:
            system("CLS");
            requestsMenu();
            break;
        case 0:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            cout << "Invalid Option!" << endl << flush;
            system("PAUSE");
            system("CLS");
            initMenu();
    }
}

void Menu::displayMenu() {
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;
    cout << BOLDWHITE << "   1 - Student;" << endl;
    cout << "   2 - Class;" << endl;
    cout << "   3 - Uc;" << endl;
    cout << "   0 - Go Back;" << RESET << endl;
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;

    int option;
    cout << "Please type the number corresponding to de wanted option:";
    cin >> option;

    switch (option) {
        case 1:
            system("CLS");
            studentMenu();
            break;
        case 2:
            system("CLS");
            classMenu();
            break;
        case 3:
            system("CLS");
            ucMenu();
            break;
        case 0:
            system("CLS");
            initMenu();
            break;
        default:
            cout << RED << "Invalid Option!" << RESET << endl;
            system("PAUSE");
            system("CLS");
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
        cout << RED << "Uc " + txtOption2 + " does not exist!" << RESET << endl;
    }

    while (true) {
        cout << "Insert the Code of the Desired Class:";
        cin >> txtOption3;
        if (Class::isClass(txtOption3)) {
            break;
        }
        cout << RED << "Class " + txtOption3 + " does not exist!" << RESET << endl;
    }

    if (!Scheduler::doesUcBelongToClass(txtOption2, txtOption3)) {
        cout << RED << "Uc " + txtOption2 + " does not belong to Class " + txtOption3 + "!" << RESET << endl;
        addMenu();
    }

    while (true) {
        cout << "Insert the Name or Code of the Desired Student:";
        cin >> txtOption1;
        if (StudentSchedule::isStudent(StudentSchedule::getStudentCode(txtOption1))) {
            cout << GREEN << "Add Request Added Successfully!" << RESET << endl << endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        else
            cout << RED << "Student " + txtOption1 + " does not exist!" << RESET << endl;
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
        cout << "Insert the Name or Code of the Desired Student:";
        cin >> txtOption1;
        if (StudentSchedule::isStudent(txtOption1)) {
            break;
        }

        cout << RED << "Student " + txtOption1 + " does not exist!" << RESET << endl;
    }

    cout << "Current Student Classes: " << endl;
    StudentSchedule::printStudentClassesAndUcs(StudentSchedule::getStudentCode(txtOption1));
    cout << endl;

    while (true) {
        cout << "Insert the Uc Code and Class Code to remove (separated by a space): ";
        cin >> txtOption2 >> txtOption3;

        if (StudentSchedule::doesClassBelongToStudent(StudentSchedule::getStudentCode(txtOption1), txtOption3, txtOption2)) {
            cout << GREEN << "Remove Request Added Successfully!" << RESET << endl << endl;
            system("PAUSE");
            system("CLS");
            break;
        }

        cout << RED << "Student " + txtOption1 + " does not have Class " + txtOption3 + " of Uc " + txtOption2 + "!" << RESET << endl;
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

    while (true) {
        cout << "Insert Student Name: ";
        cin >> txtOption1;

        if (StudentSchedule::isStudent(txtOption1)) {
            studentInfo.push(StudentSchedule::getStudentCode(txtOption1));
            break;
        }
        cout << RED << "Student " + txtOption1 + " does not exist!" << RESET << endl;
    }

    cout << "Current Student Classes: " << endl;
    StudentSchedule::printStudentClassesAndUcs(StudentSchedule::getStudentCode(txtOption1));

    while (true) {
        cout << "Type the Uc Code and Class Code to change (separated by a space): ";
        cin >> txtOption4 >> txtOption5;

        if (StudentSchedule::doesClassBelongToStudent(StudentSchedule::getStudentCode(txtOption1), txtOption5, txtOption4)) {
            break;
        }

        cout << RED << "Student " + txtOption1 + " does not have Class " + txtOption5 + " of Uc " + txtOption4 + "!" << RESET << endl;
    }

    while (true) {
        cout << "Insert the Uc Code and Class Code of the new Class (separated by a space): ";
        cin >> txtOption2 >> txtOption3;

        if (Scheduler::doesUcBelongToClass(txtOption2, txtOption3)) {
            cout << GREEN << "Change Request Added Successfully!" << RESET << endl << endl;
            system("PAUSE");
            system("CLS");
            break;
        }

        cout << RED << "Uc " + txtOption2 + " does not belong to Class " + txtOption3 + "!" << RESET << endl;
    }

    studentInfo.push(txtOption2);
    studentInfo.push(txtOption3);
    studentInfo.push(txtOption4);
    studentInfo.push(txtOption5);

    Scheduler::requestChangeInStudentClass(studentInfo);
    initMenu();
}

void Menu::requestsMenu() {
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;
    cout << BOLDWHITE << "   1 - View Requests;" << endl;
    cout << "   2 - Process Requests;" << endl;
    cout << "   3 - View Successful Requests;" << endl;
    cout << "   4 - View Failed Requests;" << endl;
    cout << "   5 - Revert Last Request;" << endl;
    cout << "   0 - Go Back;" << RESET << endl;
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;

    int option;
    cout << "Please type the number corresponding to the wanted option:";
    cin >> option;
    cout << endl;

    switch (option) {
        case 1: // View Requests
            Scheduler::printRequests();
            system("PAUSE");
            system("CLS");
            requestsMenu();
            break;

        case 2: // Process Requests
            Scheduler::processRequest();
            system("PAUSE");
            system("CLS");
            requestsMenu();
            break;

        case 3: // View Successful Requests
            Scheduler::printRequestSuccessLogs();
            system("PAUSE");
            system("CLS");
            requestsMenu();
            break;

        case 4: // View Failed Requests
            Scheduler::printRequestFailLogs();
            system("PAUSE");
            system("CLS");
            requestsMenu();
            break;

        case 5: // Revert Last Request
            Scheduler::revertLastChange();
            system("PAUSE");
            system("CLS");
            requestsMenu();
            break;

        case 0: // Go Back
            system("CLS");
            initMenu();
            break;

        default:
            cout << RED << "Invalid Option!" << RESET << endl;
            system("PAUSE");
            system("CLS");
            requestsMenu();
    }
}

void Menu::studentMenu() {
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;
    cout << BOLDWHITE << "   1 - View the Schedule of a Student;" << endl;
    cout << "   2 - View the Classes of a Student;" << endl;
    cout << "   3 - View the Ucs of a Student;" << endl;
    cout << "   0 - Go Back;" << RESET << endl;
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;

    int option;
    string txtOption1;
    string txtOption2;
    cout << "Please type the number corresponding to the wanted option:";
    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
            while (true) {
                cout << "Insert the Name or Code of the Desired Student:";
                cin >> txtOption1;
                cout << endl;

                if (StudentSchedule::isStudent(txtOption1)) {
                    system("CLS");
                    cout << BOLDWHITE << "Student " + txtOption1 + " Schedule is:" << RESET << endl;
                    SchedulePrinter::printStudentSchedule(StudentSchedule::getStudentCode(txtOption1));
                    cout << endl;
                    system("PAUSE");
                    system("CLS");
                    system("CLS");
                    break;
                }
                else {
                    cout << RED << "Student " + txtOption1 + " does not exist!" << RESET << endl;
                }
            }

            initMenu();
            break;
        case 2:
            while (true) {
                cout << "Insert the Name or Code of the Desired Student:";
                cin >> txtOption1;
                cout << endl;

                if (StudentSchedule::isStudent(txtOption1)) {
                    cout << "Student " + txtOption1 + " Classes are:" << endl;
                    StudentSchedule::printStudentClasses(StudentSchedule::getStudentCode(txtOption1));
                    cout << endl;
                    system("PAUSE");
                    system("CLS");
                    break;
                }
                else {
                    cout << RED << "Student " + txtOption1 + " does not exist!" << RESET << endl;
                }
            }

            initMenu();
            break;
        case 3:
            while (true) {
                cout << "Insert the Name or Code of the Desired Student:";
                cin >> txtOption1;
                cout << endl;

                if (StudentSchedule::isStudent(txtOption1)) {
                    cout << "Student " + txtOption1 + " Ucs are:" << endl;
                    StudentSchedule::printStudentUcs(StudentSchedule::getStudentCode(txtOption1));
                    cout << endl;
                    system("PAUSE");
                    system("CLS");
                    break;
                }
                else {
                    cout << RED << "Student " + txtOption1 + " does not exist!" << RESET << endl;
                }
            }

            initMenu();
            break;
        case 0:
            system("CLS");
            displayMenu();
            break;
        default:
            cout << RED << "Invalid Option!" << RESET << endl;
            system("PAUSE");
            system("CLS");
            studentMenu();
    }
}

void Menu::classMenu() {
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;
    cout << BOLDWHITE << "   1 - View the Schedule of a Class;" << endl;
    cout << "   2 - View the Students Enrolled in a Class;" << endl;
    cout << "   3 - View the Students Enrolled in a Class of a given Uc;" << endl;
    cout << "   0 - Go Back;" << RESET << endl;
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;

    int option;
    string txtOption1;
    string txtOption2;
    char charOption1;
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
                    system("PAUSE");
                    system("CLS");
                    system("CLS");
                    break;
                }
                else {
                    cout << RED << "Class " + txtOption1 + " does not exist!" << RESET << endl;
                }
            }

            classMenu();
            break;
        case 2:
            while (true) {
                cout << "Insert the Code of the Desired Class:";
                cin >> txtOption1;
                cout << endl;

                if (Class::isClass(txtOption1)) {
                    while (true) {
                        cout << "Do you want to see them ordered by Name or Code? (N/C):";
                        cin >> charOption1;
                        if (charOption1 == 'N' || charOption1 == 'C' || charOption1 == 'n' || charOption1 == 'c') {
                            break;
                        }
                        cout << RED << "Invalid Option!" << RESET << endl;
                    }

                    cout << endl << "Class " + txtOption1 + " Students are:" << endl;
                    Class::printStudentsInAClass(txtOption1, charOption1);
                    cout << endl;
                    system("PAUSE");
                    system("CLS");
                    break;
                }
                else {
                    cout << RED << "Class " + txtOption1 + " does not exist!" << RESET << endl;
                }
            }

            classMenu();
            break;
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
                        system("PAUSE");
                        system("CLS");
                        break;
                    }
                    else {
                        cout << RED << "Uc " + txtOption2 + " does not exist!" << RESET << endl;
                    }
                }
                else {
                    cout << RED << "Class " + txtOption1 + " does not exist!" << RESET << endl;
                }
            }

            classMenu();
            break;
        case 0:
            system("CLS");
            displayMenu();
        default:
            cout << RED << "Invalid Option!" << RESET << endl;
            system("PAUSE");
            system("CLS");
            classMenu();
    }


}

void Menu::ucMenu() {
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;
    cout << BOLDWHITE << "   1 - View the Schedule of an Uc;" << endl;
    cout << "   2 - View the Students Enrolled in an Uc;" << endl;
    cout << "   3 - View the Student Count of an Uc;" << endl;
    cout << "   0 - Go Back;" << RESET << endl;
    cout << endl << YELLOW << "=================[OPTIONS]=================" << RESET << endl << endl;

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
                    system("PAUSE");
                    system("CLS");
                    system("CLS");
                    break;
                }
                else {
                    cout << RED << "Uc " + txtOption1 + " does not exist!" << RESET << endl;
                }
            }

            ucMenu();
            break;
        case 2:
            while (true) {
                cout << "Insert the Code of the Desired Uc:";
                cin >> txtOption1;
                cout << endl;

                if (Uc::isUc(txtOption1)) {
                    cout << "Students of Uc " + txtOption1 + " are:" << endl;
                    Uc::printStudentsInAUc(txtOption1);
                    cout << endl;
                    system("PAUSE");
                    system("CLS");
                    break;
                }
                else {
                    cout << RED << "Uc " + txtOption1 + " does not exist!" << RESET << endl;
                }
            }

            ucMenu();
            break;
        case 3:
            while (true) {
                cout << "Insert the Code of the Desired Uc:";
                cin >> txtOption1;
                cout << endl;

                if (Uc::isUc(txtOption1)) {
                    cout << "Total Count of Students Enrolled in the Uc " + txtOption1 + " is: " << Uc::getStudentCount(txtOption1) << endl;
                    cout << endl;
                    system("PAUSE");
                    system("CLS");
                    break;
                }
                else {
                    cout << RED << "Uc " + txtOption1 + " does not exist!" << RESET << endl;
                }
            }

            ucMenu();
            break;
        case 0:
            system("CLS");
            displayMenu();
            break;
        default:
            cout << RED << "Invalid Option!" << RESET << endl;
            system("PAUSE");
            system("CLS");
            ucMenu();
    }
}