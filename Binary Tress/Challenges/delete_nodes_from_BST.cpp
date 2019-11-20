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

node*insert_in_BST(node*root, int data){
    if(root == NULL)
        return new node(data);

    if(data <= root->data){
        root->left = insert_in_BST(root->left, data);
    }
    else if(data > root->data){
        root->right = insert_in_BST(root->right, data);
    }
    return root;
}

node*build(int*arr, int n){
    int i=0;
    node*root = NULL;
    while(i<n){
        root = insert_in_BST(root, arr[i]);
        i++;
    }
    return root;
}

void preorder_print(node*root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorder_print(root->left);
    preorder_print(root->right);
    return;
}

node*delete_in_BST(node*root, int data){
    if(root == NULL)
        return NULL;

    if(data < root->data){
        root->left = delete_in_BST(root->left, data);
        return root;
    }
    else if(data == root->data){
        //3 cases

        //Case 1: target node has 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //Case 2: target node has 1 child
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

        //Case 3: target node has 2 child
        else{
            //replace the target node with either max node in the left subtree or min node in the right subtree
            //here, lets replace it with max node in the left subtree
            node*replace = root->left;
            while(replace->right != NULL){
                replace = replace->right;
            }
            root->data = replace->data;
            root->left = delete_in_BST(root->left, replace->data);
            return root;
        }
    }
    else{
        root->right = delete_in_BST(root->right, data);
        return root;
    }
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int a1[n];
        for(int i=0; i<n; i++)
            cin>>a1[i];
        node*root = build(a1, n);

        int m;
        cin>>m;
        int a2[m];
        for(int i=0; i<m; i++)
            cin>>a2[i];

        //delete all the elements from BST that are given in a2[] array
        for(int i=0; i<m; i++)
            root = delete_in_BST(root, a2[i]);

        preorder_print(root);
    }
    return 0;
}



