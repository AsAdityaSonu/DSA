#include <iostream>
class Rectangle { 
    private:
        int length;
        int width;
    public:
    Rectangle(int l, int w) { 
        length = l;
        width = w;
}
int getArea() {

return length * width; 

}
};

int main() {

Rectangle rectangles[3] = { 
    Rectangle(3, 4), Rectangle(5, 6),Rectangle(7, 8) 
    };

for (int i = 0; i < 3; i++) {

std::cout << "Rectangle " << i+1 << " area: " << rectangles[i].getArea() << std::endl;

}
return 0; }