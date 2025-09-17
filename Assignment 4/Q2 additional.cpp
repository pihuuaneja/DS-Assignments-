#include <iostream>
#define SIZE 5
using namespace std;

class CircularQueue
{
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull() { return (rear + 1) % SIZE == front; }

    bool isEmpty() { return front == -1; }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    cout << "Front element: " << q.peek() << endl;
    return 0;
}
