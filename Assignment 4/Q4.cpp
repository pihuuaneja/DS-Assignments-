#include <stdio.h>

#define SIZE 100

char queue[SIZE];
int front = -1, rear = -1;

void enqueue(char ch) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = ch;
}

void dequeue() {
    if (front == -1) return;
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

char peek() {
    if (front == -1) return '\0';
    return queue[front];
}

int isEmpty() {
    return (front == -1);
}

int main() {
    char str[SIZE];
    printf("Enter characters (with spaces allowed): ");
    scanf("%[^\n]s", str);

    int freq[256] = {0};
    int i = 0;

    while (str[i] != '\0') {
        char ch = str[i];
        if (ch != ' ') {
            enqueue(ch);
            freq[(int)ch]++;

            while (!isEmpty() && freq[(int)peek()] > 1) {
                dequeue();
            }

            if (isEmpty()) {
                printf("-1 ");
            } else {
                printf("%c ", peek());
            }
        }
        i++;
    }

    printf("\n");
    return 0;
}
