#include<iostream>
using namespace std;

int main()
{
    int n;
    while(true){
        cout << "------------------------------------------------------------------\n";
        cout<<"1. Insert (begnning)\t2. Insertion (end)\t3. Insertion in between\n4. Deletion (beginning)\t5. Deletion (end)\t6. Deletion (specific node)\n7. Search (node) and display its position from head\n8. Display all the node values\t9. Exit"<<endl;
        cout << "------------------------------------------------------------------\n";
        cout<<"Please select any option from above: ";
        cin>>n;
        cout << "------------------------------------------------------------------\n";

        switch (n)
        {
        // Insert at the begnning
        case 1:
            break;
        
        // Insertion at the end
        case 2:
            break;

        // Insertion in between
        case 3:
            break;

        // Deletion from the beginning
        case 4:
            break;

        // Deletion from the end
        case 5:
            break;
        
        // Deletion of a specific node
        case 6:
            break;
        
        // Search for a node and display its position from head
        case 7:
            break;
        
        // Display all the node values
        case 8:
            break;
        
        case 9:
            cout<<"Exiting..."<<endl;
            return 0;
            break;
        default:
            cout<<"Please select right option :)"<<endl;
            break;
        }
    }
    return 0;
}