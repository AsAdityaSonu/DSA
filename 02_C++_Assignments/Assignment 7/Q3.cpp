#include <iostream>
#include <iomanip>
using namespace std;
class Matrix
{
    private:
        int m[2][2],i,j;
    public:
        void read()
        {
            for(i=0;i<2;i++)
               for(j=0;j<2;j++)
                    cin>>m[i][j];
        }
        void display()
        {
            for(i=0;i<2;i++)
            {
                for(j=0;j<2;j++)
                    cout<<m[i][j]<<setw(2);
                cout<<endl;
            }
        }
        friend Matrix operator*(Matrix a,Matrix b)
        {
            int i,j,k,sum=0;
            Matrix c;
            for(i=0;i<2;i++)
            {
                for(j=0;j<2;j++)
               {
                    for(k=0;k<2;k++)
                    {

                        sum=sum+a.m[i][k]*b.m[k][j];
                    }
                    c.m[i][j]=sum;
                    sum=0;
                }
            }
            return c;
        }
};
int main()
{
    Matrix a,b,c;
    cout<<"Enter 1st matrix:"<<endl;
    a.read();
    cout<<"Enter 2nd matrix:"<<endl;
    b.read();
    c=a*b; //same as operator*(a,b);
    cout<<"The product is:"<<endl;
    c.display();
    return 0;
}