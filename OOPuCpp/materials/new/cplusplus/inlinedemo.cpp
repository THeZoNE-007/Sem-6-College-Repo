#include <iostream>
using namespace std;
inline int cube(int m)//function header
{
    return(m*m*m);
}
int main()
{
    int a = 5;
    int k = cube(a);//invocation/call
    cout << "Cube = " << k << endl;
    return 0;
}
double compute(double amount,int year,double ri = 6.5)
{
    .......
}

compute(10000,5);
compute(10000,5,7.2);