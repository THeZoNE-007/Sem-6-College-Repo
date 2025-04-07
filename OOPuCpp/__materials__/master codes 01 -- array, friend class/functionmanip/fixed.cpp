#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double number = 232123434.357;
    cout << number << endl;
    cout << fixed << number << endl;
    cout << fixed << setprecision(3) << number << endl;
    return 0;
}
