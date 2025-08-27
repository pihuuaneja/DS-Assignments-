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
        if (!isFull()) arr[++top] = c;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0'; 
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int j = 0;  

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        
        if ((ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z') || 
            (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        }
        
        else if (ch == '(') {
            s.push(ch);
        }
        
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop(); 
        }
        
        else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix[j++] = s.pop();
            }
            s.push(ch);
        }
    }

   
    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}

