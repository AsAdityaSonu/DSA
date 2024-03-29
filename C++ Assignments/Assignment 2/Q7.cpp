#include <iostream>
inline int cube(int x) { return x * x * x;
}
int main() {
int number = 5;
std::cout << "Cube of " << number << " is " << cube(number) << std::endl;
return 0; }