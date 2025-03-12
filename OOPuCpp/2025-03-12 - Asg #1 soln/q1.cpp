/*
WAP to create an enum (Day) containing 7 day names as its attributes. Prompt the user to enter a day number as int type. Assign this day number to a variable of enum Day. Using switch display the corresponding day name of the given day number. Pass the variable of Day
in switch and make the cases as attributes of Day.
*/

#include<iostream>
using namespace std;

enum Day { Sunday=1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
	int dayNum;
	cout << "Enter a day number (1-7): ";
	cin >> dayNum;
	Day d = static_cast<Day>(dayNum);
	
	switch (d) {
		case Sunday: cout << "Sunday"; break;
		case Monday: cout << "Monday"; break;
		case Tuesday: cout << "Tuesday"; break;
		case Wednesday: cout << "Wednesday"; break;
		case Thursday: cout << "Thursday"; break;
		case Friday: cout << "Friday"; break;
		case Saturday: cout << "Saturday"; break;
		default: cout << "Invalid Day Number !!";
	}
	return 0;
}
