#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void print_level_order_traversal_realistic(node*root){
	if(root == NULL)
		return;

	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node*f = q.front();
		q.pop();

		if(f == NULL){
			cout<<endl;
			q.push(NULL);
			if(q.front()==NULL)
				break;
		}
		else{
			cout<<f->data<<" ";
			if(f->left)
				q.push(f->left);
			if(f->right)
				q.push(f->right);
		}
	}
	return;
}

node*BT_from_preorder_and_inorder(int pre[], int in[], int s, int e){
	static int i = 0;
	if(s > e)
		return NULL;
	node*root = new node(pre[i]);
	i++;
	int idx = -1;
	for(int j=0; j<=e; j++){
		if(in[j] == root->data){
			idx = j;
			break;
		}
	}

	root->left = BT_from_preorder_and_inorder(pre, in, s, idx-1);
	root->right = BT_from_preorder_and_inorder(pre, in, idx+1, e);

	return root;
}

class BST_check_utility{
public:
	bool is_BST;
	int size;
	int minm;
	int maxm;

	BST_check_utility(){
		is_BST = true;
		size = 0;
		minm = INT_MAX;
		maxm = INT_MIN;
	}

};

BST_check_utility* largest_BST_in_BT(node*root){
	BST_check_utility* check = new BST_check_utility();
	if(root == NULL){
		return check;
	}

	if(!root->left and !root->right){
		check->is_BST = true;
		check->size = 1;
		check->minm = root->data;
		check->maxm = root->data;
		return check;
	}

	BST_check_utility* check_left = largest_BST_in_BT(root->left);
	BST_check_utility* check_right = largest_BST_in_BT(root->right);

	if(check_left->is_BST and check_right->is_BST and check_left->maxm<=root->data and root->data<=check_right->minm){
		check->is_BST = true;
		check->size = 1 + check_left->size + check_right->size;
		check->minm = root->left != NULL ? check_left->minm : root->data;
		check->maxm = root->right != NULL ? check_right->maxm : root->data;
	}
	else{
		check->is_BST = false;
		check->size = max(check_left->size, check_right->size);

	}
	return check;
}

int main(){
	int n;
	cin>>n;

	int pre[n];
	int in[n];

	for(int i=0; i<n; i++)
		cin>>pre[i];

	for(int i=0; i<n; i++)
		cin>>in[i];

	node*root = BT_from_preorder_and_inorder(pre, in, 0, n-1);
	// print_level_order_traversal_realistic(root);

	BST_check_utility*check = largest_BST_in_BT(root);
	cout<<check->size<<endl;

	return 0;
}