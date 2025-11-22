#include <iostream>
using namespace std;

class BinaryTree {
public:
    int tree[100];
    int size;

    BinaryTree() {
        size = 0;
        for (int i = 0; i < 100; i++)
            tree[i] = -1;   // -1 means empty
    }

    void insert(int value) {
        tree[size] = value;
        size++;
        cout << "Inserted: " << value << endl;
    }

    void display() {
        cout << "Binary Tree (Array Representation): ";
        for (int i = 0; i < size; i++)
            cout << tree[i] << " ";
        cout << endl;
    }

    void showRelations() {
        cout << "\nNode Relations:\n";
        for (int i = 0; i < size; i++) {
            cout << "Node " << tree[i] << " at index " << i;

            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < size)
                cout << ", Left Child = " << tree[left];
            if (right < size)
                cout << ", Right Child = " << tree[right];

            cout << endl;
        }
    }
};

int main() {
    BinaryTree bt;
    int choice, value;

    cout << "1. Insert Node\n2. Display Tree\n3. Show Parent/Child Relations\n4. Exit\n";

    cout << "Enter choice: ";
    cin >> choice;

    while (choice != 4) {
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            bt.insert(value);
        }
        else if (choice == 2) {
            bt.display();
        }
        else if (choice == 3) {
            bt.showRelations();
        }
        else {
            cout << "Invalid choice!" << endl;
        }

        cout << "\nEnter choice: ";
        cin >> choice;
    }

    return 0;
}
