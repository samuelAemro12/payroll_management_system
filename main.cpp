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


void intro();
void menu();
void input();
void display_employees();

int main() {
    intro();
    menu();
    return 0;
}

void intro() {
    cout << "\t\tUNIVERSITY OF GONDAR\n\n";
    cout << "Atse Tewodros Finance Office" << endl;
    cout << "Payroll Management System" << endl;
    cout << "CREATED BY: Samuel Aemro and Leul Yewondwossen" << endl;
    cout << "\n\n";
    // Optional: Commented out for cross-platform compatibility
    // system("cls");
}

void input() {
    for (int i = 0; i < EMPLOYEE_COUNT; i++) {
        cout << "\nEnter information for Employee #" << i + 1 << "\n";
        cout << "Enter Employee ID: ";
        cin >> employee[i].emID;

        cout << "Enter Employee Name: ";
        cin >> ws; // Clear newline from buffer
        getline(cin, employee[i].name); // Allows full name with spaces

        cout << "Enter hours worked: ";
        cin >> employee[i].hoursWorked;

        cout << "Enter hourly pay rate: ";
        cin >> employee[i].payRate;

        employee[i].totalPayment = employee[i].hoursWorked * employee[i].payRate;
        employee[i].taxDeduction = 0.35f * employee[i].totalPayment;
        employee[i].netPayment = employee[i].totalPayment - employee[i].taxDeduction;
    }

    display_employees();
}

void display_employees() {
    cout << "\n======= Employee Payroll Summary =======\n";

    for (int i = 0; i < EMPLOYEE_COUNT; ++i) {
        cout << "\nEmployee #" << i + 1 << "\n";
        cout << "Name: " << employee[i].name << "\n";
        cout << "ID: " << employee[i].emID << "\n";
        cout << "Hours Worked: " << employee[i].hoursWorked << "\n";
        cout << "Pay Rate: $" << employee[i].payRate << "\n";
        cout << "Total Payment: $" << employee[i].totalPayment << "\n";
        cout << "Tax Deduction (35%): $" << employee[i].taxDeduction << "\n";
        cout << "Net Payment: $" << employee[i].netPayment << "\n";
    }

    cout << "\n========================================\n";
}

void menu() {
    int choice;
    bool running = true;

    while (running) {
        cout << "======= MENU ==========\n";
        cout << "1. Enter Employee Data\n";
        cout << "2. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                input();
                break;
            case 2:
                cout << "\nThank you and Farewell!\n";
                running = false;
                break;
            default:
                cout << "\nInvalid option. Please try again.\n\n";
                break;
        }
    }
}
