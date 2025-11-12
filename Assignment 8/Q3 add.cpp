#include<iostream>
#include<queue>
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

Node* buildTree(int arr[], int n){
    if(n == 0 || arr[0] == -1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while(!q.empty() && i < n){
        Node* cur = q.front();
        q.pop();

        if(i < n && arr[i] != -1){
            cur->left = new Node(arr[i]);
            q.push(cur->left);
        }
        i++;

        if(i < n && arr[i] != -1){
            cur->right = new Node(arr[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int maxDepth(Node* root){
    if(!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int arr[1000];
        for(int i=0;i<n;i++) cin >> arr[i];

        Node* root = buildTree(arr, n);
        cout << maxDepth(root) << endl;
    }
}

