#include <iostream>
using namespace std;

void autoExample()
{
    auto  a = 10;  // `auto` is optional; same as `int a = 10;`
    cout << "Auto variable a = " << a << endl;
}

int main()
{
    autoExample();
    return 0;
}
