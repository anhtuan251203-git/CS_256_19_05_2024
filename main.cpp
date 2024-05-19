#include<iostream>
#include <conio.h>
#include"Course.h"
#include<cctype>
#include <limits>

using namespace std;


Course CS_256("CS_256");
static int student_id_auto_increasement = 1;
Time currentTime(01, 01, 1990);


void getChoice(int&);
void inputInformation();
void displayInformation();
void project_declaration();
void project_information();
void submit_project();
void displaysByProject();
void displaysByGroup();
void disPlayByStatus();
void overrallStat();

void displayLogo() 
{
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "\tPROJECTS SUBMISSION OF GROUPS\t\t";
    std::cout << "Today: " << currentTime.toString() << std::endl;
    std::cout << "------------------------------------------------------------------\n" << std::endl;
}

void displayMainMenu() {
    displayLogo();
    std::cout << "1. Group information\n";
    std::cout << "2. Project (assignment) deadline information\n";
    std::cout << "3. Submit project\n";
    std::cout << "4. Statistic\n";
    std::cout << "5. Overall Statistic\n";
    std::cout << "6. Find groups do not complete or submit on time\n";
    std::cout << "7. Save\n";
    std::cout << "8. Load\n"; 
    std::cout << "9. Quit\n";
}

void displaySubMenu1() {
    displayLogo();
    std::cout << "Group information:\n";
    std::cout << "1.1 Input information\n";
    std::cout << "1.2 Display information\n";
    std::cout << "1.3 Quit\n";
}

void Pause() {
    _getch();
}

int main() {
    currentTime.getCurrentTime();
    std::cout << currentTime.toString() << std::endl;
    int choice;
    do {
        system("cls");
        displayMainMenu();
        getChoice(choice);

        switch (choice) {
        case 1:
        {
            int choice_1 = 0;

            do {
                system("cls");
                displaySubMenu1();
                getChoice(choice_1);
                switch (choice_1) {
                    case 1: {
                        system("cls");
                        displayLogo();
                        std::cout << "Input information\n";
                        inputInformation();
                        system("pause");
                        break;
                    }
                    case 2: {
                        system("cls");
                        displayLogo();
                        std::cout << "Display information\n";
                        displayInformation();
                        system("pause");
                        break;
                    }
                    case 3:
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                        system("pause");
                        break;
                    }
            } while (choice_1 != 3);
            break;
        }
        case 2: {
            int choice_2 = 0;
            do {
                system("cls");
                displayLogo();
                std::cout << "Project (assignment) deadline information:\n";
                std::cout << "2.1 Project declaration\n";
                std::cout << "2.2 Project information\n";
                std::cout << "2.3 Quit\n";
                getChoice(choice_2);
                switch (choice_2) {
                    case 1: {
                        system("cls");
                        displayLogo();
                        std::cout << "Project declaration\n";
                        project_declaration();
                        system("pause");
                        break;
                    }
                    case 2: {
                        system("cls");
                        displayLogo();
                        std::cout << "Project information\n";
                        project_information();
                        system("pause");
                        break;
                    }
                    case 3:
                        break;
                    }
            } while (choice_2 != 3);
            break;
        }
        case 3: {
            system("cls");
            displayLogo();
            std::cout << "Submit project\n";
            submit_project();
            system("pause");
            break;
        }
        case 4: {
            int choice_4 = 0;
            do {
                system("cls");
                displayLogo();
                std::cout << "Statistic\n";
                std::cout << "4.1 Displays a table show the state of submission of a project for groups\n";
                std::cout << "4.2 Displays a table show the state of submission of all projects  of a group.\n";
                std::cout << "4.3 Quit\n";
                getChoice(choice_4);
                switch (choice_4) {
                    case 1: {
                        system("cls");
                        displayLogo();
                        std::cout << "Displays a table show the state of submission of a project for groups.\n";
                        displaysByProject();
                        choice_4 = 0;
                        system("pause");
                        break;
                    }
                    case 2: {
                        system("cls");
                        displayLogo();
                        std::cout << "Displays a table show the state of submission of all projects  of a group.\n";
                        displaysByGroup();
                        choice_4 = 0;
                        system("pause");
                        break;
                    }
                    case 3: {break; }
                    default: {
                        std::cout << "Invalid choice. Please try again.\n";
                        system("pause");
                        break; }
                    }
            } while (choice_4 != 3);
            system("pause");
            break; }
        case 5: {
            system("cls");
            displayLogo();
            std::cout << "Overall Statistic\n";
            overrallStat();
            system("pause");
            break;
        }
        case 6: {
            system("cls");
            displayLogo();
            std::cout << "Find groups do not complete or submit on time\n";
            disPlayByStatus();
            system("pause");
            break; }
        case 7: {
            system("cls");
            displayLogo();
            std::cout << "Save group information\n";
            CS_256.saveAllGroupInfor("group.dat");
            CS_256.saveAllProjectInfor("project.dat");
            CS_256.saveAllSubmissionInfor("submission.dat");
            system("pause");
            break;
        }
        case 8: {
            system("cls");
            displayLogo();
            std::cout << "Load group information\n";
            CS_256.loadAllGroupInfor("group.dat");
            CS_256.loadAllProjectInfor("project.dat");
            CS_256.loadAllSubmissionInfor("submission.dat");
            system("pause");
            break;
        }
        case 9: {
            system("cls");
            displayLogo();
            std::cout << "Quitting...\n";
            exit(0);
            return 0;
            break; }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            Pause();
            break;
        }
               std::cout << std::endl;
        }
    } while (choice != 9);
    
    return 0;
}

