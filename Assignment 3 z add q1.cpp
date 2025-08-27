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

void nearestSmallerToLeft(int A[], int n) {
    Stack s;
    int result[100];

    for (int i = 0; i < n; i++) {
        while (!s.isEmpty() && s.peek() >= A[i]) {
            s.pop();
        }

        if (s.isEmpty()) {
            result[i] = -1;
        } else {
            result[i] = s.peek();
        }

        s.push(A[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << " -> " << result[i] << endl;
    }
}

int main() {
    int A[] = {1, 3, 0, 2, 5};
    int n = 5;
    nearestSmallerToLeft(A, n);
    return 0;
}

