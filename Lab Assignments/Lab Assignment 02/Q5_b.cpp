#include <iostream>
using namespace std;

class TridiagonalMatrix {
private:
    int* mainDiagonal;
    int* superDiagonal;
    int* subDiagonal;
    int size;

public:
    TridiagonalMatrix(int n) : size(n) {
        mainDiagonal = new int[n];
        superDiagonal = new int[n - 1];
        subDiagonal = new int[n - 1];
        for (int i = 0; i < n; ++i) {
            mainDiagonal[i] = 0;
            if (i < n - 1) {
                superDiagonal[i] = 0;
                subDiagonal[i] = 0;
            }
        }
    }

    ~TridiagonalMatrix() {
        delete[] mainDiagonal;
        delete[] superDiagonal;
        delete[] subDiagonal;
    }

    void set(int i, int j, int value) {
        int diff = i - j;
        if (diff == 0) {
            mainDiagonal[i] = value;
        } else if (diff == 1) {
            superDiagonal[i - 1] = value;
        } else if (diff == -1) {
            subDiagonal[i] = value;
        } else {
            cerr << "Only tridiagonal elements can be set." << endl;
        }
    }

    int get(int i, int j) const {
        int diff = i - j;
        if (diff == 0) {
            return mainDiagonal[i];
        } else if (diff == 1) {
            return superDiagonal[i - 1];
        } else if (diff == -1) {
            return subDiagonal[i];
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
    TridiagonalMatrix matrix(size);

    matrix.set(0, 0, 5);
    matrix.set(1, 1, 7);
    matrix.set(2, 2, 9);
    matrix.set(1, 0, 2);
    matrix.set(0, 1, 3);
    matrix.set(2, 1, 4);
    matrix.set(1, 2, 6);
    matrix.set(3, 2, 8);
    matrix.set(2, 3, 1);

    cout << "Tridiagonal Matrix:" << endl;
    matrix.display();

    return 0;
}
