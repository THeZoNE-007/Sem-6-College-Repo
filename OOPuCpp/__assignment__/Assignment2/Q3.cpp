#include <iostream>
using namespace std;

class DB;

class DM
{
private:
    int meters;
    int centimeters;

public:
    void input(int m, int cm)
    {
        meters = m;
        centimeters = cm;
    }

    void display()
    {
        cout << "Distance in DM (Meters and Centimeters): " << meters << " meters " << centimeters << " cm" << endl;
    }

    friend void addDistance(DM &dmObj, DB &dbObj);
};

class DB
{
private:
    int feet;
    int inches;

public:
    void input(int ft, int in)
    {
        feet = ft;
        inches = in;
    }

    void display()
    {
        cout << "Distance in DB (Feet and Inches): " << feet << " feet " << inches << " inches" << endl;
    }

    friend void addDistance(DM &dmObj, DB &dbObj);
};

void addDistance(DM &dmObj, DB &dbObj)
{
    int totalCentimeters = dmObj.meters * 100 + dmObj.centimeters;
    int totalInches = dbObj.feet * 12 * 2.54 + dbObj.inches * 2.54;

    int totalCentimetersResult = totalCentimeters + totalInches;
    int resultMeters = totalCentimetersResult / 100;
    int resultCentimeters = totalCentimetersResult % 100;

    dmObj.meters = resultMeters;
    dmObj.centimeters = resultCentimeters;

    cout << "Result of addition (DM object): " << dmObj.meters << " meters " << dmObj.centimeters << " cm" << endl;
}

int main()
{
    DM dm1;
    DB db1;

    dm1.input(5, 60);
    db1.input(16, 4);

    dm1.display();
    db1.display();

    addDistance(dm1, db1);

    return 0;
}
