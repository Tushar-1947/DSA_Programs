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

Node* front = NULL;
Node* rear = NULL;

void enqueue(int val) {
    Node* newNode = new Node(val);

    if (rear == NULL) {        // queue empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Enqueued: " << val << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow!" << endl;
        return;
    }

    Node* temp = front;
    cout << "Dequeued: " << front->data << endl;

    front = front->next;

    if (front == NULL) {       // queue becomes empty
        rear = NULL;
    }

    delete temp;
}

void peek() {
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Front element: " << front->data << endl;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val;

    cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    while (choice != 5) {

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            enqueue(val);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            peek();
        }
        else if (choice == 4) {
            display();
        }
        else {
            cout << "Invalid choice!" << endl;
        }

        cout << "\nEnter choice: ";
        cin >> choice;
    }

    return 0;
}
