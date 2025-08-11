#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to perform an operation and return result
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero!");
            return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

// Function to evaluate an expression
double evaluate(const string& expression) {
    stack<double> values; // stack to store numbers
    stack<char> ops;      // stack to store operators

    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];

        // Skip spaces
        if (c == ' ') continue;

        // If the current token is a number
        if (isdigit(c) || c == '.') {
            double val = 0;
            int decimal_places = -1;
            bool isDecimal = false;

            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    isDecimal = true;
                } else {
                    if (!isDecimal) {
                        val = (val * 10) + (expression[i] - '0');
                    } else {
                        decimal_places++;
                        val += (expression[i] - '0') / pow(10, decimal_places);
                    }
                }
                i++;
            }
            i--;
            values.push(val);
        }

        // If '(' push it to ops
        else if (c == '(') {
            ops.push(c);
        }

        // If ')' solve the expression till '('
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty()) ops.pop(); // pop '('
        }

        // If operator
        else if (isOperator(c)) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                if (c == '^' && ops.top() == '^') break; // right-associative
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(c);
        }
    }

    // Apply remaining operators
    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    cout << "Mini Arithmetic Expression Evaluator\n";
    cout << "Enter an expression (use +, -, *, /, ^, and parentheses):\n";

    string expression;
    getline(cin, expression);

    try {
        double result = evaluate(expression);
        cout << "Result: " << result << endl;
    } catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
