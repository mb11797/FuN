#include<iostream>
#include<queue>
#include<map>
#include<vector>
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

    if(data == -1)
        return NULL;

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

void preorder_print(node*root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder_print(root->left);
    preorder_print(root->right);
    return;
}

class node_n_dist{
public:
    int dist;
    node*n;

    node_n_dist(node*root, int dis){
        dist = dis;
        n = root;
    }
};

void vertical_order_traversal(node*root){
    if(root == NULL)
        return;
    map<int, vector<int>> m;
    queue<node_n_dist*> q;
    node_n_dist*n_n_d = new node_n_dist(root, 0);
    q.push(n_n_d);
    while(!q.empty()){
        node_n_dist*f = q.front();
        q.pop();
        m[f->dist].push_back(f->n->data);
        if(f->n->left != NULL){
            q.push(new node_n_dist(f->n->left, f->dist - 1));
        }
        if(f->n->right != NULL){
            q.push(new node_n_dist(f->n->right, f->dist + 1));
        }
    }

    map<int, vector<int>> :: iterator it;
    for(it = m.begin(); it != m.end(); it++){

        for(int i=0; i<it->second.size(); i++)
            cout<<it->second[i]<<" ";

        cout<<endl;

    }

}


int main(){
    node*root = build_tree_from_level_0rder_input();
    preorder_print(root);
    cout<<endl;

    vertical_order_traversal(root);
    return 0;
}
