class Base {
    public:
        int a;
    protected:
        int b;
    private:
        int c;
    };    

class Derived : private Base {
    // a becomes private
    // b becomes private
    // c is not accessible
};
