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

node* merge_sorted_lists(node*a, node*b){
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    node*c;

    if(a->data < b->data){
        c = a;
        c->next = merge_sorted_lists(a->next, b);
    }
    else{
        c = b;
        c->next = merge_sorted_lists(a, b->next);
    }
    return c;
}

int main(){
    node*head1 = NULL;
    node*head2 = NULL;
    cin>>head1>>head2;
    cout<<endl;
    cout<<head1<<endl<<head2<<endl;

    node*merged_list = merge_sorted_lists(head1, head2);
    cout<<merged_list<<endl;

    return 0;
}
