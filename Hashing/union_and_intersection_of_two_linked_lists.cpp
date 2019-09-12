#include<iostream>
#include<unordered_map>
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
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    node*n = new node(data);
    tail->next = n;
    return;
}

void print(node*head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
    return;
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

void print_Union_of_LLs(node*head1, node*head2){
    unordered_map<int, int> my_map;
    while(head1 != NULL){
        my_map[head1->data] = head1->data;
        head1 = head1->next;
    }

    while(head2!= NULL){
        my_map[head2->data] = head2->data;
        head2 = head2->next;
    }

    for(auto node: my_map){
        cout<<node.first<<" ";
    }
    cout<<endl;
    return;
}

void print_Intersection_of_LLs(node*head1, node*head2){
    unordered_map<int, int> my_map;

    while(head1 != NULL){
        my_map[head1->data] = head1->data;
        head1 = head1->next;
    }

    while(head2 != NULL){
        if(my_map.count(head2->data)){
            cout<<head2->data<<" ";
        }
        head2 = head2->next;
    }
    cout<<endl;
    return;
}

int main(){
    node*head1 = NULL;
    buildList(head1);
    print(head1);

    node*head2 = NULL;
    buildList(head2);
    print(head2);

    cout<<endl;
    cout<<"Union: ";
    print_Union_of_LLs(head1, head2);

    cout<<endl;
    cout<<"Intersection: ";
    print_Intersection_of_LLs(head1, head2);

    return 0;
}
