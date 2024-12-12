
#include <iostream>
using namespace std;

// Define a Node structure
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning of the list
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end of the list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific position
    void insertAtPosition(int val, int position) {
        if (position <= 0) {
            cout << "Position should be greater than 0." << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position is out of bounds." << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Traverse and display the list
    void traverse() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Search for an element in the list
    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    SinglyLinkedList sll;
    int choice, value, position;

    do {
        cout << "\nMenu: ";
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Specific Position";
        cout << "\n4. Traverse and Display";
        cout << "\n5. Search for an Element";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                sll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                sll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position to insert: ";
                cin >> value >> position;
                sll.insertAtPosition(value, position);
                break;
            case 4:
                cout << "Linked List: ";
                sll.traverse();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (sll.search(value)) {
                    cout << "Element " << value << " found in the list." << endl;
                } else {
                    cout << "Element " << value << " not found in the list." << endl;
                }
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
