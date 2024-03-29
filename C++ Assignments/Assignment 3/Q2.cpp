#include <iostream>
using namespace std;

class Rectangle {
    private:
        double length, breadth;

    public:
        Rectangle() {
            length = 0;
            breadth = 0;
            cout << "Default constructor called" << endl;
        }

        Rectangle(double l, double b) {
            length = l;
            breadth = b;
            cout << "Parameterized constructor with 2 arguments called" << endl;
        }

        Rectangle(double s) {
            length = s;
            breadth = s;
            cout << "Parameterized constructor with 1 argument called" << endl;
        }

        double area() {
            return length * breadth;
        }

        ~Rectangle() {
            cout << "Destructor called" << endl;
        }
};

int main() {
    // Create an array of Rectangle objects
    Rectangle arr[3] = {Rectangle(), Rectangle(4, 5), Rectangle(6)};

    // Call the area() function for each object
    for(int i = 0; i < 3; i++) {
        cout << "Area of Rectangle " << i + 1 << ": " << arr[i].area() << endl;
    }

    return 0;
}
