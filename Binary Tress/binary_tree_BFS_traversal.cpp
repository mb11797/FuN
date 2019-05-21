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

void bfs_traversal(node*root){
    queue<node*> q;
    if(root==NULL)
        return;

    q.push(root);
    while(!q.empty()){
        node*f = q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);

    }
    return;
}

int main(){
    node*root = buildTree();
    bfs_traversal(root);
    return 0;
}
