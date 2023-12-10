#include <iostream>
using namespace std;

class Diag {
private:
    int** n;
    int size;

public:
    Diag(int size) {
        this->size = size;
        n = new int*[size];
        for (int i = 0; i < size; ++i) {
            n[i] = new int[size];
        }
    }

    ~Diag() {
        for (int i = 0; i < size; ++i) {
            delete[] n[i];
        }
        delete[] n;
    }

    void set() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == j) {
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
                if (i == j) {
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

    Diag a(size);

    // Setting values
    a.set();

    // Getting values
    a.get();

    return 0;
}
