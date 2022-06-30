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


int heightOfBT(Node* root){
	if(root == nullptr) return 0;
	int height = max(heightOfBT(root->left) , heightOfBT(root->right)) + 1;
	return height;
}

int diameterOfBT(Node* root){ // T.C. : O(n^2)
	//Number of nodes in the longest path b/w any to leaves.
	if(root == nullptr) return 0;
	int lHeight = heightOfBT(root->left);
	int rHeight = heightOfBT(root->right);
	int currDiameter = lHeight + rHeight;

	int lDiameter = diameterOfBT(root->left);
	int rDiameter = diameterOfBT(root->right);

	return max(currDiameter, max(lDiameter,rDiameter));
}

int diameterOfBT(Node* root, int* height){ // O(n)
	if(root == nullptr){
		*height = 0;
		return 0;
	}
	int lh=0,rh=0;
	int lDiameter = diameterOfBT(root->left, &lh);
	int rDiameter = diameterOfBT(root->right, &rh);

	int currDiameter = lh + rh + 1;
	*height = max(lh,rh) + 1;

	return max(currDiameter, max(lDiameter,rDiameter));
}

int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);
	root->right->left->right = new Node(6);

	cout<<heightOfBT(root);
    return 0;
}