#include <iostream>
#include <cstdint>  // for uintptr_t

class MyClass {
public:
    int a;      // Offset = 0
    double b;   // Likely offset = 8 (after padding)
    char c;     // Offset depends on alignment
};

int main() {
    MyClass obj;
    char* base = reinterpret_cast<char*>(&obj);

    std::uintptr_t offset_a = reinterpret_cast<char*>(&(obj.a)) - base;
    std::uintptr_t offset_b = reinterpret_cast<char*>(&(obj.b)) - base;
    std::uintptr_t offset_c = reinterpret_cast<char*>(&(obj.c)) - base;

    std::cout << "Offset of a: " << offset_a << " bytes" << std::endl;
    std::cout << "Offset of b: " << offset_b << " bytes" << std::endl;
    std::cout << "Offset of c: " << offset_c << " bytes" << std::endl;

    return 0;
}
