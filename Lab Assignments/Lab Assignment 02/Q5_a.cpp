// Diagonal Matrix

#include <iostream>
using namespace std;

class DiagonalMatrix {
private:
    int* diagonalElements;
    int size;

public:
    DiagonalMatrix(int n) : size(n) {
        diagonalElements = new int[n];
        for (int i = 0; i < n; ++i) {
            diagonalElements[i] = 0;
        }
    }

    ~DiagonalMatrix() {
        delete[] diagonalElements;
    }

    void set(int i, int j, int value) {
        if (i != j) {
            cout << "Only diagonal elements can be set." << endl;
            return;
        }
        diagonalElements[i] = value;
    }

    int get(int i, int j) const {
        if (i == j) {
            return diagonalElements[i];
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
    DiagonalMatrix matrix(size);

    matrix.set(0, 0, 5);
    matrix.set(1, 1, 7);
    matrix.set(2, 2, 9);

    cout << "Diagonal Matrix:" << endl;
    matrix.display();

    return 0;
}
