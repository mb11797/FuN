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

void build_list(node*&head, int n){
    int data;
    while(n>0){
        cin>>data;
        insertAtTail(head, data);
        n--;
    }

    return;
}

ostream& operator<<(ostream& os, node*head){
    print(head);
    return os;
}

node*merge_sorted_linked_lists(node*a, node*b){
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    node*c;
    if(a->data < b->data){
        c = a;
        c->next = merge_sorted_linked_lists(a->next, b);
    }
    else{
        c = b;
        c->next = merge_sorted_linked_lists(a, b->next);
    }
    return c;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        node*a = NULL;
        build_list(a, n);

        int m;
        cin>>m;
        node*b = NULL;
        build_list(b, m);

        node*c = merge_sorted_linked_lists(a, b);
        cout<<c;
    }
    return 0;
}


