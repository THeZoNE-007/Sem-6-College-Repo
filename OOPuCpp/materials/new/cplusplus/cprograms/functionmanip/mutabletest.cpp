#include <iostream>
using namespace std;

class Example
{
public:
    mutable int x;  // Can change even in a const object
    Example() { x = 10; }

    void change() const
    {
        x++;  // Allowed because x is mutable
    }
};

int main()
{
    const Example obj;
    obj.change();  // Changing x inside a const object
    cout << "Mutable variable x = " << obj.x << endl;
    return 0;
}
