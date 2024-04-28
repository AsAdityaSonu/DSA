#include <iostream>
int globalVariable = 10;
void someFunction() {
int globalVariable = 20;
std::cout << "Local variable: " << globalVariable << std::endl; std::cout << "Global variable: " << ::globalVariable << std::endl;
}
int main() { someFunction(); return 0;
}