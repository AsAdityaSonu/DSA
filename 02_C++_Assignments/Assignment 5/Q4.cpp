#include <iostream>
#include <string>

using namespace std;

// Abstract base class
class Student {
public:
    virtual void display() = 0; // Pure virtual fun
protected:
    string name;
    int rollNo;
};

// Derived class Science
class Science : public Student {
public:
    Science(string n, int r) {
        name = n;
        rollNo = r;
    }
    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Stream: Science" << endl;
    }
};

// Derived class Art
class Art : public Student {
public:
    Art(string n, int r) {
        name = n;
        rollNo = r;
    }
    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Stream: Art" << endl;
    }
};

// Derived class Commerce
class Commerce : public Student {
public:
    Commerce(string n, int r) {
        name = n;
        rollNo = r;
    }
    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Stream: Commerce" << endl;
    }
};

int main() {
    Student* students[3]; // Array of pointers

    students[0] = new Science("Aditya", 76);
    students[1] = new Art("Sonu", 97);
    students[2] = new Commerce("Aswiz", 98);

    for (int i = 0; i < 3; i++) {
        students[i]->display();
    }

    for (int i = 0; i < 3; i++) {
        delete students[i];
    }

    return 0;
}
