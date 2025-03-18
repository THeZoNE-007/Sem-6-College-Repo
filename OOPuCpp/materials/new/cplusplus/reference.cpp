#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int &m = a;
    m++;
    cout<<a<<endl;
    return 0;
}
