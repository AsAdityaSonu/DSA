// delete all the vowels from a string

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void rem(string &a) {
    string result = "";
    for (int i = 0; i < a.length(); i++) {
        if (!isVowel(a[i])) {
            result += a[i];
        }
    }
    a = result;
}

int main() {
    string a;
    cout << "Enter any sentence: ";
    // cin >> a;
    getline(cin, a);

    rem(a);

    cout << "String after removing vowels: " << a << endl;

    return 0;
}
