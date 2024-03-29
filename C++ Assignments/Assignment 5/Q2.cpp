#include <iostream>
#include <cstring>

using namespace std;

class X {
public:
    X() {
        strX[0] = '\0'; 
    }
    X(const char* s) {
        strcpy(strX, s);
    }
    virtual ~X() {} // virtual destructor 
    char strX[100];
};

class Y {
public:
    Y() {
        strY[0] = '\0';
    }
    Y(const char* s) {
        strcpy(strY, s);
    }
    virtual ~Y() {}
    char strY[100];
};

class Z : public X, public Y {
public:
    Z() {
        strZ[0] = '\0';
    }
    Z(const char* x, const char* y) : X(x), Y(y) {
        strcpy(strZ, strX);
        strcat(strZ, strY);
    }
    ~Z() {}
    char strZ[200];
};

int main() {
    Z z("Hello, ", "world!");
    cout << "String X: " << z.strX << endl;
    cout << "String Y: " << z.strY << endl;
    cout << "String Z: " << z.strZ << endl;
    return 0;
}