void getChoice(int& choice) {
    while (true) 
    {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Check if the input is a valid integer
        if (std::cin.fail())
        {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        }
        else 
        {
            break; // Input is valid, exit the loop
        }
    }
}

void inputInformation() {
    int num;
    std::string name;
    std::cout << "The number of groups in the class? ";
    std::cin >> num;
    ////////CS_256.setNumbeOfGroups(num);push
    std::cout << std::endl;
    for (int i = 1; i <= num; i++)
    {
        CS_256.addNewGroup(i);
        int numstudent;
        std::cout << "How many students in group " << i << "? ";
        while (true) {
            std::cin >> numstudent;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number:" << std::endl;
            }
            else {
                break;
            }
        }
        while (numstudent < 1) {
            std::cout << "Each group has at least one member. Please re-enter data: ";
            std::cin >> numstudent;
        }
        std::cin.clear();
        std::cin.ignore();
        for (int j = 1; j <= numstudent; j++)
        {
            std::cout << "Name of student " << j << ": ";
            getline(std::cin, name);
            CS_256.addNewStudent(student_id_auto_increasement, name);
            Student* student = CS_256.findStudentByID(student_id_auto_increasement);
            CS_256.addStudentToAGroup(student, i);
            student_id_auto_increasement++;
        }
        std::cout << std::endl;
    }
}

void displayInformation() {
    char display;
    int groupID;
    do
    {
        std::cout << "Do you want to display information for the whole class or by group (A/E(for the whole class/for each group)) ";
        std::cin >> display;
        if (tolower(display) == 'a') {
            for (int i = 1; i <= CS_256.getNumberOfGroups(); i++) {
                CS_256.findGroupByID(i)->displayGroupInfor();
            }
        }
        else
            if (tolower(display) == 'e') {
                std::cout << "What group you want to display information? ";
                std::cin >> groupID;
                CS_256.findGroupByID(groupID)->displayGroupInfor();
            }
            else { std::cout << "Just type A or E"; }
        std::cout << "If you want to continue displaying more information press Y, otherwise press any key: ";
        std::cin >> display;
    } while (tolower(display) == 'y');
}

