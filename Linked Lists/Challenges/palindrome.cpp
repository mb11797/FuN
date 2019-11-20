#include<iostream>
#include<stack>
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
    while(n--){
        cin>>data;
        insertAtTail(head, data);
    }
    return;
}

//istream& operator>>(istream& is, node*&head){
//    build_list(head);
//    return is;
//}

ostream& operator<<(ostream& os, node*head){
    print(head);
    return os;
}

node*reversed(node*head){
    node*prev = NULL;
    node*curr = head;
    node*nxt;
    while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

bool check_palindrome(node*head, int n){
    node*slow = head;
    node*fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    slow = reversed(slow);
    fast = head;

    while(slow!=NULL){
        if(slow->data != fast->data){
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    node*head = NULL;
    build_list(head, n);

    bool palindromeHai = check_palindrome(head, n);
    if(palindromeHai){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
