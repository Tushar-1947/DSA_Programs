#include <iostream>
using namespace std;

int main() {
    int base, rows, cols, i, j, size;

    cout << "Enter base address: ";
    cin >> base;

    cout << "Enter total rows: ";
    cin >> rows;

    cout << "Enter total columns: ";
    cin >> cols;

    cout << "Enter element indices (i j): ";
    cin >> i >> j;

    cout << "Enter size of each element (in bytes): ";
    cin >> size;

    // Row-major address
    int rowMajor = base + (i * cols + j) * size;

    // Column-major address
    int colMajor = base + (j * rows + i) * size;

    cout << "\nRow-Major Address = " << rowMajor;
    cout << "\nColumn-Major Address = " << colMajor;

    return 0;
}
