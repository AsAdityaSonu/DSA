#include <iostream>
using namespace std;
class complex{
    private:
        float real;
	    float img;
    public:
        void set(float x, float y){
            real=x;
            img=y;
        }
        void disp(){
            cout<<real<<" + j"<<img<<endl;
        }
        complex sum(complex c){
            complex complex_number;
	        complex_number.real = real + c.real;
	        complex_number.img = img + c.img;
	        return complex_number;
        }
};
int main()
{
    cout<<"___________________________________________________"<<endl;
    cout<<"Name:Aditya Pandey\t Roll No. 102217092\t Q8";
    cout<<endl<<"___________________________________________________"<<endl;

    complex comp1,comp2,comp3;
	comp1.set(4.5,8.9);
	comp2.set(7.3,5);
	comp3=comp1.sum(comp2);
	cout<<"\nComplex Number 1: ";
	comp1.disp();
	cout<<"\nComplex Number 2: ";
	comp2.disp();
	cout<<"\nComplex Number 3: ";
	comp3.disp();


    return 0;
}