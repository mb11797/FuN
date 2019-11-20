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

int length(node*head){
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

int check_intersection(node*head1, node*head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int intersectn_pt;
    int flag=0;
    if(l1>l2){
        int diff = l1-l2;
        while(diff--){
            head1 = head1->next;
        }
        while(head1 && head2){
            if(head1->data == head2->data){
                flag++;
                if(flag==1){
                    intersectn_pt = head1->data;
                }
            }
            else{
                flag = 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        if(flag!=0){
            return intersectn_pt;
        }
        else{
            return -1;
        }
    }
    else{
        int diff = l2-l1;
        while(diff--){
            head2 = head2->next;
        }
        while(head1 && head2){
            if(head1->data == head2->data){
                flag++;
                if(flag==1){
                    intersectn_pt = head1->data;
                }
            }
            else{
                flag = 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        if(flag!=0){
            return intersectn_pt;
        }
        else{
            return -1;
        }
    }
}

int main(){
    node*head1 = NULL;
    cin>>head1;
    node*head2 = NULL;
    cin>>head2;

    int intersectn_pt = check_intersection(head1, head2);
    cout<<intersectn_pt<<endl;
    return 0;
}
