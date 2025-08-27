#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    int peek() { return arr[top]; }
};

void dailyTemperatures(int temp[], int n, int ans[]) {
    Stack s;

    
    for (int i = 0; i < n; i++) ans[i] = 0;

    for (int i = 0; i < n; i++) {
        
        while (!s.isEmpty() && temp[i] > temp[s.peek()]) {
            int prevIndex = s.pop();
            ans[prevIndex] = i - prevIndex; 
        }
        s.push(i); 
    }
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temp[MAX], ans[MAX];
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) cin >> temp[i];

    dailyTemperatures(temp, n, ans);

    cout << "Answer array: ";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

