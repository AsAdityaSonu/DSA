#include <iostream>  
#include <string.h>  
using namespace std;  
// create class of the Car  
class Car  
{  
private:  
int car_id;  
char car_name[20];  
int marks;  
  
public:  
// declare a static data member  
static int static_member;  
  
Car()  
{  
static_member++;  
}  
  
void inp()  
{  
cout << " \n\n Enter the Id of the Car: " << endl;  
cin >> car_id; // input the id  
cout << " Enter the name of the Car: " << endl;  
cin  >> car_name;  
cout << " Number of the Marks (1 - 10): " << endl;  
cin >> marks;    
}  
  
// display the entered details  
void disp ()  
{  
cout << " \n Id of the Car: " << car_id;  
cout << "\n Name of the Car: " << car_name;  
cout << " \n Marks: " << marks;  
  
}   
};  
  
// initialized the static data member to 0  
int Car::static_member = 0;  
  
 int main ()  
{  
// create object for the class Car  
Car c1;  
// call inp() function to insert values  
c1. inp ();  
c1. disp();  
  
//create another object  
Car c2;  
// call inp() function to insert values  
c2. inp ();  
c2. disp();  
  
  
 cout << " \n No. of objects created in the class: " << Car :: static_member <<endl;  
return 0;  
}  