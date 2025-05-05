class Base {
    public:
        int a;
    protected:
        int b;
    private:
        int c;
    };    
class Derived : protected Base {
    // a becomes protected
    // b remains protected
    // c is not accessible
};
