#include<iostream>
#include<queue>
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

node*delete_in_BST(node*root, int data){
    if(root==NULL)
        return NULL;
    if(data < root->data){
        root->left = delete_in_BST(root->left, data);
        return root;
    }
    else if(data == root->data){
        //3 cases
        //case 1: 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //case 2: 1 child
        else if(root->left != NULL && root->right == NULL){
            node*temp = root->left;
            delete root;
            return temp;
        }
        else if(root->right != NULL && root->left == NULL){
            node*temp = root->right;
            delete root;
            return temp;
        }
        //case 3: 2 child - find the inorder successor of the root node
        else{
            //search min in right subtree or max in left subtree to replace the root
            //lets replace the min from right subtree, i.e, find the inorder successor of the root node and replace root->data with its data
            node*replace = root->right;
            while(replace->left != NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = delete_in_BST(root->right, replace->data);
            return root;
        }
    }
    else{
        root->right = delete_in_BST(root->right, data);
        return root;
    }


}


int main(){
    node*root = build();
    inorder_print(root);
    cout<<endl;
    bfs_awesome(root);
    cout<<endl;

    int d;
    cin>>d;

    root = delete_in_BST(root, d);
    inorder_print(root);
    cout<<endl;
    bfs_awesome(root);
    cout<<endl;
    return 0;
}
