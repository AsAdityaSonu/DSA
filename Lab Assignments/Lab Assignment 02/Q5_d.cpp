#include <iostream>
using namespace std;

class UpperTriangularMatrix {
private:
    int* elements;
    int size;

public:
    UpperTriangularMatrix(int n) : size(n) {
        elements = new int[n * (n + 1) / 2]{}; 
    }

    ~UpperTriangularMatrix() {
        delete[] elements;
    }

    void set(int i, int j, int value) {
        if (i <= j) {
            int index = i * (size - i + 1) + (j - i); 
            elements[index] = value;
        }
    }

    int get(int i, int j) const {
        if (i <= j) {
            int index = i * (size - i + 1) + (j - i);
            return elements[index];
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
    UpperTriangularMatrix matrix(size);

    matrix.set(0, 0, 5);
    matrix.set(0, 1, 3);
    matrix.set(0, 2, 2);
    matrix.set(0, 3, 8);
    matrix.set(1, 1, 7);
    matrix.set(1, 2, 1);
    matrix.set(1, 3, 6);
    matrix.set(2, 2, 9);
    matrix.set(2, 3, 4);
    matrix.set(3, 3, 2);

    cout << "Upper Triangular Matrix:" << endl;
    matrix.display();

    return 0;
}
