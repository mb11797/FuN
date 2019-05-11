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

int length(node*&head){
    int l=0;
    while(head!=NULL){
        l++;
        head = head->next;
    }
    return l;
}

void buildList(node*&head, int n){
    int data;
    while(n--){
        cin>>data;
        insertAtTail(head, data);
    }
    return;
}

//istream& operator>>(istream &is, node*&head){
//    buildList(head);
//    return is;
//}

ostream& operator<<(ostream &os, node*head){
    print(head);
    return os;
}

void k_append(node*&head, int k){
    node*slow = head;
    node*fast = head;
    int i=0;
    while(i<k){
        fast = fast->next;
        i++;
    }
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return;
}

int main(){
    node*head = NULL;
    int n;
    cin>>n;
    buildList(head, n);

    int k;
    cin>>k;
    k_append(head, k%n);
    cout<<head;
    return 0;
}
