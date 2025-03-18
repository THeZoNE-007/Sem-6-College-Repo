#include <iostream>

using namespace std;

// Defining an enumerated data type for days of the week
enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

int main() {
    Day today;  // Declaring a variable of type Day

    today = WEDNESDAY;  // Assigning an enum value

    // Display the value of the enumerated type
    cout << "Today is day number: " << today << endl;  // Output will be 3

    // Using enum in a switch statement
    switch (today) {
        case SUNDAY:
            cout << "It's a weekend!" << endl;
            break;
        case MONDAY:
            cout << "Start of the workweek!" << endl;
            break;
        case WEDNESDAY:
            cout << "Midweek day!" << endl;
            break;
        case FRIDAY:
            cout << "Weekend is coming!" << endl;
            break;
        default:
            cout << "A regular weekday!" << endl;
    }

    return 0;
}
