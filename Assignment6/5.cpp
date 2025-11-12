
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev, *up, *down;
    Node(int val) {
        data = val;
        next = prev = up = down = nullptr;
    }
};

class MatrixDLL {
public:
    Node* construct(int mat[3][3], int n, int m) {
        Node* head = nullptr;
        Node* rowStart = nullptr;
        Node* prevRowStart = nullptr;

        for (int i = 0; i < n; i++) {
            Node* prev = nullptr;
            for (int j = 0; j < m; j++) {
                Node* newNode = new Node(mat[i][j]);
                if (!head) head = newNode;

                if (!rowStart) rowStart = newNode;

                if (prev) {
                    prev->next = newNode;
                    newNode->prev = prev;
                }
                if (prevRowStart) {
                    prevRowStart->down = newNode;
                    newNode->up = prevRowStart;
                    prevRowStart = prevRowStart->next;
                }
                prev = newNode;
            }
            prevRowStart = rowStart;
            rowStart = nullptr;
        }
        return head;
    }

    void printRowWise(Node* head, int cols) {
        Node* row = head;
        while (row) {
            Node* col = row;
            for (int i = 0; i < cols && col; i++) {
                cout << col->data << " ";
                col = col->next;
            }
            cout << endl;
            row = row->down;
        }
    }
};

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    MatrixDLL obj;
    Node* head = obj.construct(mat, 3, 3);
    obj.printRowWise(head, 3);
    return 0;
}