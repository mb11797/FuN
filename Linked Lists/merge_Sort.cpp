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

node*midPoint(node*head){
    if(head==NULL or head->next==NULL)
        return head;

    node*slow = head;
    node*fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

node*merge_sort(node*head){
    //base case
    if(head==NULL or head->next==NULL)
        return head;

    //rec case
    //1.Mid Point
    node*mid = midPoint(head);

    node*a = head;
    node*b = mid->next;
    mid->next = NULL;

    //2.Recursively sort
    a = merge_sort(a);
    b = merge_sort(b);

    //3.Merge a and b
    node*c = merge_sorted_lists(a, b);
    return c;
}

int main(){
    node*head = NULL;
    cin>>head;
    cout<<endl;
    cout<<head<<endl;

    cout<<"Sorted List: "<<merge_sort(head)<<endl;
    return 0;
}

