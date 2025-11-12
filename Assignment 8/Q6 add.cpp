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

int search(int inorder[], int start, int end, int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val) return i;
    }
    return -1;
}

Node* build(int inorder[], int postorder[], int start, int end, int &postIndex){
    if(start > end) return NULL;
    int val = postorder[postIndex--];
    Node* root = new Node(val);
    if(start == end) return root;
    int pos = search(inorder, start, end, val);
    root->right = build(inorder, postorder, pos+1, end, postIndex);
    root->left = build(inorder, postorder, start, pos-1, postIndex);
    return root;
}

void preorder(Node* root){
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n;
    cin >> n;
    int inorder[100], postorder[100];
    for(int i=0;i<n;i++) cin >> inorder[i];
    for(int i=0;i<n;i++) cin >> postorder[i];

    int postIndex = n-1;
    Node* root = build(inorder, postorder, 0, n-1, postIndex);

    preorder(root);
    cout << endl;
}

