#include <iostream>
#include <cstring>
using namespace std;
class String {
    char *str;
    int length;

public:
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String(const char *s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String &s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    String add(const String &s) {
        String temp;
        temp.length = length + s.length;
        delete[] temp.str;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    void display() {
        cout << str << endl;
    }

    ~String() {
        delete[] str;
    }
};

int main() {
    String s1;
    String s2("Well done!");
    String s3(" Keep it up!");
    String s4 = s2.add(s3);
    s4.display();
    return 0;
}