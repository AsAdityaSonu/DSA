#include <iostream>
using namespace std;

class Tri {
private:
    int** n;
    int size;

public:
    Tri(int size) {
        this->size = size;
        n = new int*[size];
        for (int i = 0; i < size; ++i) {
            n[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                n[i][j] = 0; 
            }
        }
    }

    ~Tri() {
        for (int i = 0; i < size; ++i) {
            delete[] n[i];
        }
        delete[] n;
    }

    void set() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (j == i || i == j + 1 || j == i + 1) {
                    cout << "Enter the element at index (" << i << "," << j << ") : ";
                    cin >> n[i][j];
                }
            }
        }
    }

    void get() {
        cout << "Matrix is :" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (j == i || i == j + 1 || j == i + 1) {
                    cout << " " << n[i][j];
                } else {
                    cout << " " << 0;
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int size;

    // Matrix order
    cout << "Matrix order: ";
    cin >> size;

    Tri a(size);

    // Setting values
    a.set();

    // Getting values
    a.get();

    return 0;
}
