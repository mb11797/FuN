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

int height(node*root){
    if(root==NULL)
        return 0;

    int ls_height = height(root->left);                     //left subtree height
    int rs_height = height(root->right);
    return max(ls_height, rs_height)+1;
}

void print_Kth_level(node*root, int k){
    if(root==NULL)
        return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    print_Kth_level(root->left, k-1);
    print_Kth_level(root->right, k-1);
    return;
}

void print_All_levels(node*root){
    if(root==NULL)
        return;
    int ht_tree = height(root);
    for(int i=1; i<=ht_tree; i++){
        print_Kth_level(root, i);
        cout<<endl;
    }
    return;
}

int main(){
    node*root = buildTree();

    printPre(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    printPost(root);
    cout<<endl;

    cout<<height(root)<<endl;

    print_Kth_level(root, 3);
    cout<<endl;
    print_Kth_level(root, 2);
    cout<<endl;

    print_All_levels(root);

    return 0;
}
