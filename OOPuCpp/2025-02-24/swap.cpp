#include<iostream>
using namespace std;

// void swap(int &k, int &l) Incase of Call by Reference (&)
void swap(int *k, int *l)
{
    // int s=k;
    // k=l;
    // l=s;
    int s=*k;
    *k=*l;
    *l=s;
}
int main()
{
    int a,b;
    cout<<"Enter value for a and b: ";
    cin<<a<<b;
    cout<<"Before swapping: ";
    cout<<"a= "<<a<<"b= "<<b<<endl;
    //swap(a,b); Incase of Call by Reference (&)
    swap(&a, &b);
    cout<<"After swapping: ";
    cout<<"a= "<<a<<"b= "<<b<<endl;
    return 0;

}