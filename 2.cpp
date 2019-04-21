#include<bits/stdc++.h>
using namespace std ;

struct Node
{
    int data ;
    struct Node * left, * right ;
};

int maxLevelSum(struct Node * root)
{
    if (root == NULL)
        return 0;

    int result = root->data;

    queue<Node*> q;
    q.push(root);
    int level=0;
    while (!q.empty())
    {
        int count = q.size() ;

        int sum = 0;
        while (count--)
        {
            Node *temp = q.front();
            q.pop();

            sum = sum + temp->data;
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }

        result = max(sum, result);
        level++;
    }

    return level;
}

struct Node * newNode(int data)
{
    struct Node * node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* insertLevelOrder(int arr[], Node* root,
                       int i, int n)
{
    if (i < n)
    {
        Node* temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr,
                   root->left, 2 * i, n);

        // insert right child
        root->right = insertLevelOrder(arr,
                  root->right, 2 * i + 1, n);
    }
    return root;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    struct Node *root = insertLevelOrder(A, root, 0, A.size());
    cout << "Maximum level sum is "
         << maxLevelSum(root) << endl;
}

int main()
{
    struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left  = newNode(6);
    root->right->right->right  = newNode(7);

    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7    */
    cout << "Maximum level sum is "
         << maxLevelSum(root) << endl;
    return 0;
}
