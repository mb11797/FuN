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
    // LOT: 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1

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

//void print_kth_level(node*root, int k){
//    if(root==NULL){
//        return;
//    }
//    if(k == 1){
//        cout<<root->data<<" ";
//        return;
//    }
//    print_kth_level(root->left, k-1);
//    print_kth_level(root->right, k-1);
//    return;
//}
//
//int height(node*root){
//    if(root == NULL)
//        return 0;
//
//    int ht_left = height(root->left);
//    int ht_right = height(root->right);
//
//    return 1 + max(ht_left, ht_right);
//}
//
//void print_all_levels(node*root){
//    if(root == NULL)
//        return;
//
//    int ht = height(root);
//    for(int i=1; i<=ht; i++){
//        print_kth_level(root, i);
//        cout<<endl;
//    }
//    return;
//}
//
//void left_view_bt(node*root){
//    int ht = height(root);
//    int i=1;
//    node*temp = root;
//    while(i<=ht){
//        cout<<temp->data<<" ";
//        temp = temp->left;
//        i++;
//    }
//    return;
//}

void left_view_binary_tree(node*root, int cur_level, int *max_visited){
    if(root==NULL)
        return;

    if(*max_visited < cur_level){
        cout<<root->data<<" ";
        *max_visited = cur_level;
    }
    left_view_binary_tree(root->left, cur_level + 1, max_visited);
    left_view_binary_tree(root->right, cur_level + 1, max_visited);
}

int main(){
    node*root = build_tree_from_level_0rder_input();

//    print_kth_level(root, 1);
//    cout<<endl;
//    print_kth_level(root, 2);
//    cout<<endl;
//    cout<<height(root);
//    cout<<endl;
//    print_all_levels(root);
//    cout<<endl;

//    left_view_bt(root);

    int max_visited = 0;
    left_view_binary_tree(root, 1, &max_visited);

    return 0;
}
