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
    bool found = false;

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
                    cout << arr[x] << "\t";
                }
                cout << endl;
                break;

            case 3:
                // insert 
                int pos,ele;
                arr.resize(num+1);
                cout<<"Enter the position at which you want to insert"<<endl;
                cin>>pos;
                cout<<"Enter the the element you want to insert"<<endl;
                cin>>ele;
                for(int x = num; x > 0; x--) {
                    arr[x] = arr[x-1];  //Because while creating array the loop is (x < num) so last element is left
                }
                arr[pos] = ele;
                num++;
                break;

            case 4:
                // delete 
                int p;
                cout << "Enter the position of the element you want to delete" << endl;
                cin >> p;

                if (p >= 0 && p < num) {
                    for (int i = p; i < num - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    num--;
                    cout << "Element at position " << p << " has been deleted." << endl;
                } else {
                    cout << "Invalid position. Deletion failed." << endl;
                }
                break;
                
            case 5:
                // linear search
                int find;
                cout << "Enter the element you want to find: " << endl;
                cin >> find;
                for (int i = 0; i < num; i++) {
                    if (arr[i] == find) {
                        cout << find << " is found at " << i << " position." << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << find << " is not found in this array." << endl;
                }
                break;

            case 6:
                cout << "Exiting..." << endl;
                return 0;
                break;

            default:
                cout << "ERROR: Unknown option" << endl;
                break;
        }
    }

    return 0;
}
