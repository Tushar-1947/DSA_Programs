#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
        cout << "Enqueued: " << x << endl;
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Dequeued: " << s2.top() << endl;
        s2.pop();
    }

    void peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Front element: " << s2.top() << endl;
    }

    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        // Temporary copy for display
        stack<int> a = s1, b = s2;

        // Move temp elements from s1 to b to show real queue order
        if (!a.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }

        cout << "Queue elements: ";
        while (!b.empty()) {
            cout << b.top() << " ";
            b.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;
    int choice, val;

    cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";

    cout << "Enter choice: ";
    cin >> choice;

    while (choice != 5) {

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.peek();
        }
        else if (choice == 4) {
            q.display();
        }
        else {
            cout << "Invalid choice!" << endl;
        }

        cout << "\nEnter choice: ";
        cin >> choice;
    }

    return 0;
}
