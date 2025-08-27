#include <iostream>
#include <cmath>   
using namespace std;

#define MAX 100


class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack Underflow\n";
            return 0;
        }
    }
};


int evaluatePostfix(char exp[]) {
    Stack s;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

       
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');  
        }
       
        else {
            int operand2 = s.pop();  
            int operand1 = s.pop(); 

            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                case '^': s.push(pow(operand1, operand2)); break;
                default: cout << "Invalid operator: " << ch << endl;
            }
        }
    }

    return s.pop();  
}

int main() {
    char postfix[MAX];
    cout << "Enter postfix expression (use single-digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}

