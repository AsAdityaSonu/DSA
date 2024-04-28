#include<iostream>
using namespace std;
class student
{
    private:
        char  name[30];
        int   rollNo;
        char   degree[20];
        char hostel[10];
        float gpa;
        char details[50];

        void assign_Info1(){
            cout<< "Enter your Name:"<<endl;
            cin>> name;
            cout<< "Enter your roll NO:"<<endl;
            cin >> rollNo;
            cout<< "Enter the name of degree you are persuing currently:"<<endl;
            cin>> degree;
            cout<< "Enter the name of hostel you are livin in:"<<endl;
            cin >> hostel;
            cout<< "Enter your current CGPA"<<endl;
            cin>> gpa;
        }

        void display_details1(){
            cout<<"Name: "<< name<< endl;
            cout<<"Roll No.: " << rollNo<< endl;
            cout<<"Degree: "<< degree<< endl;
            cout<<"Hostel: " << hostel<< endl;
            cout<<"CGPA: "<< gpa<< endl;
            if(details!=NULL){
                puts(details);
            }
        }

        void assign_details1(){
            cout<<"Please enter details you wants to add:"<<endl;
            cin>> details;
        }

        void update_cgpa1(){
            cout<<"Please enter your new CGPA:"<<endl;
            cin>> gpa;
        }
        
        void update_residance1(){
            cout<<"Please enter your new resisdance:"<<endl;
            cin>> hostel;
        }
    public:

        //Calling Functions in Public
        void assign_Info(){
            assign_Info1();
        }
        void display_details(){
            display_details1();
        }

        void assign_details(){
            assign_details1();
        }

        void update_cgpa(){
            update_cgpa1();
        }
        
        void update_residance(){
            update_cgpa1();
        }

        
};
int main(){
    cout<<"___________________________________________________"<<endl;
    cout<<"Name:Aditya Pandey\t Roll No. 102217092\t Q6";
    cout<<endl<<"___________________________________________________"<<endl;

    int n;
    student p;
    p.assign_Info();
    cout<<"Enter action you wants to perform:"<<endl;
    cout<<"1. Display data\n2. Add Details\n3. Update CGPA\n4. Update residance Information\n5. Update Details "<<endl;
    cin>>n;
    if (n==1)
    {
        /* code */
        p.display_details();
    }else if (n==2)
    {
        /* code */
        p.assign_details();
        p.display_details();
    }else if (n==3){
        p.update_cgpa();
        p.display_details();
    }else if (n==4){
        p.update_residance();
        p.display_details();
    }else if (n==5)
    {
        p.assign_Info();
        p.display_details();
    }
    return 0;
    
}