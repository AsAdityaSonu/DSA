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

class Derived : private Base {
public:
    void foo() {
        publicVar = 1; // OK
        protectedVar = 2; // OK
        // privateVar = 3; // Error
    }
};

int main() {
    Derived d;
    // d.publicVar = 1; // Error
    // d.protectedVar = 2; // Error
    // d.privateVar = 3; // Error
    return 0;
}
