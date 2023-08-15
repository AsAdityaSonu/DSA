#include <iostream>
using namespace std;

class Upper {
private:
    int* ele;
    int size;

public:
    Upper(int n) : size(n) {
        ele = new int[n * (n + 1) / 2]; 
    }

    ~Upper() {
        delete[] ele;
    }

    void set(int i, int j, int value) {
        if (i <= j) {
            int index = i * (size - i + 1) + (j - i); 
            ele[index] = value;
        }
    }

    int get(int i, int j) const {
        if (i <= j) {
            int index = i * (size - i + 1) + (j - i);
            return ele[index];
        }
        return 0;
    }

    void display() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size = 4;
    Upper m(size);

    m.set(0, 0, 5);
    m.set(0, 1, 3);
    m.set(0, 2, 2);
    m.set(0, 3, 8);
    m.set(1, 1, 7);
    m.set(1, 2, 1);
    m.set(1, 3, 6);
    m.set(2, 2, 9);
    m.set(2, 3, 4);
    m.set(3, 3, 2);

    cout << "matrix is :" << endl;
    m.display();

    return 0;
}
