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

class Tree{
public:
    Node* create(){
        int val;
        cin >> val;
        if(val == -1) return NULL;
        Node* root = new Node(val);
        root->left = create();
        root->right = create();
        return root;
    }

    bool isBST(Node* root, Node* min=NULL, Node* max=NULL){
        if(!root) return true;
        if((min && root->data <= min->data) || (max && root->data >= max->data))
            return false;
        return isBST(root->left, min, root) && isBST(root->right, root, max);
    }
};

int main(){
    Tree t;
    cout << "Enter tree (-1 for NULL): ";
    Node* root = t.create();
    if(t.isBST(root)) cout << "It is a BST";
    else cout << "It is not a BST";
}

