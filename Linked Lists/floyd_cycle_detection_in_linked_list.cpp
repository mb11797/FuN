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

void cycle_creation(node*&head){


}

bool detect_cycle(node*head){
    node*slow = head;
    node*fast = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){
            cout<<"First meeting at "<<fast->data<<endl;
            cout<<"Cycle detected."<<endl;
            return true;
        }
    }
    return false;
}

bool remove_cycle_from_linked_list(node*&head){
    node*slow = head;
    node*fast = head;

    int flag=0;
    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){
            cout<<"First meeting at "<<fast->data<<endl;
            cout<<"Cycle detected."<<endl;
            slow = head;
            flag = 1;
            break;
        }
    }

    if(flag==1){
        node*prev;
        while(slow!=fast){
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        cout<<"Cycle starting point: "<<slow->data<<endl;
        prev->next=NULL;
        cout<<"Broken the linked list cycle to attain linear linked list"<<endl;
    }

    else if(flag==0)
        return false;

    return true;
}

int main(){
    node*head = NULL;
    cin>>head;
    cout<<endl;
    cout<<head<<endl;

    //create cycle
    node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head->next->next->next;

    bool cycle_mili = detect_cycle(head);
    if(!cycle_mili){
        cout<<"No Cycle present!";
    }


    bool cycle_mili_kya = remove_cycle_from_linked_list(head);
    if(cycle_mili_kya){
        cout<<head<<endl;
    }
    else
        cout<<"No cycle present!"<<endl;


    return 0;
}


