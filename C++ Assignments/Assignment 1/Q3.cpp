#include<iostream>
using namespace std;
int main(){
    cout<<"___________________________________________________"<<endl;
    cout<<"Name:Aditya Pandey\t Roll No. 102217092\t Q3";
    cout<<endl<<"___________________________________________________"<<endl;
    
        //For loop
        cout <<"For Loop"<<endl;{
        cout<<endl<<"___________________________________________________"<<endl;
        cout<<"1. with initialization and increment"<<endl;
        for (int i = 1; i <= 5; ++i) {
        cout << i << " ";
        }

        cout<<endl<<"2. with out initialization"<<endl;
        int j=0;
        for (int ; j <= 5; ++j) {
        cout << j << " ";
        }

        cout<<endl<< "3. without initialization and increment"<<endl;
        int k=0;
        for (; k <= 5;)
        {
            /* code */
            cout<< k<<" ";
            k++;
        }
        }


        
        cout <<endl<<"While Loop"<<endl;{
            cout<<endl<<"___________________________________________________"<<endl;
            cout<<endl<<"1."<<endl;
            int a=0;
            while(a<10){
                cout <<endl<<a<<endl;
                a++;
            }

            cout<<endl<<"___________________________________________________"<<endl;
            cout<<endl<<"2."<<endl;
            int q=10;
            while(q) {    //here we are checking if n is non-zero
            cout << q << endl;
            q--;    //decrementing n
            }
        }

        cout <<endl<<"Do While Loop"<<endl;{
            cout<<endl<<"___________________________________________________"<<endl;
            cout<<endl<<"1."<<endl;
            int b=0;
            do
            {
                /* code */
                cout <<endl<<b<<endl;
                b++;
            } while (b<10);


            cout<<endl<<"___________________________________________________"<<endl;
            cout<<endl<<"2."<<endl;
            int z=10;
            do
            {
                /* code */
                cout << endl << z << endl;
                z--;
            } while (z);
            
        }
    return 0;
}