void project_declaration() {
    int numproject;
    std::cout << "How many projects in the course: ";
    std::cin >> numproject;
    for (int i = 1; i <= numproject; i++) {
        std::cout << "Project " << i << "\n";
        int id, d, m, y;
        std::string description;
        std::cout << "ID:";
        std::cin >> id;
        std::cout << "Description: ";
        std::cin.ignore();
        getline(std::cin, description);
        std::cout << "Deadline(dd mm yyyy): ";
        std::cin >> d >> m >> y;
        Time deadline(d, m, y);
        std::cout << std::endl;
        CS_256.addNewProject(id, deadline);
        CS_256.findProjectbyID(id)->setDescription(description);
    }
}
void project_information() {
    int projectID;
    std::cout << "Enter ID to display the project you want to look up: ";
    std::cin >> projectID;
    std::cout << std::endl;
    while (CS_256.findProjectbyID(projectID) == nullptr) {
        std::cout << "There is no project with ID " << projectID << "." << std::endl;
        std::cout << "Please try again or type -1 to exit: ";
        cin >> projectID;
        if (projectID == -1) {
            return;
        }
    }
    std::cout << "Project " << CS_256.findProjectbyID(projectID)->getProjectID() << std::endl;
    std::cout << "Description:\n\t" << CS_256.findProjectbyID(projectID)->getDescription() << std::endl;
    std::cout << "Deadline: " << CS_256.findProjectbyID(projectID)->getDueDate().toString() << std::endl;
}

void submit_project() {
    int groupID, projectID, sd, sm, sy;
    char submitt;
    std::cout << "***If you have submitted your assignment, press S, otherwise enter anything***\n";
    for (projectID = 1; projectID <= CS_256.getNumberOfProjects(); projectID++) {
        std::cout << "+Project " << projectID << '\n';
        for (groupID = 1; groupID <= CS_256.getNumberOfGroups(); groupID++) {
            std::cout << "\t+Group " << groupID << ':';
            std::cin >> submitt;
            if (submitt == 'S') {
                std::cout << "\n\tSubmission date(dd mm yyyy): ";
                std::cin >> sd >> sm >> sy;
                Time submissiondate(sd, sm, sy);
                CS_256.submit(groupID, projectID, submissiondate);
            }
        }
    }
}

void displaysByProject() {
    int pid;
    std::cout << "Please enter project ID: ";

    std::cin >> pid;

    CS_256.statSubmissionByProjectID(pid, currentTime);
}
void displaysByGroup() {
    int gid;
    std::cout << "Please enter group ID: ";
    std::cin >> gid;
    CS_256.statSubmissionByGroupID(gid, currentTime);
}

void disPlayByStatus() {
    std::cout << "Enter Status you want to check: ";
    std::string status;
    std::cin.ignore();
    getline(std::cin, status);
    if (status == "late") {
        for (int projectID = 1; projectID <= CS_256.getNumberOfProjects(); projectID++) {
            CS_256.statSubmissionByStatus(projectID, 0);
        }
    }
    else if (status == "not_submit") {
        for (int projectID = 1; projectID <= CS_256.getNumberOfProjects(); projectID++) {
            for (int groupID = 1; groupID <= CS_256.getNumberOfGroups(); groupID++) {
                if (CS_256.findSubmission(projectID, groupID) == nullptr) {
                    if (CS_256.findProjectbyID(projectID)->getDueDate().isOnTime(currentTime) != true) {
                        std::cout << "Group " << groupID << " did not submitted project " << projectID << std::endl;
                    }
                }
            }
        }
    }
}

void overrallStat() {
    Time date = currentTime;
    char ch;
    std::cout << "Do you want to check with particular date? ";
    std::cout << "Choose Y/N (N - check with current time): ";
    std::cin >> ch;
    if (tolower(ch) == 'y') {
        std::cout << "Enter date (dd mm yyyy): ";
        int dd, mm, yyyy;
        std::cin >> dd >> mm >> yyyy;
        date = Time(dd, mm, yyyy);
        CS_256.statOverall(date);
    }
    else if (tolower(ch) == 'n') {
        CS_256.statOverall(date);
    }
}
