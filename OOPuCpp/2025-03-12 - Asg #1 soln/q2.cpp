/*
Write a function using reference variables as arguments to swap the values of a pair of integers.
*/

#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    swap(x,y);
    cout << "Swapped values: " << x << " " << y;
    return 0;
}