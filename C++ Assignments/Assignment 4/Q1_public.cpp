#include<iostream>
using namespace std;

class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class Derived : public Base {
public:
    void foo() {
        publicVar = 1; // OK
        protectedVar = 2; // OK
        // privateVar = 3; // Error: privateVar is not accessible
    }
};

int main()
{
    Derived d;
    d.publicVar=9;
    // d.protectedVar=0;
    return 0;
}