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

class BST{
public:
    Node* insert(Node* root, int val){
        if(root == NULL) return new Node(val);
        if(val < root->data) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    Node* searchRec(Node* root, int key){
        if(root == NULL || root->data == key) return root;
        if(key < root->data) return searchRec(root->left, key);
        else return searchRec(root->right, key);
    }

    Node* searchNonRec(Node* root, int key){
        while(root != NULL){
            if(root->data == key) return root;
            if(key < root->data) root = root->left;
            else root = root->right;
        }
        return NULL;
    }

    Node* maxNode(Node* root){
        while(root && root->right) root = root->right;
        return root;
    }

    Node* minNode(Node* root){
        while(root && root->left) root = root->left;
        return root;
    }

    Node* inorderSuccessor(Node* root, Node* x){
        if(x->right) return minNode(x->right);
        Node* succ = NULL;
        while(root){
            if(x->data < root->data){
                succ = root;
                root = root->left;
            } else if(x->data > root->data){
                root = root->right;
            } else break;
        }
        return succ;
    }

    Node* inorderPredecessor(Node* root, Node* x){
        if(x->left) return maxNode(x->left);
        Node* pred = NULL;
        while(root){
            if(x->data > root->data){
                pred = root;
                root = root->right;
            } else if(x->data < root->data){
                root = root->left;
            } else break;
        }
        return pred;
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
    for(int i=0;i<7;i++) root = b.insert(root, a[i]);

    cout << "Inorder: ";
    b.inorder(root);
    cout << endl;

    Node* s = b.searchRec(root,15);
    if(s) cout << "Found recursive: " << s->data << endl;
    s = b.searchNonRec(root,25);
    if(s) cout << "Found non-recursive: " << s->data << endl;

    cout << "Max: " << b.maxNode(root)->data << endl;
    cout << "Min: " << b.minNode(root)->data << endl;

    Node* x = b.searchRec(root,20);
    Node* succ = b.inorderSuccessor(root,x);
    Node* pred = b.inorderPredecessor(root,x);
    if(succ) cout << "Successor of 20: " << succ->data << endl;
    if(pred) cout << "Predecessor of 20: " << pred->data << endl;
}

