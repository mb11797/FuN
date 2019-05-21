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

void printPre(node*root){
    if(root==NULL)
        return;

    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}

void printIn(node*root){
    if(root==NULL)
        return;

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node*root){
    if(root==NULL)
        return;
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

int main(){
    node*root = buildTree();

    printPre(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    printPost(root);
    cout<<endl;



    return 0;
}
