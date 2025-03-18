#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double number = 12.34567;
    cout << setprecision(3) << number << " "
         << setprecision(4) << number << " "
         << setprecision(5) << number << " "
         << setprecision(6) << number << endl;
    return 0;
}