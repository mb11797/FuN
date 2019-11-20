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

node* recursive_reverse(node*head){
    if(head->next==NULL || head==NULL)
        return head;
    //rec case
    node*smallHead = recursive_reverse(head->next);
    node*curr = head;
    curr->next->next = curr;
    curr->next = NULL;
    return smallHead;
}

node* midPoint(node*head){
    if(head==NULL or head->next==NULL)
        return head;

    node*slow = head;
    node*fast = head->next;                 //to find out the first middle element
    //if second one is needed then, node*fast = head;

    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    node*head = NULL;
    cin>>head;
    cout<<head<<endl;

    node*newHead = recursive_reverse(head);
    cout<<"Reverse: "<<newHead<<endl;

    cout<<head<<endl;                           //head is not changed but the pointers are reversed now.
    node*mid = midPoint(newHead);
    cout<<mid->data<<endl;
    return 0;
}
