#include <iostream>
using namespace std;

// Correct macro definition with parentheses around each argument
#define MAX_OF_THREE(a, b, c) (((a) > (b)) ? (((a) > (c)) ? (a) : (c)) : (((b) > (c)) ? (b) : (c)))

int main()
{
    int x, y, z;
    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    // Pass correct variables to the macro
    cout << "Largest number: " << MAX_OF_THREE(x, y, z) << endl;

    return 0;
}

