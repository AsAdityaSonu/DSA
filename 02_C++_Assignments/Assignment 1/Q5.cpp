#include<iostream>
using namespace std;
struct student
{
   
        char  name[30];
        int   rollNo;
        char   degree[20];
        char hostel[10];
        float gpa;
        char details[50];

        void assign_Info(){
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
        void display_details(){
            cout<<"Name: "<< name<< endl;
            cout<<"Roll No.: " << rollNo<< endl;
            cout<<"Degree: "<< degree<< endl;
            cout<<"Hostel: " << hostel<< endl;
            cout<<"CGPA: "<< gpa<< endl;
            if(details!=NULL){
                puts(details);
            }
        }

        void assign_details(){
            cout<<"Please enter details you wants to add:"<<endl;
            cin>> details;
        }

        void update_cgpa(){
            cout<<"Please enter your new CGPA:"<<endl;
            cin>> gpa;
        }
        
        void update_residance(){
            cout<<"Please enter your new resisdance:"<<endl;
            cin>> hostel;
        }

        
};
int main(){
    cout<<"___________________________________________________"<<endl;
    cout<<"Name:Aditya Pandey\t Roll No. 102217092\t Q5";
    cout<<endl<<"___________________________________________________"<<endl;

    int n;
    student p;
    p.assign_Info();
    cout<<"Enter action you wants to perform:"<<endl;
    cout<<"1. Display data\n2. Add Details\n3. Update CGPA\n4. Update residance Information\n5. Update Information "<<endl;
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