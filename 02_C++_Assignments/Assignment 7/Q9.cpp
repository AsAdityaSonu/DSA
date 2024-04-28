#include<iostream>
#include<math.h>
using namespace std;
class polar
 {
 public: float r,th;
 polar(){}
 polar(int val1,int val2)
 { 
    r=val1;
    th=val2;
  } 

void show() {
       cout<<"Polar form : \nr="<<r<<" and θ = "<<th;
  }
 };
 class cartesian
    {
        float x,y;
        public:
            cartesian(){}
            cartesian(polar p)
            {
                x = p.r * cos(p.th);
                y = p.r * sin(p.th);
            }
            void show()
            {
                cout<<"\n\nIn Cartesian form : \nx="<<x<<" and y="<<y;
            }
    };
int main()
{
  polar p(5.5,3.14/2);
  p.show();
  cartesian c(p);
  c.show();
    return 0;
}