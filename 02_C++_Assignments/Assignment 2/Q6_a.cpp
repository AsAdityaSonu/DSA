#include <iostream>
class Rectangle { private:
int length;
int width; public:
Rectangle(int l, int w) { length = l;
width = w;
}
int getArea(); };
int Rectangle::getArea() { return length * width;
}
int main() {
Rectangle rect(3, 4);
std::cout << "Rectangle area: " << rect.getArea() << std::endl; return 0;
}