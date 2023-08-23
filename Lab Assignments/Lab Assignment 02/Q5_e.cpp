#include <iostream>
using namespace std;

class Sym {
private:
    int** n;
    int size;

public:
    Sym(int size) {
        this->size = size;
        n = new int*[size];
        for (int i = 0; i < size; ++i) {
            n[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                n[i][j] = 0; 
            }
        }
    }

    ~Sym() {
        for (int i = 0; i < size; ++i) {
            delete[] n[i];
        }
        delete[] n;
    }

    void set() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (j >= i) {
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
                if (j >= i) {
                    cout << " " << n[i][j];
                } else {
                    cout << " " << n[j][i]; 
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

    Sym a(size);

    // Setting values
    a.set();

    // Getting values
    a.get();

    return 0;
}
