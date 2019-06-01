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

node* build_BST_from_inorder_array(int*in, int s, int e){
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    node*root = new node(in[mid]);
    root->left = build_BST_from_inorder_array(in, s, mid-1);
    root->right = build_BST_from_inorder_array(in, mid+1, e);
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

void replace_sum_with_greater_nodes(node*root, int *sum){
    if(root==NULL)
        return;

    //rec for right subtree
    replace_sum_with_greater_nodes(root->right, sum);

    //now *sum has sum of nodes greater than current root in right subtree,
    //add root->data to *sum and update root->data
    *sum = *sum + root->data;
    root->data = *sum;

    //rec for left subtree
    replace_sum_with_greater_nodes(root->left, sum);
    return;
}


int main(){
    int n;
    cin>>n;
    int in[n];
    for(int i=0; i<n; i++)
        cin>>in[i];

    node*root = build_BST_from_inorder_array(in, 0, n-1);                     //assumption (although BST cant be built from inorder only)

    int sum = 0;
    replace_sum_with_greater_nodes(root, &sum);
    preorder_print(root);
    cout<<endl;

    return 0;
}
