#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Get dimensions of the 2D array
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    // Allocate memory for a 2D array (array of pointers)
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];  // Allocate memory for each row
    }

    // Input elements into the 2D array
    cout << "Enter " << rows * cols << " elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Display the 2D array
    cout << "2D Array elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];  // Free each row
    }
    delete[] arr;  // Free the array of pointers

    cout << "Memory has been released." << endl;

    return 0;
}
