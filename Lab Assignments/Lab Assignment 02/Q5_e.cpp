#include <iostream>
using namespace std;

class SymmetricMatrix
{
private:
    int *elements;
    int size;

public:
    SymmetricMatrix(int n) : size(n)
    {
        elements = new int[n * (n + 1) / 2]{};
    }

    ~SymmetricMatrix()
    {
        delete[] elements;
    }

    void set(int i, int j, int value)
    {
        if (i >= j)
        {
            int index = i * (i + 1) / 2 + j;
            elements[index] = value;
        }
    }

    int get(int i, int j) const
    {
        if (i >= j)
        {
            int index = i * (i + 1) / 2 + j;
            return elements[index];
        }
        return get(j, i);
    }

    void display() const
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int size = 4;
    SymmetricMatrix matrix(size);

    matrix.set(0, 0, 5);
    matrix.set(1, 0, 3);
    matrix.set(1, 1, 7);
    matrix.set(2, 0, 2);
    matrix.set(2, 1, 1);
    matrix.set(2, 2, 9);
    matrix.set(3, 0, 8);
    matrix.set(3, 1, 6);
    matrix.set(3, 2, 4);
    matrix.set(3, 3, 2);

    cout << "Symmetric Matrix:" << endl;
    matrix.display();

    return 0;
}
