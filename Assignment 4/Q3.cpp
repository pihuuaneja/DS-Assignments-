#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull(int n) {
    return (rear == n - 1);
}

void enqueue(int value, int n) {
    if (isFull(n)) return;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
}

int dequeue() {
    if (isEmpty()) return -1;
    int val = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return val;
}

int main() {
    int n, i;
    printf("Enter number of elements (even): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // first half queue
    int q1[SIZE], f1 = -1, r1 = -1;
    // second half queue
    int q2[SIZE], f2 = -1, r2 = -1;

    // Fill first half in q1, second half in q2
    for (i = 0; i < n / 2; i++) {
        if (f1 == -1) f1 = 0;
        q1[++r1] = arr[i];
    }
    for (i = n / 2; i < n; i++) {
        if (f2 == -1) f2 = 0;
        q2[++r2] = arr[i];
    }

    // Interleave elements
    int result[n], k = 0;
    while (f1 <= r1 && f2 <= r2) {
        result[k++] = q1[f1++];
        result[k++] = q2[f2++];
    }

    printf("Interleaved Queue: ");
    for (i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
