#include<iostream>
using namespace std;

//e.g., preorder: 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

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

node*build_BST_from_preorder_format(){
    //10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

    int data;
    cin>>data;

    node*root = new node(data);

    string lft, ryt;
    cin>>lft;
    if(lft=="true")
        root->left = build_BST_from_preorder_format();

    cin>>ryt;
    if(ryt=="true")
        root->right = build_BST_from_preorder_format();

    return root;
}

void preorder_print(node*root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder_print(root->left);
    preorder_print(root->right);
}

int height(node*root){
    if(root==NULL)
        return 0;

    int ls_height = height(root->left);                     //left subtree height
    int rs_height = height(root->right);
    return max(ls_height, rs_height)+1;
}

void print_Kth_level(node*root, int k, string order){
    if(root==NULL)
        return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    if(order=="l2r"){
        print_Kth_level(root->left, k-1, order);
        print_Kth_level(root->right, k-1, order);
    }
    if(order=="r2l"){
        print_Kth_level(root->right, k-1, order);
        print_Kth_level(root->left, k-1, order);
    }
    return;
}

void print_All_levels(node*root){
    if(root==NULL)
        return;
    int ht_tree = height(root);
    for(int i=1; i<=ht_tree; i++){
        string order;
        if(i%2 != 0)
            order = "l2r";
        else
            order = "r2l";
        print_Kth_level(root, i, order);
    }
    return;
}


int main(){
    node*root = build_BST_from_preorder_format();

    print_All_levels(root);
    cout<<endl;
    return 0;
}

