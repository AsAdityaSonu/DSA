// Lower triangular matrix

#include<iostream>
using namespace std;

class Lower{
    private:
    int n[10][10];
    int size;
    public:
    void set( int size ){
        this->size = size;
        // Loop
        for(int i=0;i<(size);i++){
            for(int j=0;j<(size);j++){
                if(j<=i){
                    cout<<"Enter the element at index ("<<i<<","<<j<<") : ";
                    cin>>n[i][j];
                }
            }
        }

    }

    void get( ){
        cout<<"Matrix is :"<<endl;
        for(int i=0;i<(size);i++){
            for(int j=0;j<(size);j++){
                if(j<=i){
                    cout<<" "<<n[i][j];
                }else{
                    cout<<" "<<0;
                }
            }
            cout<<endl;
        }
    }

};

int main()
{
    int size;
    Lower a;

    //Matrix order
    cout<<"Matrix order: ";
    cin>>size;

    // Setting values
    a.set(size);

    // Getting values
    a.get();
    
    return 0;
}