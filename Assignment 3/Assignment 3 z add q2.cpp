#include <iostream>
using namespace std;
#define SIZE 100

class SpecialStack {
    int mainStack[SIZE];
    int minStack[SIZE];
    int topMain, topMin;
    
public:
    SpecialStack() {
        topMain = -1;
        topMin = -1;
    }
    void push(int x) {
        if(topMain == SIZE - 1) return; // Overflow check
        mainStack[++topMain] = x;
        if(topMin == -1 || x <= minStack[topMin])
            minStack[++topMin] = x;
        else
            minStack[++topMin] = minStack[topMin-1];
    }
    void pop() {
        if (topMain == -1) return; // Underflow check
        topMain--;
        topMin--;
    }
    int peek() {
        if(topMain == -1) return -1;
        return mainStack[topMain];
    }
    int getMin() {
        if(topMin == -1) return -1;
        return minStack[topMin];
    }
    bool empty() {
        return topMain == -1;
    }
};

int main() {
    SpecialStack s;
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);
    cout << "Current Min: " << s.getMin() << endl; // 1
    s.pop();
    cout << "Current Min: " << s.getMin() << endl; // 2
    s.pop();
    cout << "Top Element: " << s.peek() << endl;   // 2
    cout << "Current Min: " << s.getMin() << endl; // 2
    return 0;
}

