#include <iostream>

using namespace std;

class Time
{
    int h,m,s;
    public:
    Time()
    {
        h=0, m=0; s=0;
    }
    void setTime();
    void show()
    {
        cout<< h<< ":"<< m<< ":"<< s;
    }
    
    Time operator+(Time t1);   
};

Time Time::operator+(Time t1)	//operator function
{
    Time t;
    t.s = (s + t1.s) % 60;
    t.m = (((s + t1.s) / 60) + m + t1.m) % 60;
    t.h = ((((s + t1.s) / 60) + m + t1.m) / 60) + h + t1.h;
    t.h = t.h % 12;
    return t;
}

void Time::setTime()
{
    cout << "\n Enter the hour(0-11) ";
    cin >> h;
    cout << "\n Enter the minute(0-59) ";
    cin >> m;
    cout << "\n Enter the second(0-59) ";
    cin >> s;
}

int main()
{
    Time t1,t2,t3;
 
    cout << "\n Enter the first time ";
    t1.setTime();
    cout << "\n Enter the second time ";
    t2.setTime();
    t3 = t1 + t2;	
    cout << "\n First time ";
    t1.show();
    cout << "\n Second time ";
    t2.show();
    cout << "\n Sum of times ";
    t3.show();
    cin.get();
    return 0;
}
