#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    //constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

//class LinkedList{
//    node*head;
//    node*tail;
//public:
//    LinkedList(){
//        head = NULL;
//        tail = NULL;
//    }
//
//    void insert(){
//
//    }
//};

//Passing a pointer variable by reference
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
    int len = 0;
    while(head!=NULL){
        head = head->next;
        len++;
    }
    return len;
}

void insertInMiddle(node*&head, int data, int p){

    if(head==NULL || p==0){
        insertAtHead(head, data);
    }
    else if(p>length(head)){
        insertAtTail(head, data);
    }
    else{
        node*temp = head;
        int jump = 1;
        while(jump<=p-1){
            temp = temp->next;
            jump++;
        }

        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
    return;
}

void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTail(node*&head){
    node*prev = NULL;
    node*temp = head;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    return;
}

void deleteInMiddle(node*&head, int p){
    if(head==NULL)
        return;
    if(p==0){
        deleteAtHead(head);
    }
    else if(p>length(head)){
        deleteAtTail(head);
    }
    else{
        int jump = 1;
        node*prev = NULL;
        node*temp = head;
        while(jump<=p-1){
            prev = temp;
            temp = temp->next;
            jump++;
        }
        prev->next = temp->next;
        delete temp;
        return;
    }
    return;
}

bool searchRecursive(node*head, int key){
    //base case
    if(head==NULL){
        return false;
    }
    //rec case
    if(head->data==key)
        return true;
    searchRecursive(head->next, key);
}

bool searchIterative(node*head, int key){
    while(head!=NULL){
        if(head->data==key)
            return true;
        head = head->next;
    }
    return false;
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

int main(){
    node*head = NULL;
    insertAtHead(head, 6);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    print(head);
    cout<<endl;

    insertInMiddle(head, 2, 0);
    insertAtTail(head, 7);
    insertInMiddle(head, 5, 3);
    insertInMiddle(head, 8, 9);
    print(head);
    cout<<endl;

    deleteAtHead(head);
    print(head);
    cout<<endl;
    deleteAtTail(head);
    print(head);
    cout<<endl;

    deleteInMiddle(head, 2);
    print(head);
    cout<<endl;
    deleteInMiddle(head, 0);
    print(head);
    cout<<endl;
    deleteInMiddle(head, 7);
    print(head);
    cout<<endl;

    if(searchRecursive(head, 6)){
        cout<<"Element is present."<<endl;
    }
    else
        cout<<"Not present"<<endl;

    if(searchIterative(head, 189)){
        cout<<"Element is present."<<endl;
    }
    else
        cout<<"Not present"<<endl;

    return 0;
}
