#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
	if (c == '#')
	{
		return 5;
	}
	else if (c == '^')
	{
		return 4;
	}
	else if (c == '/' || c == '*')
	{
		return 3;
	}
	else if (c == '+' || c == '-')
	{
		return 2;
	}
	else if (c == '$')
	{
		return 1;
	}
	else
		return -1;
}

// to postfix expression
void infixToPostfix(string s)
{

	stack<char> st;
	string result;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		else if (c == '(')
			st.push('(');

		else if (c == ')')
		{
			while (st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		else
		{
			while (!st.empty() && prec(s[i]) <= prec(st.top()))
			{
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

int main()
{
	string exp = "(A$B+C)#(K+L-M*N+0^13*W/U)";

	infixToPostfix(exp);

	return 0;
}
