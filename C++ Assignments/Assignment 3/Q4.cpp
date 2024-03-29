#include <iostream>
using namespace std;

class MyClass {
public:
    int value;

    // Constructor
    MyClass(int v) {
        value = v;
    }

    // Member function to print the value
    void printValue() {
        cout << "Value is " << value << endl;
    }

    // Member function to print the value using this pointer
    void printValueUsingThis() {
        cout << "Value is " << this->value << endl;
    }
};

int main() {
    MyClass obj1(10); // create object of MyClass
    MyClass* ptr = &obj1; // create pointer to obj1

    // Access object member using pointer and dot operator
    cout << "Value is " << ptr->value << endl;

    // Access object member using pointer and arrow operator
    cout << "Value is " << (*ptr).value << endl;

    // Call member function using object and dot operator
    obj1.printValue();

    // Call member function using this pointer and arrow operator
    obj1.printValueUsingThis();

    return 0;
}
