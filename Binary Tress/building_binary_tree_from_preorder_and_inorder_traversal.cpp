#include<iostream>
#include<queue>
using namespace std;

//e.g.:
//int pre[] = {1,2,3,4,8,5,6,7};
//int in[] = {3,2,8,4,1,6,7,5};

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

node*build_bt_from_inorder_n_preorder_trav(int*in, int*pre, int s, int e){
    static int i = 0;
    if(s>e)
        return NULL;

    node*root = new node(pre[i]);

    int index = -1;
    for(int j=s; j<=e; j++){
        if(in[j]==pre[i]){
            index = j;
            break;
        }
    }

    i++;

    root->left = build_bt_from_inorder_n_preorder_trav(in, pre, s, index-1);
    root->right = build_bt_from_inorder_n_preorder_trav(in, pre, index+1, e);

    return root;
}

int main(){
    int pre[] = {1,2,3,4,8,5,6,7};
    int in[] = {3,2,8,4,1,6,7,5};
    int n = sizeof(pre)/sizeof(int);

    node*root = build_bt_from_inorder_n_preorder_trav(in, pre, 0, n-1);
    bfs_awesome(root);
    return 0;
}
