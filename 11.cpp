#include <iostream>
using namespace std;

#define SIZE 100   // maximum size of queue

int queueArr[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow!" << endl;
        return;
    }
    if (front == -1) front = 0; // first insertion
    queueArr[++rear] = val;
    cout << "Enqueued: " << val << endl;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow!" << endl;
        return;
    }
    cout << "Dequeued: " << queueArr[front] << endl;
    front++;
}

void peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Front element: " << queueArr[front] << endl;
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
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
            cout << "Invalid Choice!" << endl;
        }

        cout << "\nEnter choice: ";
        cin >> choice;
    }

    return 0;
}
