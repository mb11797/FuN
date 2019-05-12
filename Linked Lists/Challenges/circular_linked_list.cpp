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
    tail->next = new node(data);
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

int length(node*head){
    int l=0;
    while(head!=NULL){
        l++;
        head = head->next;
    }
    return l;
}

void buildList(node*&head){
    int data;
    cin>>data;
    while(data != -1){
        insertAtTail(head, data);
        cin>>data;
    }
    return;
}

istream& operator>>(istream &is, node*&head){
    buildList(head);
    return is;
}

ostream& operator<<(ostream &os, node*head){
    print(head);
    return os;
}


int main(){
    node*head = NULL;
    cin>>head;
    cout<<head;

    return 0;
}