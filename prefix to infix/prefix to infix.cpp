#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToInfix(string prefix) {
    stack<string> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string result = "(" + operand1 + prefix[i] + operand2 + ")";
            st.push(result);
        }
        else {
            string operand(1, prefix[i]);
            st.push(operand);
        }
    }

    return st.top();
}

int main() {
    string prefixExpression;
    cout << "Enter prefix expression: ";
    cin >> prefixExpression;

    string infixExpression = prefixToInfix(prefixExpression);
    cout << endl;
    cout << "Infix expression: " << infixExpression << endl;

    return 0;
}
