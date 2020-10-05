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

Node*merge_2_sorted_lists(Node*&a, Node*&b){
	if(!a)
		return b;
	if(!b)
		return a;

	Node*c;
	if(a->data < b->data){
		c = a;
		c->next = merge_2_sorted_lists(a->next, b);
	}
	else{
		c = b;
		c->next = merge_2_sorted_lists(a, b->next);
	}

	return c;
}


int main() {
	int tc;
	cin>>tc;

	while(tc--){
		int n1;
		cin>>n1;

		Node*a = NULL;
		for(int i=0; i<n1; i++){
			int data;
			cin>>data;
			insert_at_tail(a, data);
		}

		int n2;
		cin>>n2;

		Node*b = NULL;
		for(int i=0; i<n2; i++){
			int data;
			cin>>data;
			insert_at_tail(b, data);
		}

		print(merge_2_sorted_lists(a, b));
	}

	return 0;
}