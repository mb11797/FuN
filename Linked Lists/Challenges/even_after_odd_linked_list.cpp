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

void buildList(node*&head){
    int n;
    cin>>n;
    int data;
    while(n--){
        cin>>data;
        insertAtTail(head, data);
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

void even_after_odd(node*&head){
    node*oHead = NULL;
    node*oTail = NULL;
    node*eHead = NULL;
    node*eTail = NULL;

    node*curr = head;

    while(curr!=NULL){
        if(curr->data % 2 != 0){
            if(oHead==NULL){
                oHead = oTail = curr;
            }
            else{
                oTail->next = curr;
                oTail = curr;
            }
        }
        else{
            if(eHead==NULL){
                eHead = eTail = curr;
            }
            else{
                eTail->next = curr;
                eTail = curr;
            }
        }
        curr = curr->next;
    }
    if(eTail!=NULL){
        eTail->next = NULL;
    }
    else{
        if(oTail!=NULL){
            oTail->next = NULL;
            head = oHead;
            return;
        }
    }
    if(oTail!=NULL){
        oTail->next = eHead;
    }
    else{
        head = eHead;
        return;
    }
    head = oHead;
    return;
}

int main(){
    node*head = NULL;
    cin>>head;

    even_after_odd(head);
    cout<<head;

    return 0;
}
