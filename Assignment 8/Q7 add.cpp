#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int v){
        data = v;
        left = right = NULL;
    }
};

class DLL{
public:
    int data;
    DLL* prev;
    DLL* next;
    DLL(int v){
        data = v;
        prev = next = NULL;
    }
};

Node* insert(Node* root, int val){
    if(!root) return new Node(val);
    if(val < root->data) root->left = insert(root->left, val);
    else if(val > root->data) root->right = insert(root->right, val);
    return root;
}

void BSTtoDLL(Node* root, DLL* &head, DLL* &tail){
    if(!root) return;
    BSTtoDLL(root->left, head, tail);
    DLL* node = new DLL(root->data);
    if(!head) head = tail = node;
    else{
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    BSTtoDLL(root->right, head, tail);
}

DLL* mergeDLL(DLL* h1, DLL* h2){
    if(!h1) return h2;
    if(!h2) return h1;
    DLL* head = NULL;
    DLL* tail = NULL;
    while(h1 && h2){
        DLL* temp;
        if(h1->data < h2->data){
            temp = h1;
            h1 = h1->next;
        }
        else{
            temp = h2;
            h2 = h2->next;
        }
        temp->prev = tail;
        if(!head) head = temp;
        else tail->next = temp;
        tail = temp;
    }
    if(h1) tail->next = h1, h1->prev = tail;
    if(h2) tail->next = h2, h2->prev = tail;
    return head;
}

void printDLL(DLL* head){
    DLL* cur = head;
    while(cur){
        cout << cur->data;
        if(cur->next) cout << " <-> ";
        cur = cur->next;
    }
    cout << " -> null\n";
}

int main(){
    Node* t1 = NULL;
    t1 = insert(t1, 20);
    t1 = insert(t1, 10);
    t1 = insert(t1, 30);
    t1 = insert(t1, 25);
    t1 = insert(t1, 100);
    t1 = insert(t1, 50);

    Node* t2 = NULL;
    t2 = insert(t2, 5);
    t2 = insert(t2, 70);

    DLL *h1 = NULL, *t1dll = NULL;
    DLL *h2 = NULL, *t2dll = NULL;

    BSTtoDLL(t1, h1, t1dll);
    BSTtoDLL(t2, h2, t2dll);

    DLL* merged = mergeDLL(h1, h2);
    printDLL(merged);
}

