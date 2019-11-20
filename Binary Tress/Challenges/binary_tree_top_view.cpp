#include<iostream>
#include<queue>
#include<map>
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

void top_view_binary_tree(node*root){
    if(root==NULL)
        return;

    map<int, int> m;

    queue<pair<node*, int>> q;                  //pair - curr_node and horizontal_distance_from_root

    q.push({root, 0});
    while(!q.empty()){
        pair<node*, int> f = q.front();
        node*temp = f.first;
        int h_d = f.second;
        q.pop();

        if(m.find(h_d) == m.end()){
            m[h_d] = temp->data;
        }

        if(temp->left){
            q.push({temp->left, h_d - 1});
        }
        if(temp->right){
            q.push({temp->right, h_d + 1});
        }
    }

    map<int, int> :: iterator it;
    for(it = m.begin(); it!=m.end(); it++){
        cout<<it->second<<" ";
    }
}

int main(){
    node*root = build_tree_from_level_0rder_input();

    preorder_print(root);
    cout<<endl;
    top_view_binary_tree(root);
    cout<<endl;
    return 0;
}
