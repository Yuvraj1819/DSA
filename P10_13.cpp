#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int rollno;
    char name[30];
    char div;
    char add[30];

public:
    void accept() {
        cout << "\nEnter roll number: ";
        cin >> rollno;
        cin.ignore(); // Clear the input buffer
        cout << "Enter name: ";
        cin.getline(name, 30); // Accept full name
        cout << "Enter division: ";
        cin >> div;
        cin.ignore(); // Clear the input buffer again
        cout << "Enter address: ";
        cin.getline(add, 30); // Accept full address
    }

    void display() const {
        cout << "\n" << rollno << "\t" << name << "\t" << div << "\t" << add;
    }

    int getRollNo() const {
        return rollno;
    }
};

class StudentFileHandler {
public:
    void addRecords() {
        int n;
        Student s;
        ofstream out("Student.txt", ios::binary); // Open in binary mode
        cout << "\nEnter total number of students: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            s.accept();
            out.write((char*)&s, sizeof(s));
        }
        out.close();
    }

    void displayRecords() const {
        ifstream inf("Student.txt", ios::binary); // Open in binary mode
        Student s;
        cout << "\nRoll No\tName\tDiv\tAddress";
        while (inf.read((char*)&s, sizeof(s))) {
            s.display();
        }
        inf.close();
    }

    void addNewRecord() {
        ofstream out("Student.txt", ios::app | ios::binary); // Open in append mode
        Student s;
        s.accept();
        out.write((char*)&s, sizeof(s));
        out.close();
    }

    void updateRecord(int r) {
        ifstream inf("Student.txt", ios::binary); // Open in binary mode
        ofstream out("temp.txt", ios::binary); // Temporary file
        int flag = 0;
        Student s;
        while (inf.read((char*)&s, sizeof(s))) {
            if (s.getRollNo() == r) {
                flag = 1;
                cout << "\nUpdating record for roll number: " << r;
                s.accept();
                out.write((char*)&s, sizeof(s));
                cout << "\nRecord updated successfully.";
            } else {
                out.write((char*)&s, sizeof(s));
            }
        }
        if (flag == 0) {
            cout << "\nRecord not found!";
        }
        inf.close();
        out.close();
        remove("Student.txt");
        rename("temp.txt", "Student.txt");
    }
};

int main() {
    StudentFileHandler fileHandler;
    int ch, r;

    do {
        cout << "\n1. Add records";
        cout << "\n2. Display all records";
        cout << "\n3. Add new record";
        cout << "\n4. Update a record";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                fileHandler.addRecords();
                cout << "\nRecords added successfully!";
                break;
            case 2:
                fileHandler.displayRecords();
                break;
            case 3:
                fileHandler.addNewRecord();
                cout << "\nNew record added successfully!";
                break;
            case 4:
                cout << "\nEnter roll number to update: ";
                cin >> r;
                fileHandler.updateRecord(r);
                break;
        }
    } while (ch != 5);

    return 0;
}
