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

Node* LCA(Node* root, int n1, int n2){
	if(root == NULL) return root;

	if(root->data == n1 || root->data == n2) return root;

	Node* leftLca = LCA(root->left, n1, n2);
	Node* rightLca = LCA(root->right, n1, n2);

	if(leftLca && rightLca) return root;

	if(leftLca) return leftLca;
	return rightLca;
}

int findDist(Node* root, int k, int dist){
	if(root == NULL) return -1;
	if(root->data == k) return dist;
	int left = findDist(root->left, k, dist+1);
	if(left != -1) return left;
	return findDist(root->right, k, dist+1); 
}

int shortestDistance(Node* root, int n1, int n2){
	Node* lca = LCA(root, n1, n2);

	int d1 = findDist(lca, n1, 0);
	int d2 = findDist(lca, n2, 0);

	return d1+d2;
}

int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);

	// if distance is -ve that's means nodes are not present in the tree.
	cout<<shortestDistance(root, 0, 3);
    return 0;
}