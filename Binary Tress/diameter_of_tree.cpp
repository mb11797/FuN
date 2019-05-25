#include<iostream>
using namespace std;

//e.g, tree: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

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

node*buildTree(){
    int data;
    cin>>data;

    if(data==-1)
        return NULL;

    node*root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int height(node*root){
    if(root==NULL)
        return 0;
    int ht_left = height(root->left);
    int ht_right = height(root->right);
    return 1 + max(ht_left, ht_right);
}

int diameter(node*root){
    if(root==NULL)
        return 0;

    int ht_left = height(root->left);
    int ht_right = height(root->right);
    int op1 = ht_left + ht_right;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}

int main(){
    node*root = buildTree();
    cout<<diameter(root)<<endl;
    return 0;
}
