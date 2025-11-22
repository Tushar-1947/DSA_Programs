#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

void insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPosition(int pos, int val) {  
    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    Node* temp = head;

    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, position;

    cout << "1. Insert at Beginning\n";
    cout << "2. Insert at End\n";
    cout << "3. Insert at Position\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    while (choice != 5) {
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
        }
        else if (choice == 3) {
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter value: ";
            cin >> value;
            insertAtPosition(position, value);
        }
        else if (choice == 4) {
            display();
        }
        else {
            cout << "Invalid choice!\n";
        }

        cout << "\nEnter your choice: ";
        cin >> choice;
    }

    return 0;
}
