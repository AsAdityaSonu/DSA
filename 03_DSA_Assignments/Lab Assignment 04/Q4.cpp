/*
Write a program to find first non-repeating character in a string using Queue.
Sample I/P: a a b c Sample O/P: a -1 b b 
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 10;

string nonRep(const string& input) {
    int count[MAX] = {0};
    queue<char> q;

    string result;

    for (char c : input) {
        count[c]++;
        q.push(c);

        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }
    }

    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    return result;
}

int main() {
    string a = "a a b c";
    string result = nonRep(a);
    cout << "Result: " << result << endl; // Output: "a -1 b b"

    return 0;
}
