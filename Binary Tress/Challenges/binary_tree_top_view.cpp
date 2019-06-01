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

node*build_tree_from_level_0rder_input(){
    int data;
    cin>>data;

    node*root = new node(data);

    queue<node*> q;

    q.push(root);
    while(!q.empty()){
        node*f = q.front();
        q.pop();
        int left, right;
        cin>>left;
        if(left != -1){
            f->left = new node(left);
            q.push(f->left);
        }
        cin>>right;
        if(right != -1){
            f->right = new node(right);
            q.push(f->right);
        }
    }
    return root;
}

void preorder_print(node*root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder_print(root->left);
    preorder_print(root->right);
    return;
}

void bt_top_view(node*root, int level, char sub_tree){
    if(sub_tree=='l' && root->left==NULL){
        cout<<root->data<<" ";
        return;
    }
    if(sub_tree=='r' && root->right==NULL){
        cout<<root->data<<" ";
        return;
    }
    bt_top_view(root->left, level+1, 'l');
    cout<<root->data<<" ";
    if(level==1){
        bt_top_view(root->right, level+1, 'r');
    }

}

int main(){
    node*root = build_tree_from_level_0rder_input();

    preorder_print(root);

    return 0;
}
