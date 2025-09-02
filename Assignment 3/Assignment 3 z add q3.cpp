#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    int peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

void nextGreaterElement(int arr[], int n) {
    Stack s;
    int result[100];

    for (int i = 0; i < n; i++) result[i] = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.isEmpty() && s.peek() <= arr[i]) {
            s.pop();
        }

        if (!s.isEmpty()) {
            result[i] = s.peek();
        }

        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << result[i] << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = 4;
    nextGreaterElement(arr, n);
    return 0;
}

