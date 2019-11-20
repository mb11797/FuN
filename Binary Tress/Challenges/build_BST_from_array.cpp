#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* build_BST_from_array(node*root, int arr[], int s, int e){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    root = new node(arr[mid]);
    root->left = build_BST_from_array(root->left, arr, s, mid-1);
    root->right = build_BST_from_array(root->right, arr, mid+1, e);
    return root;
}

void preorder_print(node*root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder_print(root->left);
    preorder_print(root->right);
    return;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        node*root = NULL;
        root = build_BST_from_array(root, arr, 0, n-1);

        preorder_print(root);
    }

    return 0;
}
