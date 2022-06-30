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

int search(int inorder[], int start, int end, int curr){
	for(int i=start; i<=end; i++){
		if(inorder[i] == curr) return i;
	}
	return -1;
}


Node* buildTree(int preorder[], int inorder[], int start, int end){
	static int idx = 0;
	if(start>end) return NULL;

	int curr = preorder[idx++];
	Node* node = new Node(curr);
	if(start == end) return node;

	int pos = search(inorder, start, end, curr);
	node->left = buildTree(preorder, inorder, start, pos-1);
	node->right = buildTree(preorder, inorder, pos+1, end);
	return node;
}

void inorderPrint(Node* root){
	Node* temp = root;
	if(temp == NULL) return;
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}

int main() {
	
	// Node* root = new Node(8);
	// root->left = new Node(4);
	// root->right = new Node(10);
	// root->left->left = new Node(2);
	// root->left->right = new Node(5);
	// root->right->left = new Node(9);
	// root->right->right = new Node(12);
	int preorder[] = {1,2,3,4,5,6};
	int inorder[] = {3,2,4,1,5,6};
	Node* root = buildTree(preorder, inorder, 0, 0);
	inorderPrint(root);
    return 0;
}