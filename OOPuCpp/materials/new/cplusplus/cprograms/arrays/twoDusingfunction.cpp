#include <iostream>
using namespace std;

// Function to allocate memory for a 2D array
int** allocate2DArray(int rows, int cols) {
    int** arr = new int*[rows];  // Allocate row pointers
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];  // Allocate each row
    }
    return arr;
}

// Function to deallocate memory for a 2D array
void deallocate2DArray(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];  // Delete each row
    }
    delete[] arr;  // Delete row pointers
}

int main() {
    int rows, cols;

    // Get the size of the 2D array
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    // Allocate memory
    int** arr = allocate2DArray(rows, cols);

    // Input elements
    cout << "Enter " << rows * cols << " elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Display elements
    cout << "2D Array elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    deallocate2DArray(arr, rows);
    cout << "Memory has been released." << endl;

    return 0;
}
