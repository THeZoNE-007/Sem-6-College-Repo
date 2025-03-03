#include<iostream>
using namespace std;
int max(int int); //prototype declaration

int main() {
    int a, b;
    cout << "Enter value for a and b: ";
    cin >> a >> b;
    int m = max ( a, b ); //invocation; inside are called arguments
    cout<<"Max value is = "<<m<<endl;
    return 0;
}

//defination; inside are called parameter
int max(int k, int l) {
    if(k>l)
    {
        return k;
    }
    else
    {
        return l;
    }
}

// Function name + Parameter = Function Signature
