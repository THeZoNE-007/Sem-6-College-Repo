#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void draw() = 0;//pure virtual function 
};
class Triangle : public Shape
{
public:
    void draw()
    {
        cout << "Triangle Drawn"<<endl;
    }
};
class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Circle Drawn"<<endl;
    }
};
int main()
{
    Shape *p;
    Triangle T;
    Circle C;
    p = &T;
    p->draw();
    p = &C;
    p->draw();
    return 0;
}