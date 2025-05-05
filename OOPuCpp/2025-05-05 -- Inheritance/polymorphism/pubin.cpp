
class Base {
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Derived : public Base {
    // a remains public
    // b remains protected
    // c is not accessible
};