#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int sum = 0;

class Node{
public:
    int data;
    vector<Node*> child;

    Node(int d){
        data = d;
    }
};

Node*build_tree(){
    int data;
    cin>>data;

    Node*temp = new Node(data);
    int n_child;
    cin>>n_child;

    if(n_child<=0)
        return temp;
    else if(n_child>0)
        for(int i=0; i<n_child; i++){
            Node*child = build_tree();
            temp->child.push_back(child);
        }
    return temp;
}
//
//void level_order_traversal_generic_tree(Node*root){
//    if(root==NULL)
//        return;
//
//    queue<Node*> q;
//    q.push(root);
//
//    while(!q.empty()){
//        int n = q.size();
//
//        while(n>0){
//            Node*f = q.front();
//            q.pop();
//            cout<<f->data<<" ";
//
//            for(int i=0; i<f->child.size(); i++){
//                q.push(f->child[i]);
//            }
//            n--;
//        }
//        cout<<endl;
//    }
//}

int sum_at_level_k(Node*root, int k){
    if(root==NULL)
        return 0;

    if(k==0)
        return root->data;

    int sum=0;
    for(int i=0; i<root->child.size(); i++){
        sum += sum_at_level_k(root->child[i], k-1);
    }
    return sum;
}

int main(){
    Node*root = build_tree();
//    level_order_traversal_generic_tree(root);

    int k;
    cin>>k;

    cout<<sum_at_level_k(root, k)<<endl;

    return 0;
}

