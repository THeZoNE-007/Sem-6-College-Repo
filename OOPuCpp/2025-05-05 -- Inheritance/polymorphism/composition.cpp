#include <iostream>
using namespace std;
// Composition Example
class Engine
{
private:
    std::string model;

public:
    Engine(const std::string &model) : model(model) {}

    void start() const
    {
        std::cout << "Engine " << model << " started." << std::endl;
    }
    ~Engine()
    {
        std::cout << "Engine Destructor Called" << std::endl;
    }
};

class Car
{
private:
    std::string brand;
    Engine engine; // Car "has an" Engine (Composition)

public:
    Car(const std::string &brand, const std::string &engineModel) : brand(brand), engine(engineModel) {}

    void drive() const
    {
        std::cout << "Car " << brand << " is driving." << std::endl;
        engine.start();
    }
    ~Car()
    {
        std::cout << "Car Destructor Called" << std::endl;
    }
};

/*class House
{
private:
    int numberOfRooms;
    Car garage; // House has a Car.

public:
    House(int rooms, const std::string &carBrand, const std::string &engineModel)
        : numberOfRooms(rooms), garage(carBrand, engineModel) {}

    void displayHouseDetails() const
    {
        std::cout << "Number of rooms: " << numberOfRooms << std::endl;
        std::cout << "Car in garage: " << std::endl;
        garage.drive();
    }
    ~House()
    {
        std::cout << "House destructor called" << std::endl;
    }
};*/
int main()
{

    // Composition
    std::cout << "Composition Example:\n";
    Car myCar("Ford", "V8"); // Car object contains an Engine object
    myCar.drive();

    std::cout << "\n";
    /*House myHouse(5, "Toyota", "V6");
    myHouse.displayHouseDetails();

    std::cout << "\nEnd of program:\n";*/
    return 0;
}
