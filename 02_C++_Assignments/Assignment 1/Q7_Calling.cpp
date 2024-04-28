#include<iostream>
using namespace std;
class A{
	private:
		int a;
		int b;
		//set value of a
		void set_a(int a){
			this->a=a;
		}
		//set value of b
		void set_b(int b){
			this->b=b;
		}
	public:
		void getValues(int x,int y){
			set_a(x); //calling private member function
			set_b(y); //calling private member function
		}
		void putValues(){
			//printing values of private data members a,b
			cout<<"a="<<a<<",b="<<b<<endl;
		}
};





int main(){
    cout<<"___________________________________________________"<<endl;
    cout<<"Name:Aditya Pandey\t Roll No. 102217092\t Q7";
    cout<<endl<<"___________________________________________________"<<endl;
    
    A objA;
	
	//set values to class data members
	objA.getValues(100,200);
	//print values
	objA.putValues();

}