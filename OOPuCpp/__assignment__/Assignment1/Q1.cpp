#include <iostream>

using namespace std;

enum Day
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main()
{
    int dayNumber;

    cout << "Enter a day number (0 for Sunday, 1 for Monday, ..., 6 for Saturday): ";
    cin >> dayNumber;

    if (dayNumber < 0 || dayNumber > 6)
    {
        cout << "Invalid day number. Please enter a number between 0 and 6." << endl;
        return 1;
    }

    Day day = static_cast<Day>(dayNumber);

    switch (day)
    {
    case Sunday:
        cout << "The day is Sunday." << endl;
        break;
    case Monday:
        cout << "The day is Monday." << endl;
        break;
    case Tuesday:
        cout << "The day is Tuesday." << endl;
        break;
    case Wednesday:
        cout << "The day is Wednesday." << endl;
        break;
    case Thursday:
        cout << "The day is Thursday." << endl;
        break;
    case Friday:
        cout << "The day is Friday." << endl;
        break;
    case Saturday:
        cout << "The day is Saturday." << endl;
        break;
    default:
        cout << "Unexpected error." << endl;
        break;
    }

    return 0;
}
