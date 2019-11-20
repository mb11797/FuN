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
    node*n = new node(data);
    n->next = head;
    head = n;
}

void insertAtTail(node*&head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }

    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

int length(node*head){
    int len=0;
    while(head!=NULL){
        head = head->next;
        len++;
    }
    return len;
}

void print(node*head){
//    node*temp = head;
//    while(temp!=NULL){
//        cout<<temp->data<<"->";
//        temp = temp->next;
//    }
//OR
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}

void buildList(node*&head){
    int data;
    cin>>data;

    while(data != -1){
        insertAtTail(head, data);
        cin>>data;
    }
}

istream& operator>>(istream &is, node*&head){
    buildList(head);
    return is;
}

ostream& operator<<(ostream& os, node*head){
    print(head);
    return os;
}

node* kth_node_from_last(node*head, int k){
    if(head==NULL or k>length(head))
        return head;

    node*slow = head;
    node*fast = head;

    for(int i=0; i<k; i++){
        fast = fast->next;
    }

    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    node*head = NULL;
    cin>>head;
    cout<<head<<endl;

    int k;
    cin>>k;
    node*kth_node_last = kth_node_from_last(head, k);
    cout<<kth_node_last->data<<endl;

    return 0;
}

