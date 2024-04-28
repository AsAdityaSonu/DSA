// sort in alphabetical order

#include <iostream>
#include <string>
using namespace std;

void sort(string &a) {      //Bubble Sorting
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < a.length() - i - 1; j++) {
            if ((int)a[j] > (int)a[j + 1]) { 
                char temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << a<< endl;
}

int main() {
    string a;
    getline(cin, a);

    sort(a);

    return 0;
}
