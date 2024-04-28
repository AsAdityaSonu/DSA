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

class Derived : protected Base {
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
    // d.publicVar=5;
    // d.protectedVar=8;
    return 0;
}