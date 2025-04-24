#include <iostream>
using namespace std;

const int EMPLOYEE_COUNT = 5;

struct Employee {
    int emID;
    string name;
    float hoursWorked;
    float payRate;
    float taxDeduction;
    float totalPayment;
    float netPayment;
};


Employee employee[EMPLOYEE_COUNT];

int main (){
intro();
menu();

return 0;
}

void intro() {
    cout << "\t\tUNIVERSITY OF GONDAR\n\n";
    cout << "Atse Tewodros Finance Office\n";
    cout << "Payroll Management System\n";
    cout << "CREATED BY:-\n";
    cout << "SAMUEL AEMRO and LEUL YEWONDWOSSEN\n\n";
    // system("cls"); // Optional
}

void input() {
    for (int i = 0; i < EMPLOYEE_COUNT; ++i) {
        cout << "\nEnter Information for Employee " << i + 1 << ":\n";

        cout << "Employee ID: ";
        cin >> employee[i].emID;
        cin.ignore();  // Clear input buffer before using getline

        cout << "Employee Name: ";
        getline(cin, employee[i].name);

        cout << "Hours Worked: ";
        cin >> employee[i].hoursWorked;

        cout << "Pay Rate: ";
        cin >> employee[i].payRate;

        cout << "-----------------------------------\n";
        employee[i].totalPayment = employee[i].hoursWorked * employee[i].payRate;
        employee[i].taxDeduction = 0.35f * employee[i].totalPayment;
        employee[i].netPayment = employee[i].totalPayment - employee[i].taxDeduction;
    }

}


void menu() {
    int choice;

    do {
        cout << "\n======= MENU ==========\n";
        cout << "1. Enter Employee Info and Calculate Payroll\n";
        cout << "2. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                input();
                break;
            case 2:
                cout << "\nThank you and Farewell!\n";
                break;
            default:
                cout << "\nInvalid option. Please try again.\n";
                // system("cls"); // Optional for Windows users
        }

    } while (choice != 2);
}