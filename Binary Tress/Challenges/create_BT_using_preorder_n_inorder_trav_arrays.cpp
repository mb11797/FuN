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

node*build_bt_from_pre_n_in(int pre[], int in[], int s, int e){
    static int i = 0;
    if(s>e)
        return NULL;
    node*root = new node(pre[i]);

    int index = -1;
    for(int j=s; j<=e; j++){
        if(in[j] == pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = build_bt_from_pre_n_in(pre, in, s, index-1);
    root->right = build_bt_from_pre_n_in(pre, in, index+1, e);
    return root;
}

void print_bt(node*root){
    if(root->left)
        cout<<root->left->data;
    else
        cout<<"END";

    cout<<" => "<<root->data<<" <= ";

    if(root->right)
        cout<<root->right->data;
    else
        cout<<"END";

    cout<<endl;
    if(root->left)
        print_bt(root->left);
    if(root->right)
        print_bt(root->right);
    return;
}

int main(){
    int n;
    cin>>n;
    int pre[n];
    for(int i=0; i<n; i++)
        cin>>pre[i];

    int m;
    cin>>m;
    int in[m];
    for(int i=0; i<m; i++)
        cin>>in[i];

    node*root = build_bt_from_pre_n_in(pre, in, 0, m-1);
    print_bt(root);

    return 0;
}
