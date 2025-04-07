#include <iostream>
using namespace std;

// Function to allocate memory for a 1D array
int* allocate1DArray(int size) {
    return new int[size];
}

// Function to deallocate memory for a 1D array
void deallocate1DArray(int* arr) {
    delete[] arr;
}

int main() {
    int size;

    // Get the size of the array
    cout << "Enter the number of elements: ";
    cin >> size;

    // Allocate memory
    int* arr = allocate1DArray(size);

    // Input elements
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Display elements
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deallocate memory
    deallocate1DArray(arr);
    cout << "Memory has been released." << endl;

    return 0;
}
