#include<iostream>
using namespace std;
namespace ns1 { int value() {return 5;}} 
namespace ns2 { int value() {return -5;}} 


namespace first_space
{
  void func()
  {
     cout << "Inside first_space" << endl;
  }
}
 
// second name space
namespace second_space
{
  void func()
  {
     cout << "Inside second_space" << endl;
  }
}
using namespace first_space;

int main(){
    cout<<"___________________________________________________"<<endl;
    cout<<"Name:Aditya Pandey\t Roll No. 102217092\t Q4";
    cout<<endl<<"___________________________________________________"<<endl;
    func();
    cout <<endl<< ns1::value() << '\n';  //5 will be displayed
    cout <<endl<< ns2::value() << '\n';     // -5 will be displayed

    return 0;
}




