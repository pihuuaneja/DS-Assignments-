#include <iostream>
using namespace std;
#define SIZE 100

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }
    bool isEmpty() {
        return (rear < front);
    }
    bool isFull() {
        return (rear == SIZE - 1);
    }
    void enqueue(int x) {
        if (!isFull()) arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        return arr[front++];
    }
    int size() {
        return (isEmpty()) ? 0 : (rear - front + 1);
    }
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    void reset() {
        front = 0;
        rear = -1;
    }
};

class StackUsingQueues {
    Queue q1, q2;
public:
    void push(int x) {
        // Enqueue new element to q2
        q2.enqueue(x);

        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        // Swap q1 and q2 by copying arrays
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
        // Reset q2 for next operation
        q2.reset();
    }
    void pop() {
        if (!q1.isEmpty()) {
            q1.dequeue();
        }
    }
    int top() {
        return q1.peek();
    }
    bool empty() {
        return q1.isEmpty();
    }
};

int main() {
    StackUsingQueues s;
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);
    cout << "Top element: " << s.top() << endl;  // 1
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;  // 8
    s.pop();
    cout << "Top element after another pop: " << s.top() << endl;  // 2
    s.pop();
    cout << "Top element after third pop: " << s.top() << endl;  // 5
    s.pop();
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;  // Yes
    return 0;
}
