#include <iostream>

using namespace std;

int main()
{
    cout << "Enter two numbers : ";
    int a, b;
    cin >> a >> b;
    cout << static_cast<double>(a) / b << endl;
    return 0;
}
