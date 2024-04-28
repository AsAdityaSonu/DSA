#include <iostream>

using namespace std;

// Base class
class A {
public:
    int x;
};

// class B inherits from A
class B : virtual public A {
public:
    void setX(int i) {
        x = i;
    }
};

//class C inherits from A
class C : virtual public A {
public:
    void displayX() {
        cout << "x = " << x << endl;
    }
};

// Derived class D inherits from both B and C
class D : public B, public C {
public:
    void incrementX() {
        x++;
    }
};

int main() {
    D d;
    d.setX(876);
    d.displayX();
    d.incrementX();
    d.displayX();

    return 0;
}
