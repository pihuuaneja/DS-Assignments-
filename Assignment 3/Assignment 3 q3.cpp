#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            return '\0'; 
        }
    }

    char peek() {
        if (!isEmpty()) 
		return arr[top];
        return '\0';
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(char expr[]) {
    Stack s;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false; 

            char top = s.pop();
            if (!isMatchingPair(top, ch)) return false;
        }
    }

    
    return s.isEmpty();
}

int main() {
    char expr[100];
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}

