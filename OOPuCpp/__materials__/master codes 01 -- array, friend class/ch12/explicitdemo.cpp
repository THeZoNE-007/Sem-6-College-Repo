#include<iostream>
using namespace std;
class Cube
{
   public:
   double side;
   explicit Cube(double side);
   double volume();
   bool compareVolume(Cube aCube);
};
Cube::Cube(double length):side(length){}
double Cube::volume() { return side*side*side;}
bool Cube::compareVolume(Cube aCube)
{
   return volume() > aCube.volume();
}
int main()
{
  Cube box1(5.0);
  Cube box2(3.0);
  /*if(box1.compareVolume(box2))
    cout<<"volume of box1 is greater than box2"<<endl;
   else
    cout<<"volume of box1 is not greater than box2"<<endl;*/

 if(box1.compareVolume(50.0))  //Cube(50.0)
    cout<<"volume of box1 is greater than 50"<<endl;
   else
    cout<<"volume of box1 is not greater than 50"<<endl;
  return 0;
}

