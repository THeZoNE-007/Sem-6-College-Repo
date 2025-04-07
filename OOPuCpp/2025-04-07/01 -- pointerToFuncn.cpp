#include <iostream>
using namespace std;

class MyClass
{
   
public:
    int a;
    double b;
    
    void show(){
        cout<<"Inside show(): a= "<<a<<" b= "<<b;
    }
    void setVal(int x,double y){
         a=x;
         b=y;
    }
    
};

int main()
{
 
     MyClass obj;
     
     // pointer to data member
     int MyClass::*ptrToA = &MyClass::a;
     double MyClass::*ptrToB = &MyClass::b;
     
     // pointer to memeber functions
    void (MyClass::*ptrToShow)() = &MyClass::show;
    void (MyClass::*ptrToSetVal)(int,double) = &MyClass::setVal;
    
    // access data members function using pointer
    obj.*ptrToA = 10;
    obj.*ptrToB = 3.14;
    
    //call member functions using pointers
    (obj.*ptrToShow)();
    (obj.*ptrToSetVal)(21,4.20);
    cout<<" "<<endl; 
    (obj.*ptrToShow)();
    return 0;
}
