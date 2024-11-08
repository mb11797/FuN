#include<iostream>
#include<queue>
using namespace std;

//e.g. BST: 5 3 7 1 6 8 -1

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


void inorder_print(node*root){
    if(root==NULL)
        return;

    inorder_print(root->left);
    cout<<root->data<<", ";
    inorder_print(root->right);
    return;
}


//Accepts the old root node & data, and returns the new root node
node*insert_in_BST(node*root, int data){
    //base case
    if(root==NULL){
        return new node(data);
    }
    //recursive case - insert in the subtree and update pointers
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

bool search(node*root, int data){
    if(root==NULL)
        return false;

    if(data == root->data)
        return true;

    //Recursively search in left and right subtree
    if(data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int main(){
    node*root = build();
    inorder_print(root);
    cout<<endl;
    bfs_awesome(root);
    cout<<endl;

    int key;
    cin>>key;

    if(search(root, key))
        cout<<"Present"<<endl;
    else
        cout<<"Not Present"<<endl;


    return 0;
}
