#include <iostream>

int main() {
    // Anonymous enum
    enum { RED = 1, GREEN, BLUE };

    std::cout << "RED: " << RED << std::endl;
    std::cout << "GREEN: " << GREEN << std::endl;
    std::cout << "BLUE: " << BLUE << std::endl;

    int color = GREEN;  // Directly using the enum value
    if (color == GREEN) {
        std::cout << "Selected color is GREEN!" << std::endl;
    }

    return 0;
}
