#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode *prev, *next;
    DNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DLL {
public:
    DNode* head;
    DLL() { head = nullptr; }

    void append(int val) {
        DNode* newNode = new DNode(val);
        if (!head) { head = newNode; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int parity(int n) {
        int c = 0;
        while (n) { c += n & 1; n >>= 1; }
        return c;
    }

    void removeEvenParity() {
        DNode* curr = head;
        while (curr) {
            DNode* nxt = curr->next;
            if (parity(curr->data) % 2 == 0) {
                if (curr->prev) curr->prev->next = curr->next;
                else head = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
                delete curr;
            }
            curr = nxt;
        }
    }

    void print() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <=> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) { data = val; next = nullptr; }
};

class CLL {
public:
    CNode* head;
    CLL() { head = nullptr; }

    void append(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    int parity(int n) {
        int c = 0;
        while (n) { c += n & 1; n >>= 1; }
        return c;
    }

    void removeEvenParity() {
        if (!head) return;
        CNode *curr = head, *prev = nullptr;
        do {
            CNode* nxt = curr->next;
            if (parity(curr->data) % 2 == 0) {
                if (curr == head) {
                    if (curr->next == head) {
                        delete curr;
                        head = nullptr;
                        return;
                    }
                    CNode* temp = head;
                    while (temp->next != head) temp = temp->next;
                    temp->next = curr->next;
                    head = curr->next;
                    delete curr;
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
            } else prev = curr;
            curr = nxt;
        } while (curr != head);
    }

    void print() {
        if (!head) return;
        CNode* temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head) cout << " -> ";
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DLL dll;
    dll.append(18);
    dll.append(15);
    dll.append(8);
    dll.append(9);
    dll.append(14);
    dll.removeEvenParity();
    dll.print();

    CLL cll;
    cll.append(9);
    cll.append(11);
    cll.append(34);
    cll.append(6);
    cll.append(13);
    cll.append(21);
    cll.removeEvenParity();
    cll.print();
    return 0;
}