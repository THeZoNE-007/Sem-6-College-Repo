#include <iostream>
using namespace std;

class DB; // Forward declaration of DB class

class DM {
private:
    int meters;
    int centimeters;

public:
    // Constructor to initialize DM object
    DM(int m = 0, int cm = 0) : meters(m), centimeters(cm) {}

    // Friend function to add DM and DB objects
    friend DM addDistances(const DM& dm, const DB& db);

    // Function to display distance in meters and centimeters
    void display() const {
        cout << "Distance: " << meters << " meters and " << centimeters << " centimeters" << endl;
    }
};

class DB {
private:
    int feet;
    int inches;

public:
    // Constructor to initialize DB object
    DB(int f = 0, int in = 0) : feet(f), inches(in) {}

    // Friend function to add DM and DB objects
    friend DM addDistances(const DM& dm, const DB& db);

    // Function to display distance in feet and inches
    void display() const {
        cout << "Distance: " << feet << " feet and " << inches << " inches" << endl;
    }
};

// Friend function to add distances from DM and DB objects
DM addDistances(const DM& dm, const DB& db) {
    // Convert DB (feet & inches) to meters & centimeters
    double totalInches = db.feet * 12 + db.inches;       // Total inches
    double totalMeters = totalInches * 0.0254;          // Convert inches to meters
    int metersFromDB = static_cast<int>(totalMeters);   // Extract whole meters
    int centimetersFromDB = static_cast<int>((totalMeters - metersFromDB) * 100); // Extract remaining centimeters

    // Add distances from DM and converted DB
    int totalMeters = dm.meters + metersFromDB;
    int totalCentimeters = dm.centimeters + centimetersFromDB;

    // Normalize centimeters (if >= 100)
    if (totalCentimeters >= 100) {
        totalMeters += totalCentimeters / 100;
        totalCentimeters %= 100;
    }

    return DM(totalMeters, totalCentimeters); // Return result as a DM object
}

int main() {
    int m, cm, f, in;

    // Input for DM object
    cout << "Enter distance in DM (meters and centimeters): ";
    cin >> m >> cm;
    
    DM distanceM(m, cm);

    // Input for DB object
    cout << "Enter distance in DB (feet and inches): ";
    cin >> f >> in;

    DB distanceB(f, in);

    // Add distances using the friend function
    DM result = addDistances(distanceM, distanceB);

    // Display results
    cout << "\nResult of addition:\n";
    result.display();

    return 0;
}

