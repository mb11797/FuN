#include<iostream>
#include<queue>
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

node*insert_in_BST(node*root, int data){
    if(root==NULL)
        return new node(data);

    if(data <= root->data){
        root->left = insert_in_BST(root->left, data);
    }
    if(data > root->data){
        root->right = insert_in_BST(root->right, data);
    }
    return root;
}

node*build_BST(int*arr, int n){
    node*root = NULL;
    for(int i=0; i<n; i++){
        root = insert_in_BST(root, arr[i]);
    }
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

void print_bst_keys_within_the_range(node*root, int k1, int k2){
    if(root==NULL)
        return;

    if(k1 < root->data)
        print_bst_keys_within_the_range(root->left, k1, k2);
    if(k1<=root->data && k2>=root->data)
        cout<<root->data<<" ";
    if(k2 > root->data)
        print_bst_keys_within_the_range(root->right, k1, k2);
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

        int k1, k2;
        cin>>k1>>k2;

        node*root = build_BST(arr, n);
        cout<<"# Preorder : ";
        preorder_print(root);
        cout<<endl;
        cout<<"# Nodes within range are : ";
        print_bst_keys_within_the_range(root, k1, k2);
        cout<<endl;
    }
    return 0;
}
