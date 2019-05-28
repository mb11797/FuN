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

void preorder_print(node*root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder_print(root->left);
    preorder_print(root->right);
    return;
}

node*build(node*root){
    string lft, ryt;
    int data;
    cin>>data;
    root = new node(data);

    cin>>lft;
    if(lft=="true"){
        root->left = build(root->left);
    }
    else{                                           //not needed as such because by default node cnstructor makes left and right nodes as null
        root->left = NULL;
    }

    cin>>ryt;
    if(ryt=="true"){
        root->right = build(root->right);
    }
    else{
        root->right = NULL;
    }
    return root;
}

class HBPair{
public:
    int height;
    bool balance;
};

HBPair check_balance(node*root){
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }

    HBPair left = check_balance(root->left);
    HBPair right = check_balance(root->right);

    p.height = 1 + max(left.height, right.height);

    if(abs(left.height - right.height) <= 1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}


int main(){
    node*root = NULL;
    root = build(root);
    preorder_print(root);
    cout<<endl;

    if(check_balance(root).balance)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}





