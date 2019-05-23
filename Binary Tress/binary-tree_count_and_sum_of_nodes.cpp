#include<iostream>
#include<queue>
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

int count(node*root){
    if(root==NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);
}

int sum(node*root){
    if(root==NULL)
        return 0;
    return root->data + sum(root->left) + sum(root->right);
}

int main(){
    node*root = buildTree();
    bfs_awesome(root);
    cout<<endl;
    cout<<count(root)<<endl;
    cout<<sum(root)<<endl;

    return 0;
}
