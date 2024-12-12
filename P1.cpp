#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void bubble(Student student[], int n) {
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            if (student[i].rollNo > student[i + 1].rollNo) {
                swap(student[i], student[i + 1]);
            }
        }
    }
}

void insertion(Student student[], int n) {
    for (int i = 1; i < n; i++) {
        Student temp = student[i];
        int j = i - 1;
        while (j >= 0 && student[j].name > temp.name) {
            student[j + 1] = student[j];
            j--;
        }
        student[j + 1] = temp;
    }
}

void display(Student student[], int n) {
    cout << "\nRoll No\tName\t\tSGPA\n";
    for (int i = 0; i < n; i++) {
        cout << student[i].rollNo << "\t" << student[i].name << "\t\t" << student[i].sgpa << endl;
    }
    cout << endl;
}

int binarysearch(Student student[], int n) {
    string tar;
    int st = 0, end = n - 1;

    cout << "Enter the Name of the student you want to search: ";
    cin >> tar;

    while (st <= end) {
        int mid = (st + end) / 2;
        if (student[mid].name < tar) {
            st = mid + 1;
        } else if (student[mid].name > tar) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int n, ch;
    Student student[30];

    cout << "Enter the number of Students (max 30): ";
    cin >> n;
    if (n > 30 || n <= 0) {
        cout << "Invalid number of students. Please restart the program.\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter the Roll No of Student " << i + 1 << ": ";
        cin >> student[i].rollNo;
        cout << "Enter the Name of Student " << i + 1 << ": ";
        cin >> student[i].name;
        cout << "Enter the SGPA of Student " << i + 1 << ": ";
        cin >> student[i].sgpa;
    }

    do {
        cout << "\nMenu\n";
        cout << "1. Display all Records\n";
        cout << "2. Sort by Roll No\n";
        cout << "3. Sort by Name\n";
        cout << "4. Search by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                display(student, n);
                break;

            case 2:
                bubble(student, n);
                cout << "Records sorted by Roll No.\n";
                break;

            case 3:
                insertion(student, n);
                cout << "Records sorted by Name.\n";
                break;

            case 4: {
                insertion(student, n);
                int index = binarysearch(student, n);
                if (index != -1) {
                    cout << "Student found: Roll No: " << student[index].rollNo
                         << ", Name: " << student[index].name
                         << ", SGPA: " << student[index].sgpa << endl;
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid input. Please try again.\n";
        }
    } while (ch != 5);

    return 0;
}
