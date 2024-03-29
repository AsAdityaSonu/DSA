#include <iostream>
#include <cmath>

using namespace std;

double area(double a) {
    //area of an equilateral triangle
    return sqrt(3) / 4 * a * a;
}

double area(double a, double b) {
    if (a == b) {
        //area of an isosceles triangle
        return 0.5 * a * sqrt(b*b - (a*a/4));
    }
    else {
        //area of a scalene triangle
        double s = (a + b + sqrt(a*a + b*b))/2;
        return sqrt(s * (s-a) * (s-b) * (s-sqrt(a*a + b*b)));
    }
}

int main() {
    double a, b;

    // Equilateral triangle
    cout << "Enter the length of side of equilateral triangle: ";
    cin >> a;
    cout << "Area of equilateral triangle: " << area(a) << endl;

    // Isosceles triangle
    cout << "Enter the lengths of equal sides of isosceles triangle: ";
    cin >> a;
    b = a;
    cout << "Area of isosceles triangle: " << area(a, b) << endl;

    // Scalene triangle
    cout << "Enter the lengths of two sides of scalene triangle: ";
    cin >> a >> b;
    cout << "Area of scalene triangle: " << area(a, b) << endl;

    return 0;
}