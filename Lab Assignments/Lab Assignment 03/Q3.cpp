// Check if an expr has Balanced parentheses
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool B(string &expr)
{
    stack<char> s;

    for (char ch : expr)
    {
        cout<<ch;
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (s.empty())
            {
                return false;
            }

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{'))
            {
                return false;
            }
        }
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
