#include<iostream>
#include<queue>
using namespace std;

//e.g, tree: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

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

node*buildTree(){
    int data;
    cin>>data;

    if(data==-1)
        return NULL;

    node*root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
//
//void bfs_better(node*root){
////    if(root==NULL)
////        return;
////    queue<pair<node*, int>> q;
////
////    q.push(pair(root, 1));
////    int level=1;
////    while(!q.empty()){
////        pair<node*, int> f = q.front();
////        level = f.second;
////        cout<<f.first->data<<" ";
////        q.push()
////    }
//    if(root==NULL)
//        return;
//
//    queue<pair<node*, int>> q;
//
//    pair<node*, int> p;
//    p.first = root;
//    int k=1;
//    p.second = 1;
//    q.push(p);
//    while(!q.empty()){
//        pair<node*, int> f = q.front();
//        cout<<f.first->data<<" ";
//        q.pop();
//        if(k!=f.second){
//            cout<<endl;
//        }
//        pair<node*, int> t;
//        if(f.first->left){
//            t.first = f.first->left;
//            t.second = k-1;
//            q.push(t);
//        }
//        if(f.first->right){
//            t.first = f.first->right;
//            t.second = k-1;
//        }
//    }
//
//
//
//}

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


int main(){
    node*root = buildTree();
    bfs_awesome(root);


    return 0;
}
