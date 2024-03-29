#include <iostream>
using namespace std;

class MyFloat {
    private:
        float value;
    public:
        MyFloat(float v) {
            value = v;
        }
        float getValue() {
            return value;
        }
};


MyFloat float_to_myfloat(float num) {
    MyFloat obj(num);
    return obj;
}


int main() {
    float float_num = 3.14;
    MyFloat myfloat_obj = float_to_myfloat(float_num);
    cout << "Float number: " << float_num << endl;
    cout << "MyFloat object: " << myfloat_obj.getValue() << endl;

    return 0;
}
