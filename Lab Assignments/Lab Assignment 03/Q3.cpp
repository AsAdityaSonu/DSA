// Check if an expr has Balanced parentheses
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool B(string &expr)
{
    stack<char> s;
    stack<char> p;
    stack<char> rev;

    for (char ch : expr)
    {
        cout<<ch;
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            p.push(ch);
        }
    }
    
    char q;

    for(int i=0;i<p.size();i++){
        q = p.pop();
        rev.push(q);
    }


    // cout<<s.empty();
    return s.empty();
}

int main()
{
    string expr;
    cout << "Enter an expr: ";
    cin >> expr;

    if (B(expr))
    {
        cout << "Balanced.\n";
    }
    else
    {
        cout << "not Balanced.\n";
    }

    return 0;
}
