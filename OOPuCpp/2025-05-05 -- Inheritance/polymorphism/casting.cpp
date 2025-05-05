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
    Base *b;
    Derived d;
    b = &d;
    ((Derived*)b)->print();
    return 0;
}