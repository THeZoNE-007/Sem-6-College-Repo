#include <iostream>
using namespace std;

int globalVar = 100;  // Definition of extern variable

void display()
{
    cout << "Global variable = " << globalVar << endl;
}
