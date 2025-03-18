#include <iostream>
using namespace std;

class Counter {
private:
    int id;
public:
    static int count;

    void assignId() {
        id = ++count;
    }

    void showId() const {
        cout << "Object ID: " << id << endl;
    }

    static void showCount() {
        cout << "Total objects created: " << count << endl;
    }
};

int Counter::count = 0;

int main() {
    Counter c1, c2;
    c1.assignId();
    c2.assignId();
    c1.showId();
    c2.showId();
    Counter::showCount();
    return 0;
}
