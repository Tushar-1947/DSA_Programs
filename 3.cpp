#include <iostream>
using namespace std;

int main() {
    int arr[100], n, pos, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Traversal
    cout << "\nArray elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Insertion
    cout << "\n\nEnter position to insert (0-based index): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;

    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;

    cout << "\nArray after insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Deletion
    cout << "\n\nEnter position to delete (0-based index): ";
    cin >> pos;

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;

    cout << "\nArray after deletion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
