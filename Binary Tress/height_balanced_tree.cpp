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

class HBPair{
public:
    int height;
    bool balance;
};

HBPair isHeightBalance(node*root){
    HBPair p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }

    //Recursive Case
    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);

    p.height = 1 + max(left.height, right.height);
    if(abs(left.height - right.height)<=1 && left.balance && right.balance)
        p.balance = true;
    else
        p.balance = false;

    return p;
}

int main(){
    node*root = buildTree();
    if(isHeightBalance(root).balance)
        cout<<"Balanced"<<endl;
    else
        cout<<"Not a Balanced Tree!"<<endl;

    return 0;
}
