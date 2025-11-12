#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void split(CircularLinkedList &firstHalf, CircularLinkedList &secondHalf) {
        if (!head) return;
        Node *slow = head, *fast = head;
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next->next == head) fast = fast->next;
        firstHalf.head = head;
        if (head->next != head)
            secondHalf.head = slow->next;
        fast->next = slow->next;
        slow->next = head;
    }

    void print() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll, first, second;
    cll.append(10);
    cll.append(4);
    cll.append(9);
    cll.split(first, second);
    first.print();
    second.print();
    return 0;
}