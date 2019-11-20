#include<iostream>
#include<algorithm>
using namespace std;

/*
n = 9
Preorder: 8 10 1 6 9 7 3 14 13
Inorder: 1 10 9 6 7 8 3 13 14
*/

/*
4
60 65 50 70
50 65 60 70
2
60 1
65 2
*/

/*
7
20 8 4 12 10 14 22
4 8 10 12 14 20 22
5
4 2
12 3
22 2
8 1
10 1
*/

int got = 0;
int arr[1001];

class node{
public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node*BT_from_preorder_and_inorder_trav(int pre[], int in[], int s, int e){
    static int p = 0;
    if(s > e){
        return NULL;
    }

    node*root = new node(pre[p]);

    int idx = -1;
    for(int i=s; i<=e; i++){
        if(pre[p] == in[i]){
            idx = i;
            break;
        }
    }

    p++;

    root->left = BT_from_preorder_and_inorder_trav(pre, in, s, idx-1);
    root->right = BT_from_preorder_and_inorder_trav(pre, in, idx+1, e);
    return root;
}

void print_preorder_traversal(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print_preorder_traversal(root->left);
    print_preorder_traversal(root->right);
    return;
}

void print_nodes_at_dist_k_downwards(node*root, int k, int &status){
    if(root == NULL || k<0){
        return;
    }

    if(k==0){
//        cout<<root->data<<" ";
        arr[got++] = root->data;
        status = 1;
    }

    print_nodes_at_dist_k_downwards(root->left, k-1, status);
    print_nodes_at_dist_k_downwards(root->right, k-1, status);
    return;
}

int print_nodes_at_dist_k(node*root, int target_data, int k, int &status){
    if(root == NULL){
        return -1;
    }

    if(root->data == target_data){
        print_nodes_at_dist_k_downwards(root, k, status);
        return 0;
    }

    int dl = print_nodes_at_dist_k(root->left, target_data, k, status);
    if(dl != -1){
        if(dl + 1 == k){
//            cout<<root->data<<" ";
            arr[got++] = root->data;
            status = 1;
        }else{
            print_nodes_at_dist_k_downwards(root->right, k-dl-2, status);
        }

        return dl+1;
    }

    int dr = print_nodes_at_dist_k(root->right, target_data, k, status);
    if(dr != -1){
        if(dr + 1 == k){
//            cout<<root->data<<" ";
            arr[got++] = root->data;
            status = 1;
        }else{
            print_nodes_at_dist_k_downwards(root->left, k-dr-2, status);
        }

        return dr+1;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;

    int pre[1001];
    int in[1001];
    for(int i=0; i<n; i++)
        cin>>pre[i];
    for(int i=0; i<n; i++)
        cin>>in[i];

    node*root = BT_from_preorder_and_inorder_trav(pre, in, 0, n-1);

//    print_preorder_traversal(root);
//    cout<<endl;

    int q;
    cin>>q;

    while(q--){
        int target, k;
        cin>>target>>k;

        int status = 0;
        print_nodes_at_dist_k(root, target, k, status);
        if(status == 0){
            cout<<0;
        }
        else{
            sort(arr, arr+got);
            for(int i=0; i<got; i++)
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        got = 0;
    }

    return 0;
}
