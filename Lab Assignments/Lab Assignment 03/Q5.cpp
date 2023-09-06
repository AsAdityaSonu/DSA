#include <iostream>
using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int EvlExp(int oper1, int oper2, char op) {
    switch (op) {
        case '+':
            return oper1 + oper2;
        case '-':
            return oper1 - oper2;
        case '*':
            return oper1 * oper2;
        case '/':
            return oper1 / oper2;
    }
    return 0; 
}

int EvlPost(const string& postfix) {
    int stack[100];
    int top = -1;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack[++top] = ch - '0'; // Convert character to integer
        } else if (isOperator(ch)) {
            int oper2 = stack[top--];
            int oper1 = stack[top--];
            int result = EvlExp(oper1, oper2, ch);
            stack[++top] = result;
        }
    }

    return stack[top];
}

int main() {
    string Pexp="53*82/-";
    // cout << "Enter a postfix expression: ";
    // cin >> Pexp;

    int result = EvlPost(Pexp);
    cout << "Result: " << result << endl;

    return 0;
}
