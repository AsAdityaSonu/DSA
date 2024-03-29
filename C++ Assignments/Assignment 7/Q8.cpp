#include <iostream>
using namespace std;

class MyFloat {
private:
    float value;
public:
    MyFloat(float v) : value(v) {}
    operator float() const { return value; }
};

int main() {
    MyFloat mf(3.14);
    float f = mf;
    cout << "MyFloat value: " << mf << endl;
    cout << "Float value: " << f << endl;
    return 0;
}
