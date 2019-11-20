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

class Pair{
public:
    int height;
    int diameter;
};

Pair fast_diameter(node*root){
    Pair p;
    if(root==NULL){
        p.height = p.diameter = 0;
        return p;
    }

    Pair pLeft = fast_diameter(root->left);
    Pair pRight = fast_diameter(root->right);

    p.height = 1 + max(pLeft.height, pRight.height);
    p.diameter = max(pLeft.height + pRight.height, max(pLeft.diameter, pRight.diameter));
    return p;
}


int main(){
    node*root = buildTree();
    Pair p = fast_diameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;

    return 0;
}
