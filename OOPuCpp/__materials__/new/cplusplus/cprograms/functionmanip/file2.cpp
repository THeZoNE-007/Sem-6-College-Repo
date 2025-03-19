#include <iostream>

using namespace std;

extern int globalVar;  // Declaration (defined in another file)

int main()
{
    cout << "Extern variable = " << globalVar << endl;
    return 0;
}
