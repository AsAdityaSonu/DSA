#include<iostream>
using namespace std;

class Student{
    public:
    virtual void show()=0;
};

class Engineering : public Student{
    public:
    void show(){
        cout<<"Engineering Student"<<endl;
    }
};

class Medicine : public Student{
    public:
    void show(){
        cout<<"Medicine Student"<<endl;
    }
};

class Science : public Student{
    public:
    void show(){
        cout<<"Science Student"<<endl;
    }
};

int main()
{
    Student *s[10];
    Engineering e;
    Medicine m;
    Science sc;

    s[0]=&e;
    s[1]=&m;
    s[2]=&sc;

    for (int i=0; i<3;i++){
        s[i]->show();
    }
    
    return 0;
}