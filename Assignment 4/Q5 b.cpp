#include <stdio.h>
#define SIZE 100

int q[SIZE];
int f=-1,r=-1;

int isEmpty() { return (f==-1); }
void enqueue(int val) {
    if (r==SIZE-1) return;
    if (f==-1) f=0;
    q[++r] = val;
}
int dequeue() {
    if (f==-1) return -1;
    int val=q[f];
    if (f==r) f=r=-1;
    else f++;
    return val;
}

// stack using one queue
void push(int val) {
    enqueue(val);
    int sz=r-f;
    for(int i=0;i<sz;i++) {
        enqueue(dequeue());
    }
}
int pop() {
    if (isEmpty()) return -1;
    return dequeue();
}

int main() {
    push(1);
    push(2);
    push(3);
    printf("%d ",pop());
    printf("%d ",pop());
    push(4);
    printf("%d ",pop());
    return 0;
}
