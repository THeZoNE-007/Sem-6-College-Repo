// Program 12.5 Creating a copy of an object    File: prog12_05.cpp
#include <iostream>
#include "Box.h"

using std::cout;
using std::endl;

int main() {
  cout << endl;

  Box firstBox;
  cout<<firstBox.getLength()<<endl;
  cout<<firstBox.getWidth()<<endl;
  cout<<firstBox.getHeight()<<endl;

  cout << "Volume of first box = "
       << firstBox.volume()
       << endl;

  firstBox.setLength(20);
  firstBox.setWidth(30);
  firstBox.setHeight(40);
  cout << "Volume of First box after setting values = "
       << firstBox.volume()
       << endl;

  return 0;
}
