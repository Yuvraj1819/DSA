#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Student
{
    int rollNumber;
    string name;
    string division;
    string address;
};

void addRecord()
{
    ofstream file("students.txt", ios::app);
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    file << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;
    file.close();
    cout << "Record added successfully!" << endl;
}

void displayRecords()
{
    ifstream file("students.txt");
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    cout << "\nAll Student Records:" << endl;
    while (getline(file, line))
    {
        stringstream ss(line);
        string rollNumber, name, division, address;

        getline(ss, rollNumber, ',');
        getline(ss, name, ',');
        getline(ss, division, ',');
        getline(ss, address, ',');

        cout << "Roll Number: " << rollNumber << "\n"
             << "Name: " << name << "\n"
             << "Division: " << division << "\n"
             << "Address: " << address << "\n"
             << endl;
    }
    file.close();
}

void searchRecord()
{
    ifstream file("students.txt");
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    int rollNumberToSearch;
    cout << "Enter Roll Number to search: ";
    cin >> rollNumberToSearch;

    string line;
    bool found = false;
    while (getline(file, line))
    {
        stringstream ss(line);
        Student student;
        string rollNumber;

        getline(ss, rollNumber, ',');
        student.rollNumber = stoi(rollNumber);
        getline(ss, student.name, ',');
        getline(ss, student.division, ',');
        getline(ss, student.address, ',');

        if (student.rollNumber == rollNumberToSearch)
        {
            found = true;
            cout << "\nRecord Found:\n";
            cout << "Roll Number: " << student.rollNumber << "\n"
                 << "Name: " << student.name << "\n"
                 << "Division: " << student.division << "\n"
                 << "Address: " << student.address << "\n"
                 << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Record with Roll Number " << rollNumberToSearch << " not found!" << endl;
    }

    file.close();
}

void deleteRecord()
{
    ifstream file("students.txt");
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    vector<Student> students;
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        Student student;
        string rollNumber;

        getline(ss, rollNumber, ',');
        student.rollNumber = stoi(rollNumber);
        getline(ss, student.name, ',');
        getline(ss, student.division, ',');
        getline(ss, student.address, ',');

        students.push_back(student);
    }
    file.close();

    int rollNumberToDelete;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNumberToDelete;

    bool found = false;
    ofstream outFile("students.txt", ios::trunc);
    for (const auto &student : students)
    {
        if (student.rollNumber == rollNumberToDelete)
        {
            found = true;
            continue;
        }
        outFile << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;
    }
    outFile.close();

    if (found)
    {
        cout << "Record deleted successfully!" << endl;
    }
    else
    {
        cout << "Record with Roll Number " << rollNumberToDelete << " not found!" << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\nStudent Database Menu:\n";
        cout << "1. Add Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecords();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}