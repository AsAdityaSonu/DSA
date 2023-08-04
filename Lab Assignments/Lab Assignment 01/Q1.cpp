/* Develop a Menu driven program to demonstrate the following operations of Arrays 
-——MENU——-
1.CREATE
2. DISPLAY
3. INSERT
4. DELETE
5. LINEAR SEARCH
6. EXIT
*/
// --------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num = 0;
    int opt;
    vector<int> arr;

    while (true) {
        cout << "----------------------------------------------------------------\n";
        cout << "Choose any of the following options:\n";
        cout<<"(Please create an array first)" << endl;
        cout << "----------------------------------------------------------------\n";
        cout << "1. Create\n2. Display\n3. Insert\n4. Delete\n5. LINEAR SEARCH\n6. Exit\n";
        
        cin >> opt;

        switch (opt) {
            case 1:
                cout << "Enter the number of items:" << endl;
                cin >> num;
                arr.resize(num); // Resize the vector
                cout << "Enter " << num << " items" << endl;
                for (int x = 0; x < num; x++) {
                    cin >> arr[x];
                }
                break;

            case 2:
                for (int x = 0; x < num; x++) {
                    cout << arr[x] << endl;
                }
                break;

            case 3:
                // insert 
                int pos,ele;
                cout<<"Enter the position at which you want to insert"<<endl;
                cin>>pos;
                cout<<"Enter the the element you want to insert"<<endl;
                cin>>ele;
                
                break;

            case 4:
                // delete 
                

            case 5:
                // linear search
                break;

            case 6:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "ERROR: Unknown option" << endl;
                break;
        }
    }

    return 0;
}
