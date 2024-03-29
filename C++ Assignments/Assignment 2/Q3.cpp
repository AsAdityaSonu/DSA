#include <iostream>
using namespace std;

// creating a class
class myClass{
  public: 
  static int var; 
};

// initiazing 
int myClass:: var = 5;

int main() 
{
    // creating two objects of myClass
    myClass obj1,obj2;
      
    cout<<"Value of var: "<<obj1.var<<endl;
    
    // chaning value of var by using obj2
    obj2.var = 7;
    
    cout<<"New value of var: "<<obj1.var<<endl;
    return 0;
}
