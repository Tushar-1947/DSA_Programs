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

Node* topNode = NULL;   // top of stack

void push(int val) {
    Node* newnode = new Node(val);
    newnode->next = topNode;
    topNode = newnode;
    cout << "Pushed: " << val << endl;
}

void pop() {
    if (topNode == NULL) {
        cout << "Stack Underflow!" << endl;
        return;
    }
    cout << "Popped: " << topNode->data << endl;
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
}

void peek() {
    if (topNode == NULL) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Top element: " << topNode->data << endl;
}

void display() {
    if (topNode == NULL) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements: ";
    Node* temp = topNode;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val;

    cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";

    cout << "Enter choice: ";
    cin >> choice;

    while (choice != 5) {

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            push(val);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            peek();
        }
        else if (choice == 4) {
            display();
        }
        else {
            cout << "Invalid Choice!" << endl;
        }

        cout << "\nEnter choice: ";
        cin >> choice;
    }

    return 0;
}
