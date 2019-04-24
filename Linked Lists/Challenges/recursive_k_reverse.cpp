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

node*k_reverse(node*head, int n, int k){
    //Base case
    if(head==NULL){
        return head;
    }

    //Recursive case
//    node*smallHead = head;
    node*temp = head;
    int j=0;
    while(j<k){
        temp = temp->next;
        j++;
    }
    node*cn = head;
    node*pn = NULL;
    node*nn;
//    smallHead->next = k_reverse(temp, n-k, k);
    j=0;
    while(j<k){
        nn = cn->next;
        if(j==0){
            cn->next = k_reverse(temp, n-k, k);
        }
        else{
            cn->next = pn;
        }
        pn = cn;
        cn = nn;
        j++;
    }
    return pn;
}

int main(){
    int n, k;
    cin>>n>>k;

    node*head = NULL;
    build_list(head, n);
    node*nHead = k_reverse(head, n, k);
    cout<<nHead<<endl;
    return 0;
}
