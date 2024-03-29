#include <iostream>
using namespace std;

int main() {
    // Allocate memory for an integer using new keyword
    int *ptr = new int;
    
    // Check if memory allocation was successful
    if (ptr == NULL) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }
    
    // Set value of the integer
    *ptr = 5;
    
    // Print the value of the integer
    cout << "Value of integer = " << *ptr << endl;
    
    // Deallocate memory using delete keyword
    delete ptr;
    
    return 0;
}
