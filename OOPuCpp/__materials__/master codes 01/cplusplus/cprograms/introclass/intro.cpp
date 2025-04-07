#include <iostream>
using namespace std;

class Sample {
private:
    int privateData;
public:
    int publicData;

    void setPrivateData(int value) {
        privateData = value;
    }

    int getPrivateData() const {
        return privateData;
    }

    void display() const {
        cout << "Private Data: " << privateData 
             << ", Public Data: " << publicData << endl;
    }
};

int main() {
    Sample obj;
    obj.publicData = 10;
    obj.setPrivateData(20);
    obj.display();
    return 0;
}
