#include <iostream>
using namespace std;

int main()
{
    int size;

    // Ask the user for the array size
    cout << "Enter the number of elements: ";
    cin >> size;

    // Allocate memory dynamically for an array of integers
    int *arr = new int[size];

    // Input values into the array
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Display the array elements
    cout << "Array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free the allocated memory
    delete[] arr;

    cout << "Memory has been released." << endl;

    cout << "Array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
