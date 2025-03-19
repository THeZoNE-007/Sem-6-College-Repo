#include <iostream>
using namespace std;
//int max(int, int);//function declaration/prototype
int max(int m, int n)//function header
{
    if (m > n)
        return m;
    else
        return n;
}
int main()
{
    int a = 5, b = 10;
    int k = max(a, b);//invocation/call
    cout << "Max = " << k << endl;
    return 0;
}
