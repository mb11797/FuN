#include<iostream>
#include<queue>
#include<climits>
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


void bfs_awesome(node*root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
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

bool isBST(node*root, int minV = INT_MIN, int maxV = INT_MAX){
    if(root==NULL)
        return true;

    if(root->data >= minV && root->data<= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)){
        return true;
    }
    return false;
}

int main(){
    node*root = build();
    inorder_print(root);
    cout<<endl;
    bfs_awesome(root);
    cout<<endl;
    if(isBST(root))
        cout<<"Yes it as BST"<<endl;
    else
        cout<<"No it is not a BST"<<endl;

    return 0;
}

