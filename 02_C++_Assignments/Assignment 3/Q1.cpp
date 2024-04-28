#include <iostream>
using namespace std;

class Rectangle {
    private:
        double length, breadth;

    public:
        Rectangle() {
            length = 0;
            breadth = 0;
        }

        Rectangle(double l, double b) {
            length = l;
            breadth = b;
        }

        Rectangle(double s) {
            length = s;
            breadth = s;
        }

        double area() {
            int a= (length * breadth);
            return a;
        }

        ~Rectangle(){
            cout;
        };
};

int main() {
    Rectangle r1;           // Object with no parameters
    Rectangle r2(4, 5);     // Object with two parameters
    Rectangle r3(6);        // Object with one parameter

    // Print the areas of the objects
    cout << "Area of r1: " << r1.area() << endl;
    cout << "Area of r2: " << r2.area() << endl;
    cout << "Area of r3: " << r3.area() << endl;

    return 0;
}
