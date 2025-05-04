#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to add student data to the file
void adddata(const string& filename) {
    string roll_no, name, div, address;

    cout << "Enter Roll Number: ";
    cin >> roll_no;
    cin.ignore(); // To clear newline before getline

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Division: ";
    getline(cin, div);
    cout << "Enter Address: ";
    getline(cin, address);

    ofstream outfile(filename, ios::app);
    if (!outfile) {
        cout << "Error opening file.\n";
        return;
    }

    outfile << roll_no << "," << name << "," << div << "," << address << endl;
    cout << "Data Added Successfully.\n";

    outfile.close();
}

// Function to search a student by roll number
void searchdata(const string& filename) {
    string roll_no;
    cout << "Enter roll number to search: ";
    cin >> roll_no;

    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) {
        if (line.substr(0, line.find(',')) == roll_no) {
            found = true;
            cout << "Student Details: " << line << endl;
            break;
        }
    }

    if (!found) {
        cout << "No student found with roll number " << roll_no << ".\n";
    }

    infile.close();
}

// Function to delete a student record
void deletedata(const string& filename) {
    string roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;

    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    bool found = false;
    string tempfilename = "tmp.txt";
    ofstream tempfile(tempfilename);
    if (!tempfile) {
        cout << "Error creating temp file.\n";
        return;
    }

    while (getline(infile, line)) {
        if (line.substr(0, line.find(',')) != roll) {
            tempfile << line << "\n";
        } else {
            found = true;
        }
    }

    infile.close();
    tempfile.close();

    if (found) {
        remove(filename.c_str());
        rename(tempfilename.c_str(), filename.c_str());
        cout << "Data deleted successfully.\n";
    } else {
        remove(tempfilename.c_str()); // Clean up temp file if not found
        cout << "No student found with roll number " << roll << ".\n";
    }
}

// Function to display all student data
void displaydata(const string& filename) {
    ifstream disfile(filename);
    if (!disfile) {
        cout << "Error opening file.\n";
        return;
    }

    cout << "\nDisplaying File Contents:\n";
    string line;
    while (getline(disfile, line)) {
        cout << line << endl;
    }

    disfile.close();
}

// Main function
int main() {
    string filename = "student-info.txt";
    int choice;

    while (true) {
        cout << "\n===== Student Record Menu =====\n";
        cout << "1. Add Data To File\n";
        cout << "2. Display Data of File\n";
        cout << "3. Search a Record in File\n";
        cout << "4. Delete Record\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                adddata(filename);
                break;
            case 2:
                displaydata(filename);
                break;
            case 3:
                searchdata(filename);
                break;
            case 4:
                deletedata(filename);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Please enter a valid choice (1-5).\n";
        }
    }
}
