#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node*&head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }

    node*n = new node(data);
    n->next = head;
    head = n;
    return;
}

void insertAtTail(node*&head, int data){
    if(head==NULL){
        insertAtHead(head, data);
        return;
    }

    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    node*n = new node(data);
    tail->next = n;
    return;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

void build_list(node*&head){
    int data;
    cin>>data;
    while(data != -1){
        insertAtTail(head, data);
        cin>>data;
    }

    return;
}

istream& operator>>(istream& is, node*&head){
    build_list(head);
    return is;
}

ostream& operator<<(ostream& os, node*head){
    print(head);
    return os;
}

node*kth_node_from_last(node*head, int k){
    node*slow = head;
    node*fast = head;

    while(k--){
        fast = fast->next;
    }

    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(){
    node*head = NULL;
    cin>>head;

    int k;
    cin>>k;
    cout<<kth_node_from_last(head, k)->data;

    return 0;
}


