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

    int sumLeft(Node* root, bool isLeft){
        if(!root) return 0;
        if(!root->left && !root->right && isLeft) return root->data;
        return sumLeft(root->left, true) + sumLeft(root->right, false);
    }
};

int main(){
    Tree t;
    cout << "Enter tree (-1 for NULL): ";
    Node* root = t.create();
    cout << "Sum of left leaves: " << t.sumLeft(root, false);
}

