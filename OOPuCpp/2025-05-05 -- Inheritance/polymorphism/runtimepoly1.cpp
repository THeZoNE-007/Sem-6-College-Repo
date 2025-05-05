#include<iostream>
using namespace std;
class Base{
    public:
    void print()
    {
        cout<<"Base Class Print";
    }
};
class Derived:public Base
{
    public:
    void print()
    {
        cout<<"Derived Class Print";
    }
};
int main()
{
    Derived d;
    d.print();
    return 0;
}