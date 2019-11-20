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

void get_vertical_order(node*root, int h_d, map<int, vector<int>> &m){
    if(root == NULL)
        return;

    //store current node in map m
    m[h_d].push_back(root->data);

    //store nodes in left subtree
    get_vertical_order(root->left, h_d - 1, m);

    //store nodes in right subtree
    get_vertical_order(root->right, h_d + 1, m);

    return;
}

void vertical_order_traversal_print(node*root){
    map<int, vector<int>> m;
    int h_d = 0;                     //horizontal distance from root
    get_vertical_order(root, h_d, m);

    //traverse the map and print the nodes at every horizontal distance
    map<int, vector<int>> :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout<<it->first<<" : ";
        for(int i=0; i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
//        cout<<it->second[0]<<" ";                       // for top view of binary tree
//        cout<<it->second[it->second.size()-1]<<" ";     // for bottom view of binary tree
    }

    return;
}

int main(){
    node*root = build_tree_from_level_0rder_input();

    vertical_order_traversal_print(root);

    return 0;
}

