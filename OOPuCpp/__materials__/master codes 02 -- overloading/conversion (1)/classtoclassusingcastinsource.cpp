#include <iostream>
using namespace std;

class DistanceKM {
public:
    float km;
    DistanceKM(float k) { km = k; }
};

class DistanceMiles {
public:
    float miles;

    // Constructor for conversion from DistanceKM to DistanceMiles
    DistanceMiles(DistanceKM d) {
        miles = d.km * 0.621371;  // Convert km to miles
    }

    void display() {
        cout << "Distance in miles: " << miles << endl;
    }
};

int main() {
    DistanceKM d1(10);  // 10 km
    DistanceMiles d2 = d1;  // Convert to miles
    d2.display();
    return 0;
}
