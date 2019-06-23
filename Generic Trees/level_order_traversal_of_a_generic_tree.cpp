#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    vector<Node*> child;

    Node(int d){
        data = d;
    }
};

Node*newNode(int d){
    Node*temp = new Node(d);
    return temp;
}

void level_order_traversal(Node*root){
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();

        while(n>0){
            Node*f = q.front();
            q.pop();
            cout<<f->data<<" ";

            for(int i=0; i<f->child.size(); i++){
                q.push(f->child[i]);
            }
            n--;
        }
        cout<<endl;
    }
    return;
}


int main(){
    Node*root = new Node(10);
    root->child.push_back(new Node(2));
    root->child.push_back(new Node(34));
    root->child.push_back(new Node(56));
    root->child.push_back(new Node(100));
    root->child[0]->child.push_back(new Node(77));
    root->child[0]->child.push_back(new Node(88));
    root->child[2]->child.push_back(new Node(1));
    root->child[3]->child.push_back(new Node(7));
    root->child[3]->child.push_back(new Node(8));
    root->child[3]->child.push_back(new Node(9));

    level_order_traversal(root);
    return 0;
}
