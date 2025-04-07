#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a =1234,b=34,c=501;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<setw(7)<<a<<endl;
    cout<<setw(7)<<b<<endl;
    cout<<setw(7)<<c<<endl;
    cout<<left<<setw(7)<<a<<endl;
    cout<<left<<setw(7)<<b<<endl;
    cout<<left<<setw(7)<<c<<endl;
    return 0;
}