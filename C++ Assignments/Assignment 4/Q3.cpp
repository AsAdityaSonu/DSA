#include <iostream>

class Fruit {
protected:
    int num_fruits;

public:
    Fruit() {
        num_fruits = 0;
    }

    int count() {
        return num_fruits;
    }
};

class Apple : public Fruit {
private:
    int num_apples;

public:
    Apple() {
        num_apples = 0;
    }

    void add(int n) {
        num_fruits += n;
        num_apples += n;
    }

    int count() {
        return num_apples;
    }
};

class Mango : public Fruit {
private:
    int num_mangoes;

public:
    Mango() {
        num_mangoes = 0;
    }

    void add(int n) {
        num_fruits += n;
        num_mangoes += n;
    }

    int count() {
        return num_mangoes;
    }
};

int main() {
    Apple apples;
    apples.add(5);

    Mango mangoes;
    mangoes.add(3);

    int total_fruits = apples.count() + mangoes.count();

    std::cout << "Number of apples: " << apples.count() << std::endl;
    std::cout << "Number of mangoes: " << mangoes.count() << std::endl;
    std::cout << "Total number of fruits: " << total_fruits << std::endl;

    return 0;
}