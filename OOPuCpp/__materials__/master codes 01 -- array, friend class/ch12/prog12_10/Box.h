// Box.h Definition of the Box class
#ifndef BOX_H
#define BOX_H

class Box {
  public:
    // Constructors
    Box();
    Box(double lengthValue, double widthValue, double heightValue);

    // Function to calculate the volume of a box
    double volume() const;

    // Function to compare two Box objects
    int compareVolume(const Box& otherBox) const;

    int getObjectCount() const {return objectCount;}

  private:
    static int objectCount;            // Count of objects in existence
    double length;
    double width;
    double height;
}; //length + width + height = 8bytes * 3 = 24 bytes. Remember static is never stored as an object, it's shared by all. Its size to be not considered.

#endif
