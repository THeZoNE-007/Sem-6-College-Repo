#include <iostream>
#include <string>
using namespace std;
// Aggregation Example
class Address
{
private:
    string street;
    string city;

public:
    Address(const string &street, const string &city) : street(street), city(city) {}

    void display() const
    {
        cout << "Street: " << street << ", City: " << city << endl;
    }
};

class Student
{
private:
    string name;
    Address *address; // Student "has a" Address (Aggregation)

public:
    Student(const string &name, Address *address) : name(name), address(address) {}

    void display() const
    {
        cout << "Name: " << name << endl;
        if (address)
        {
            cout << "Address: ";
            address->display();
        }
        else
        {
            cout << "Address is Null" << endl;
        }
    }
    ~Student()
    {
        cout << "Student Destructor Called" << endl;
    }
};
/*class Department
{
private:
    string deptName;
    Student *students[100]; // Department has many students
    int numStudents;

public:
    Department(const string &name) : deptName(name), numStudents(0) {}

    void addStudent(Student *student)
    {
        if (numStudents < 100)
        {
            students[numStudents++] = student;
        }
        else
        {
            cout << "Department is full, cannot add more students." << endl;
        }
    }

    void displayStudents() const
    {
        cout << "Department Name: " << deptName << endl;
        for (int i = 0; i < numStudents; ++i)
        {
            students[i]->display();
        }
    }
    ~Department()
    {
        cout << "Department destructor called" << endl;
    }
};*/

int main()
{
    // Aggregation
    cout << "Aggregation Example:\n";
    
    Address *workAddress = new Address("456 Business Ave", "Workville");
    Student student2("Bob", workAddress); // student2 has a workAddress
    student2.display();

    delete workAddress; // important:  need to delete, otherwise memory leak.
                        // student2 no longer has a valid address.
    student2 = Student("Bob", nullptr); // Reset to avoid accessing freed memory
    student2.display(); // display Bob, who no longer has a valid address.

    cout << "\n";
    /*Department csDept("Computer Science");
    csDept.addStudent(&student1);
    csDept.addStudent(&student2);
    csDept.displayStudents();

    cout << "\n";*/

    return 0;
}

/*
✔ Student does not own the Address; it's passed via pointer.

✔ Address is created outside and managed externally.

✔ Explicitly deletes dynamically allocated workAddress, which is good practice.

*/