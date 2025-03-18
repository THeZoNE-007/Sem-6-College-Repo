#include <iostream>
using namespace std;

void registerExample()
{
    register int count = 5;  // Stored in CPU register (if possible)
    cout << "Register variable count = " << count << endl;
}

int main()
{
    registerExample();
    return 0;
}
