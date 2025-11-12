#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    Node* reverseInGroups(Node* head, int k) {
        Node* curr = head;
        Node* next = nullptr;
        Node* prev = nullptr;
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
            count++;
        }
        if (next) {
            head->next = reverseInGroups(next, k);
            if (head->next) head->next->prev = head;
        }
        return prev;
    }

    void reverseK(int k) {
        head = reverseInGroups(head, k);
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << " <-> NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);
    dll.append(6);
    int k = 2;
    dll.reverseK(k);
    dll.print();
    return 0;
}