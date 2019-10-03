#include<iostream>
using namespace std;

#define ll long long
ll cycle = 0;

class node{
public:
    ll data;
    node*next;

    node(ll d){
        data = d;
        next = NULL;
    }
};

void add_to_back(node*&head, node*node_to_add){
    int flag = 0;
    if(head == NULL){
        head = node_to_add;
        return;
    }

    node*temp = head;

    node*cycle_pt;
    while(temp->next != NULL){
        if(temp->data == node_to_add->data){
            cycle_pt = temp;
            flag = 1;
        }
        temp = temp->next;
    }
    if(flag == 0){
        temp->next = node_to_add;
    }
    else{
        temp->next = cycle_pt;
        cycle = 1;
    }
    return;
}

node*take_input(){
    int data;

    node*head = NULL;

    while(cin>>data && data != -1){
        if(cycle == 1){
            break;
        }
        node*node_to_add = new node(data);
        add_to_back(head, node_to_add);
    }

    if(cycle == 1 && data != -1){
        while(cin>>data && data != -1);
    }
    return head;
}

void print(node*head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

bool detect_cycle(node*head){
    node*slow = head;
    node*fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
//    cout<<0<<endl;
    return false;
}

void remove_cycle(node*&head){
    node*slow = head;
    node*fast = head;
    while(fast->next != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }

    if(slow == fast && fast == head){
        node*prev = head->next;
        while(prev->next != head){
            prev = prev->next;
        }
        prev->next = NULL;
        return;
    }

    slow = head;

    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
    return;
}

int main(){
    node*head = take_input();
//    print(head);

    if(detect_cycle(head)){
//        cout<<1<<endl;
        remove_cycle(head);
        print(head);
    }
    else{
        cout<<2<<endl;
        print(head);
    }
    return 0;
}
