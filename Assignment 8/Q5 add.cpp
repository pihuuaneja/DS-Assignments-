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
    for(int i=start; i<=end; i++){
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

Node* build(int inorder[], int preorder[], int start, int end, int &preIndex){
    if(start > end) return NULL;

    int val = preorder[preIndex++];
    Node* root = new Node(val);

    if(start == end) return root;

    int pos = search(inorder, start, end, val);

    root->left = build(inorder, preorder, start, pos-1, preIndex);
    root->right = build(inorder, preorder, pos+1, end, preIndex);

    return root;
}

void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    int n;
    cin >> n;
    int inorder[100], preorder[100];

    for(int i=0; i<n; i++) cin >> inorder[i];
    for(int i=0; i<n; i++) cin >> preorder[i];

    int preIndex = 0;
    Node* root = build(inorder, preorder, 0, n-1, preIndex);

    postorder(root);
    cout << endl;
}

