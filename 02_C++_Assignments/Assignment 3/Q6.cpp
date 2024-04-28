#include <iostream>
using namespace std;

// Forward declaration of class B
class ClassB;

// Class A declaration
class ClassA {
private:
    int a;

public:
    ClassA() {
        a = 0;
    }

    void setValue(int value) {
        a = value;
    }

    void display() {
        cout << "Value of ClassA = " << a << endl;
    }

    friend void addValues(ClassA, ClassB);
};

// Class B declaration
class ClassB {
private:
    int b;

public:
    ClassB() {
        b = 0;
    }

    void setValue(int value) {
        b = value;
    }

    void display() {
        cout << "Value of ClassB = " << b << endl;
    }

    friend void addValues(ClassA, ClassB);
};

// Friend function to add values of two classes
void addValues(ClassA objA, ClassB objB) {
    int sum = objA.a + objB.b;
    cout << "Sum of ClassA and ClassB = " << sum << endl;
}

int main() {
    // Create objects of ClassA and ClassB
    ClassA objA;
    ClassB objB;

    // Set values of objects
    objA.setValue(5);
    objB.setValue(10);

    // Display values of objects
    objA.display();
    objB.display();

    // Add values of objects using friend function
    addValues(objA, objB);

    return 0;
}
