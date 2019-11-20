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
    if(head == NULL){
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
    tail->next = new node(data);
    return;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
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

istream&operator>>(istream &is, node*&head){
    buildList(head);
    return is;
}

ostream&operator<<(ostream &os, node*head){
    print(head);
    return os;
}

bool find_cycle(node*head){
    node*temp = head;

    unordered_map<node*, bool>m;

    while(temp != NULL){
        if(m[temp]==true){
            cout<<"Cycle found"<<endl;
            return true;
        }

        m[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main(){
    node*head = NULL;
    cin>>head;
    cout<<head<<endl;

    //creating cycle
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = head->next->next->next;

    bool cycle_mili = find_cycle(head);
    if(!cycle_mili)
        cout<<"No cycle present!!!"<<endl;

    return 0;
}
