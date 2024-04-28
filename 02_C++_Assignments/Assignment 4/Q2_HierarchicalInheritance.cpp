#include <iostream>
using namespace std;

class Number {
    protected:
        int num;
    public:
        void getNum() {
            cout << "Enter a number: ";
            cin >> num;
        }
};

class Square : public Number {
    public:
        void getSquare() {
            cout << "Square of " << num << " is: " << num*num << endl;
        }
};

class Cube : public Number {
    public:
        void getCube() {
            cout << "Cube of " << num << " is: " << num*num*num << endl;
        }
};

int main() {
    Square s;
    Cube c;
    s.getNum();
    s.getSquare();
    c.getNum();
    c.getCube();
    return 0;
}