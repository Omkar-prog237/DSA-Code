#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 10

struct Employee {
    string name;
    long int employee_id;
    string designation;
    int salary;
};

int num = -1;
Employee emp[MAX];

void insert() {
    if (num < MAX - 1) {        
        num++; 
        cout << "\nEnter the information of the Employee\n"; 
        cout << "Employee ID: ";
        cin >> emp[num].employee_id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, emp[num].name);
        cout << "Designation: ";
        getline(cin, emp[num].designation);
        cout << "Salary: ";
        cin >> emp[num].salary;
    } else {
        cout << "Employee Table is Full!\n";
    }
}

void deleteIndex(int index) {
    for (int j = index; j < num; j++) {
        emp[j] = emp[j + 1];
    }
    num--;
}

void displayAllRecords() {
    if (num == -1) {
        cout << "No records present!\n";
        return;
    }

    cout << "\n" << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(20) << "Designation"
         << setw(10) << "Salary" << "\n";

    for (int i = 0; i <= num; i++) {
        cout << setw(10) << emp[i].employee_id
             << setw(20) << emp[i].name
             << setw(20) << emp[i].designation
             << setw(10) << emp[i].salary << "\n";
    }
}

void deleteRecord() {
    int employee_id;
    cout << "Enter the Employee ID to delete: ";
    cin >> employee_id;

    for (int i = 0; i <= num; i++) {
        if (emp[i].employee_id == employee_id) {
            deleteIndex(i);
            cout << "Record deleted successfully.\n";
            return;
        }
    }
    cout << "Employee with ID " << employee_id << " not found.\n";
}

void searchRecord() {
    int employee_id;
    cout << "Enter the Employee ID to search: ";
    cin >> employee_id;

    for (int i = 0; i <= num; i++) {
        if (emp[i].employee_id == employee_id) {
            cout << "\n" << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(20) << "Designation"
                 << setw(10) << "Salary" << "\n";
            cout << setw(10) << emp[i].employee_id
                 << setw(20) << emp[i].name
                 << setw(20) << emp[i].designation
                 << setw(10) << emp[i].salary << "\n";
            return;
        }
    }

    cout << "Employee with ID " << employee_id << " not found.\n";
}

int main() {
    int option = 0;

    while (option != 5) {
        cout << "\n----- Employee Management System -----\n";
        cout << "1. Insert New Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Delete Record\n";
        cout << "4. Search Record by Employee ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Please enter a valid option (1-5).\n";
                break;
        }
    }

    return 0;
}
