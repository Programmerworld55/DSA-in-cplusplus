#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToPostfix(const string& prefix) {
    stack<string> stack;
    int length = prefix.size();

    for (int i = length - 1; i >= 0; --i) {
        if (isOperator(prefix[i])) {
            string operand1 = stack.top(); stack.pop();
            string operand2 = stack.top(); stack.pop();
            string expression = operand1 + operand2 + prefix[i];
            stack.push(expression);
        } else if (isalnum(prefix[i])) {
            stack.push(string(1, prefix[i]));  // Convert char to string
        }
    }

    return stack.top();
}

string postfixToPrefix(const string& postfix) {
    stack<string> stack;
    int length = postfix.size();

    for (int i = 0; i < length; ++i) {
        if (isOperator(postfix[i])) {
            string operand2 = stack.top(); stack.pop();
            string operand1 = stack.top(); stack.pop();
            string expression = string(1, postfix[i]) + operand1 + operand2;
            stack.push(expression);
        } else if (isalnum(postfix[i])) {
            stack.push(string(1, postfix[i]));  // Convert char to string
        }
    }

    return stack.top();
}

int main() {
    char choice;
    cout << "Enter 'P' for Prefix to Postfix conversion or 'S' for Postfix to Prefix conversion: ";
    cin >> choice;

    if (choice == 'P' || choice == 'p') {
        string prefixExpression;
        cout << "Enter a prefix expression: ";
        cin >> prefixExpression;
        string postfixExpression = prefixToPostfix(prefixExpression);
        cout << "Postfix expression: " << postfixExpression << endl;
    } else if (choice == 'S' || choice == 's') {
        string postfixExpression;
        cout << "Enter a postfix expression: ";
        cin >> postfixExpression;
        string prefixExpression = postfixToPrefix(postfixExpression);
        cout << "Prefix expression: " << prefixExpression << endl;
    } else {
        cout << "Invalid choice! Please enter 'P' or 'S'." << endl;
    }

    return 0;
}
