#include <iostream>
using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool higherP(char op1, char op2) {
    int prec1, prec2;
    if (op1 == '+' || op1 == '-') {
        prec1 = 1;
    } else {
        prec1 = 2;
    }

    if (op2 == '+' || op2 == '-') {
        prec2 = 1;
    } else {
        prec2 = 2;
    }

    return prec1 >= prec2;
}

string i2Postfix(const string& infix) {
    string postfix = "";
    char stack[100];
    int top = -1;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix += stack[top--];
            }
            top--; // Pop '('
        } else if (isOperator(ch)) {
            while (top >= 0 && stack[top] != '(' && higherP(stack[top], ch)) {
                postfix += stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top >= 0) {
        postfix += stack[top--];
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string exp = i2Postfix(infix);
    cout << "Postfix expression: " << exp << endl;

    return 0;
}
