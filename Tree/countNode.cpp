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


int countNodes(Node* root){
	if(root == nullptr) return 0;

	int count = countNodes(root->left) + countNodes(root->right) + 1;

	return count;
}

int sumOfNodes(Node* root){
	if(root == nullptr) return 0;

	int sum = root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
	return sum;
}


int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);

	cout<<countNodes(root)<<endl;;
	cout<<sumOfNodes(root)<<endl;;
    return 0;
}