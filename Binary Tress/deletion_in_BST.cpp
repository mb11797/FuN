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

void inorder_print(node*root){
    if(root==NULL)
        return;

    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
    return;
}

node*insert_in_BST(node*root, int data){
    if(root==NULL)
        return new node(data);
    if(data <= root->data){
        root->left = insert_in_BST(root->left, data);
    }
    else{
        root->right = insert_in_BST(root->right, data);
    }
    return root;
}


node*build(){
    int data;
    cin>>data;

    node*root = NULL;
    while(data != -1){
        root = insert_in_BST(root, data);
        cin>>data;
    }
    return root;
}



int main(){
    node*root = build();
    inorder_print(root);
    cout<<endl;

    return 0;
}
