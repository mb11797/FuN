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


node*build_Height_Balanced_Binary_Tree_from_Array(int*a, int s, int e){
    //base case
    if(s>e)
        return NULL;
    //Recursive Case
    int mid = (s+e)/2;
    node*root = new node(a[mid]);
    root->left = build_Height_Balanced_Binary_Tree_from_Array(a, s, mid-1);
    root->right = build_Height_Balanced_Binary_Tree_from_Array(a, mid+1, e);
    return root;
}

int main(){
    int a[30];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    node*root = build_Height_Balanced_Binary_Tree_from_Array(a, 0, n-1);
    bfs_awesome(root);

    return 0;
}
