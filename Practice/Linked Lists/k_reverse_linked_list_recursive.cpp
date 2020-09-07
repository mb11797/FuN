#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};

void insert_at_head(Node*&head, int data){
	Node*n = new Node(data);
	n->next = head;
	head = n;
	return;
}

void insert_at_tail(Node*&head, int data){
	if(!head){
		head = new Node(data);
		return;
	}

	Node*tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}

	tail->next = new Node(data);
	return;
}

void print(Node*head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	return;
}

Node* k_reverse_linked_list_recursive(Node*&head, int n, int k){
	if(head == NULL ||head->next == NULL || n < k){
		return head;
	}

	Node*temp = head;
	for(int i=0; i<k; i++){
		temp = temp->next;
	}

	Node*curr = head;
	Node*prev = NULL;
	Node*nxt;

	int i=0;
	while(i < k){
		nxt = curr->next;
		if(i == 0)
			curr->next = k_reverse_linked_list_recursive(temp, n-k, k);
		else
			curr->next = prev;		
		prev = curr;
		curr = nxt;
		i++;
	}

	head = prev;
	return head;
}

int main() {
	int n, k;
	cin>>n>>k;

	Node*head = NULL;

	for(int i=0; i<n; i++){
		int data;
		cin>>data;
		insert_at_tail(head, data);
	}

	head = k_reverse_linked_list_recursive(head, n, k);

	print(head);

	return 0;
}