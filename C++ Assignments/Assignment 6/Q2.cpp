#include<iostream>
using namespace std;

class shape {
public:
    virtual void area() = 0;
    virtual void display() = 0;
};

class triangle : public shape {
    string name;
    int n, h;
    int a;
public:
    triangle(string name, int n, int h) {
        this->name = name;
        this->n = n;
        this->h = h;
    }
    void area() {
        a = 0.5 * n * h;
    }
    void display() {
        cout << name << endl;
        cout << a << endl;
    }
};

class rectangle : public shape {
    string name;
    int n, m;
    int a;
public:
    rectangle(string name, int n, int m) {
        this->name = name;
        this->n = n;
        this->m = m;
    }
    void area() {
        a = n * m;
    }
    void display() {
        cout << name << endl;
        cout << a << endl;
    }
};

class circle : public shape {
    string name;
    int r;
    int a;
public:
    circle(string name, int r) {
        this->name = name;
        this->r = r;
    }
    void area() {
        a = 3.14 * r * r;
    }
    void display() {
        cout << name << endl;
        cout << a << endl;
    }
};

int main() {
    circle c("circle", 5);
    c.area();
    c.display();

    rectangle r("rectangle", 6, 8);
    r.area();
    r.display();

    triangle t("Triangle", 7, 8);
    t.area();
    t.display();

    return 0;
}