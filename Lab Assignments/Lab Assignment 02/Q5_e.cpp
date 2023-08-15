#include <iostream>
using namespace std;

class Sys
{
private:
    int *elements;
    int size;

public:
    Sys(int n) : size(n)
    {
        elements = new int[n * (n + 1) / 2];
    }

    ~Sys()
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
    Sys m(size);

    m.set(0, 0, 5);
    m.set(1, 0, 3);
    m.set(1, 1, 7);
    m.set(2, 0, 2);
    m.set(2, 1, 1);
    m.set(2, 2, 9);
    m.set(3, 0, 8);
    m.set(3, 1, 6);
    m.set(3, 2, 4);
    m.set(3, 3, 2);

    cout << "Matrix is :" << endl;
    m.display();

    return 0;
}
