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

class BST{
public:
    Node* insert(Node* root, int v){
        if(!root) return new Node(v);
        if(v < root->data) root->left = insert(root->left, v);
        else if(v > root->data) root->right = insert(root->right, v);
        return root;
    }

    Node* minNode(Node* root){
        while(root && root->left) root = root->left;
        return root;
    }

    Node* del(Node* root, int v){
        if(!root) return root;
        if(v < root->data) root->left = del(root->left, v);
        else if(v > root->data) root->right = del(root->right, v);
        else{
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            Node* t = minNode(root->right);
            root->data = t->data;
            root->right = del(root->right, t->data);
        }
        return root;
    }

    int maxDepth(Node* root){
        if(!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return (l > r ? l : r) + 1;
    }

    int minDepth(Node* root){
        if(!root) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(!root->left || !root->right) return l + r + 1;
        return (l < r ? l : r) + 1;
    }

    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main(){
    BST b;
    Node* root = NULL;
    int a[] = {20,10,5,15,30,25,35};
    for(int i=0;i<7;i++) root = b.insert(root,a[i]);

    cout << "Inorder: ";
    b.inorder(root);
    cout << endl;

    root = b.del(root,10);
    cout << "After deleting 10: ";
    b.inorder(root);
    cout << endl;

    cout << "Max depth: " << b.maxDepth(root) << endl;
    cout << "Min depth: " << b.minDepth(root) << endl;
}

