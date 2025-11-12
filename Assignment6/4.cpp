#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev, *random;
    Node(int val) {
        data = val;
        next = prev = random = nullptr;
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

    void correctRandom() {
        if (!head) return;
        Node* temp = head;
        while (temp) {
            if (temp->random && temp->random->next == temp) {
                temp->random = temp->prev;
                break;
            }
            temp = temp->next;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << "Node " << temp->data << " ";
            if (temp->random)
                cout << "-> random: " << temp->random->data;
            cout << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);

    dll.head->random = dll.head->next->next;           // node 1 → 3
    dll.head->next->next->random = dll.head->next;     // node 3 → 2 (wrong random)
    dll.correctRandom();
    dll.printList();
    return 0;
}