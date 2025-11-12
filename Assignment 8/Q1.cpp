#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
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

    void preorder(Node* root){
        if(!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(Node* root){
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main(){
    Tree t;
    Node* root = t.create();
    cout << "Preorder: ";
    t.preorder(root);
    cout << "\nInorder: ";
    t.inorder(root);
    cout << "\nPostorder: ";
    t.postorder(root);
}

