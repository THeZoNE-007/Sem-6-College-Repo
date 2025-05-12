#include <iostream>
#include <string>
using namespace std;

class Book {
    string title, author, publisher;
    float price;
public:
    Book(string t, string a, string p, float pr) {
        title = t;
        author = a;
        publisher = p;
        price = pr;
    }

    bool match(string t, string a) {
        return (title == t && author == a);
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: Rs. " << price << endl;
    }
};

int main() {
    Book books[] = {
        Book("The Alchemist", "Paulo Coelho", "HarperOne", 350),
        Book("C++ Basics", "E. Balaguruswamy", "McGraw Hill", 450)
    };
    string t, a;
    cout << "Enter book title: ";
    getline(cin, t);
    cout << "Enter author name: ";
    getline(cin, a);

    bool found = false;
    for (int i = 0; i < 2; ++i) {
        if (books[i].match(t, a)) {
            cout << "\nBook Available:\n";
            books[i].display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nBook Not Available.\n";
    return 0;
}