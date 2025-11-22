#include <iostream>
using namespace std;

// Heapify function to maintain max heap property
void heapify(int arr[], int n, int i) {
    int largest = i;          // root index
    int left = 2 * i + 1;     // left child
    int right = 2 * i + 2;    // right child

    // Check if left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If root is not largest, swap and heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build max heap from array
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node: (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Display heap
void display(int arr[], int n) {
    cout << "Max Heap: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    buildMaxHeap(arr, n);

    cout << "\nAfter Building Max Heap:\n";
    display(arr, n);

    return 0;
}
