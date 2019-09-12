#include<iostream>
#include<map>
#include<vector>
using namespace std;

//e.g, tree1: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
//e.g, tree2: 1 2 4 -1 -1 5 -1 8 -1 -1 3 6 -1 -1 7 -1 9 -1 -1

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

node*build_tree(){

    int data;
    cin>>data;

    if(data == -1)
        return NULL;

    node*root = new node(data);
    root->left = build_tree();
    root->right = build_tree();
    return root;
}

void print_preorder(node*root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
    return;
}

void vertical_order_print(node*root, map<int, vector<int>> &m, int dis=0){
    if(root == NULL){
        return;
    }

    m[dis].push_back(root->data);
    vertical_order_print(root->left, m, dis-1);
    vertical_order_print(root->right, m, dis+1);
    return;
}

int main(){
    node*root = build_tree();

    print_preorder(root);

    cout<<endl;

    map<int, vector<int>> m;
    vertical_order_print(root, m);

    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<"->";

        ///vector
        for(int j=0; j<it->second.size(); j++){
            cout<<it->second[j]<<", ";
        }
        cout<<endl;
    }

    return 0;
}
