#include <iostream>
class Counter { private:
static int count; public:
static void increment() { count++;
}
static int getCount() {
return count;
} };
int Counter::count = 0;
int main() {
Counter::increment();
Counter::increment();
std::cout << "Count: " << Counter::getCount() << std::endl; return 0;
}