#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(int x) { if (!isFull()) arr[++top] = x; }
    int pop() { return (!isEmpty()) ? arr[top--] : -1; }
    int peek() { return (!isEmpty()) ? arr[top] : -1; }
};


void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

bool canTransform(int A[], int N) {
    int target[MAX];
    for (int i = 0; i < N; i++) target[i] = A[i];
    sortArray(target, N);  

    Stack s;
    int i = 0, j = 0;  

    while (i < N || !s.isEmpty()) {
        if (!s.isEmpty() && s.peek() == target[j]) {
            s.pop();
            j++;
        } 
        else if (i < N) {
            s.push(A[i]);
            i++;
        } 
        else {
            return false;  
        }
    }
    return (j == N);
}

int main() {
    int N;
    cout << "Enter size of array: ";
    cin >> N;

    int A[MAX];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < N; i++) cin >> A[i];

    if (canTransform(A, N))
        cout << "Yes, possible to make B sorted." << endl;
    else
        cout << "No, not possible." << endl;

    return 0;
}

