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

Node** generate(int start, int end, int &count){
    if(start > end){
        Node** arr = new Node*[1];
        arr[0] = NULL;
        count = 1;
        return arr;
    }

    Node** result = new Node*[1000];
    count = 0;

    for(int i = start; i <= end; i++){
        int leftCount = 0, rightCount = 0;
        Node** left = generate(start, i - 1, leftCount);
        Node** right = generate(i + 1, end, rightCount);

        for(int l = 0; l < leftCount; l++){
            for(int r = 0; r < rightCount; r++){
                Node* root = new Node(i);
                root->left = left[l];
                root->right = right[r];
                result[count++] = root;
            }
        }
        delete[] left;
        delete[] right;
    }
    return result;
}

void preorder(Node* root){
    if(!root){
        cout << "null ";
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n;
    cin >> n;
    int total = 0;
    Node** trees = generate(1, n, total);
    cout << "Total BSTs: " << total << endl;
    for(int i = 0; i < total; i++){
        cout << i + 1 << ": ";
        preorder(trees[i]);
        cout << endl;
    }
    delete[] trees;
}

