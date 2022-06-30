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


// int height(Node* root){
// 	if(root == NULL) return 0;
// 	int h = 1 + max(height(root->left),height(root->right));
// 	return h;
// }

// bool isBalanced(Node* root){ //O(n^2)
// 	if(root == nullptr) return true;
// 	if(!isBalanced(root->left) || !isBalanced(root->right)) return false;
// 	if(abs(height(root->left) - height(root->right)) <= 1) return true;
// 	return false;
// }

bool isBalanced(Node* root, int* height){
	if(root == NULL) return true;

	int lh=0,rh=0;

	if(!isBalanced(root->left, &lh) || !isBalanced(root->right, &rh))
		return false;

	*height = max(lh, rh) + 1;
	if(abs(lh-rh) <= 1) return true;
	else return false;
}


int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->left->left = new Node(2);
	root->left->left->left = new Node(1);
	root->right = new Node(10);
	root->right->right = new Node(5);
	root->right->right->right = new Node(9);
	// root->right->right = new Node(12);

	cout<<isBalanced(root);

    return 0;
}