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

void k_reverse(node*&head, int n, int k){
    node*temp = head;
    int iter = n/k;
    int i=0;
    while(i < iter){
        node*p = NULL;
        node*c = temp;
        node*n;
        node*tHead = temp;
        int j = 0;
        while(j<k){
            temp = temp->next;
            j++;
        }
        j = 0;
        while(j<k){
            n = c->next;
            if(j==0)
                c->next = temp;
            else
                c->next = p;
            p = c;
            c = n;
            if(j==k-1){
                tHead = p;
            }
            j++;
        }
        if(i == 0){
            head = p;
        }
        i++;
    }
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;

    node*head = NULL;
    build_list(head, n);

    k_reverse(head, n, k);
    cout<<head;
    return 0;
}
