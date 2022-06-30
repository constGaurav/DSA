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

void flatten(Node* root){
	if(root == NULL || root->left == NULL && root->right == NULL)
		return;

	if(root->left != NULL) {
		flatten(root->left);
		
		Node* temp = root->right;
		root->right = root->left;
		root->left = NULL;

		Node* t = root->right;
		while(t->right != NULL){
			t = t->right;
		}

		t->right = temp;
	}

	flatten(root->right);
}

int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);

	flatten(root);
    return 0;
}