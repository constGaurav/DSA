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


void sumReplacement(Node* root){
	if(root==NULL) return;

	sumReplacement(root->left);
	sumReplacement(root->right);

	if(root->left!=NULL)
		root->data += root->left->data;
	if(root->right!=NULL)
		root->data += root->right->data;
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
	sumReplacement(root);
	preorder(root);
    return 0;
}