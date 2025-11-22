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

// ------------------- INSERT AT END (Helper) -------------------
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

// ------------------- DELETE BY VALUE -------------------
void deleteByValue(int val) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    // If node to delete is the head
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Value not found!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node deleted.\n";
}

// ------------------- DELETE BY POSITION -------------------
void deleteByPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node at position deleted.\n";
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node at position deleted.\n";
}

// ------------------- DISPLAY LIST -------------------
void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// ------------------- MAIN FUNCTION -------------------
int main() {
    int choice, val, pos;

    cout << "1. Insert at End\n";
    cout << "2. Delete by Value\n";
    cout << "3. Delete by Position\n";
    cout << "4. Display List\n";
    cout << "5. Exit\n";

    cout << "\nEnter choice: ";
    cin >> choice;

    while (choice != 5) {
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
        }
        else if (choice == 2) {
            cout << "Enter value to delete: ";
            cin >> val;
            deleteByValue(val);
        }
        else if (choice == 3) {
            cout << "Enter position to delete: ";
            cin >> pos;
            deleteByPosition(pos);
        }
        else if (choice == 4) {
            display();
        }
        else {
            cout << "Invalid choice!\n";
        }

        cout << "\nEnter choice: ";
        cin >> choice;
    }

    return 0;
}
