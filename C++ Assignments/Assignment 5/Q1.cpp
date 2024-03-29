#include<iostream>
using namespace std;

class Alpha{
    public:
    Alpha(){
        cout<<"I am Alpha\n";
    }
    ~Alpha(){
        cout<<"I am Alpha's Destructor\n";
    }
};
class Beta{
    public:
    Beta(){
        cout<<"I am Beta\n";
    }
    ~Beta(){
        cout<<"I am Beta's Destructor\n";    
    }
};
class Gamma:public Alpha,public Beta{
    public:
    Gamma(){
        cout<<"I am Gamma\n";
    }
    ~Gamma(){
        cout<<"I am Gamma's Destructor\n";
    }
};
int main()
{
    Gamma g;
    return 0;
}