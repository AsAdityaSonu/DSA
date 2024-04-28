#include <iostream>
using namespace std;

class Student
{
	private:
		int No;
		float percentage;
		//private member functions
		void TakeNumbersBegin(void)
		{
			cout<<"Input start..."<<endl;
		}
		void TakeNumber(void)
		{
			cout<<"Input end..."<<endl;
		}		
		
	public:
		//public member functions
		void read(void)
		{
			//calling first member function
			TakeNumber();
			//read rNo and percentage
			cout<<"Enter roll number: ";
			cin>>No;
			cout<<"Enter percentage: ";
			cin>>percentage;
			//calling second member function
			TakeNumber();				
		}		
		void print(void)
		{
			cout<<endl;
			cout<<"Roll No.: "<<No<<endl;
			cout<<"Percentage: "<<percentage<<"%"<<endl;
		}
};

//Main code
int main()
{
    cout<<"___________________________________________________"<<endl;
    cout<<"Name:Aditya Pandey\t Roll No. 102217092\t Q7";
    cout<<endl<<"___________________________________________________"<<endl;
	//declaring object of class student
	Student object;
	
	//reading and printing details of a student
	object.read();
	object.print();
	
	return 0;
}