#include <iostream>
using namespace std;

void localClassDemo() {
    // Local class defined inside a function
    class Local {
    private:
        int data;
    public:
        void setData(int d) {
            data = d;
        }
        void showData() const {
            cout << "Local class data: " << data << endl;
        }
    };

    Local localObj;
    localObj.setData(100);
    localObj.showData();
}

int main() {
    localClassDemo();
    return 0;
}
