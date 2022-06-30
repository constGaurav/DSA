#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void preorder(Node* root){
	Node* temp = root;
	if(temp == NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root){
	Node* temp = root;
	if(temp == NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(Node* root){
	Node* temp = root;
	if(temp == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

// Tree Traversal
// An iterative process to print pre order traversal of Binary tree 
void iterativePreorder(Node *root) { 
    if (root == NULL) 
       return; 
    // Create an empty stack and push root to it 
    stack<Node*> nodeStack; 
    nodeStack.push(root); 
  
    while (nodeStack.empty() == false) {  
        Node *node = nodeStack.top(); 
        printf ("%d ", node->data); 
        nodeStack.pop(); 
 
        if (node->right) 
            nodeStack.push(node->right); 
        if (node->left) 
            nodeStack.push(node->left); 
    } 
}

// An iterative process to print post order traversal of Binary tree 
void iterativePostorder(Node* root){
	if(root == NULL) return;

	stack<Node*> s1,s2;
	s1.push(root);

	while(!s1.empty()){
		Node* tmp = s1.top();
		s1.pop();
		s2.push(tmp);
		if(tmp->left)
			s1.push(tmp->left);
		if(tmp->right)
			s1.push(tmp->right);
	}

	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
}

int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);

	preorder(root);
	cout<<"\n";
	inorder(root);
	cout<<"\n";
	postorder(root);

    return 0;
}