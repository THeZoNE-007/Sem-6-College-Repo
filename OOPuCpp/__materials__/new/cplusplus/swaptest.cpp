#include <iostream>
using namespace std;
void swap(int *m, int *n)//function header
{
    int s = *m;
    *m=*n;
    *n=s;
}
int main()
{
    int a = 5, b = 10;
    cout<<"Before swapping: ";
    cout<<"a = "<<a<<" b = "<<b<<endl;
    swap(&a,&b);
    cout<<"After swapping: ";
    cout<<"a = "<<a<<" b = "<<b<<endl;
    return 0;
}
/*
a =5 b =10     m=10 n=5
*/
