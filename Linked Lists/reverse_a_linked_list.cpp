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

void reverse(node*&head){
    node*prev = NULL;
    node* curr = head;
    node *nxt;

    while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}

int main(){
    node*head = NULL;
    cin>>head;
    cout<<head<<endl;

    reverse(head);
    cout<<"Reverse: "<<head<<endl;

    return 0;
}
