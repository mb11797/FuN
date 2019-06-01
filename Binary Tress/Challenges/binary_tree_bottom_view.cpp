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
        int lft, ryt;
        cin>>lft>>ryt;
        if(lft != -1){
            f->left = new node(lft);
            q.push(f->left);
        }
        if(ryt != -1){
            f->right = new node(ryt);
            q.push(f->right);
        }
    }
    return root;
}





int main(){
    node*root = build_tree_from_level_0rder_input();
    preorder_print(root);
    cout<<endl;
//    bottom_view_binary_tree(root);

    return 0;
}
