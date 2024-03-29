#include<iostream>
using namespace std;

class Polygon{
    protected:
    int width, height;
    public:
    void set_value(int w, int h){
        width=w;
        height =h;
    }
};

class Rectangle : public Polygon{
    public:
    int calculate_area(){
        return width*height;
    }
};

class RightAngledTriangle : public Polygon{
    public:
    int calculate_area(){
        return width*height*0.5;
    }
};

int main()
{
    Polygon *s;
    Rectangle r;
    RightAngledTriangle t;

    s=&r;
    s->set_value(5,6);
    cout<<"Area of Rectangle: "<<r.calculate_area()<<endl;

    s=&t;
    s->set_value(8,9);
    cout<<"Area of Right Angled Triangle:"<<t.calculate_area()<<endl;
    
    return 0;
}