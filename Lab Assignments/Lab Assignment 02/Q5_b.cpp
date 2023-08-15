#include <iostream>
using namespace std;

class Tri {
private:
    int* mainD;
    int* superD;
    int* subD;
    int size;

public:
    Tri(int n) : size(n) {
        mainD = new int[n];
        superD = new int[n - 1];
        subD = new int[n - 1];
        for (int i = 0; i < n; ++i) {
            mainD[i] = 0;
            if (i < n - 1) {
                superD[i] = 0;
                subD[i] = 0;
            }
        }
    }

    ~Tri() {
        delete[] mainD;
        delete[] superD;
        delete[] subD;
    }

    void set(int i, int j, int value) {
        int diff = i - j;
        if (diff == 0) {
            mainD[i] = value;
        } else if (diff == 1) {
            superD[i - 1] = value;
        } else if (diff == -1) {
            subD[i] = value;
        } else {
            cerr << "Only tridiagonal elements can be set." << endl;
        }
    }

    int get(int i, int j) const {
        int diff = i - j;
        if (diff == 0) {
            return mainD[i];
        } else if (diff == 1) {
            return superD[i - 1];
        } else if (diff == -1) {
            return subD[i];
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
    int size = 5;
    Tri m(size);

    m.set(0, 0, 5);
    m.set(1, 1, 7);
    m.set(2, 2, 9);
    m.set(1, 0, 2);
    m.set(0, 1, 3);
    m.set(2, 1, 4);
    m.set(1, 2, 6);
    m.set(3, 2, 8);
    m.set(2, 3, 1);

    cout << "Tridiagonal Matrix:" << endl;
    m.display();

    return 0;
}
