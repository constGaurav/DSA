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

void width(Node* root, int hl, vector<int> &ans){
	if(root == nullptr) return;

	ans[0] = min(ans[0],hl);
	ans[1] = max(ans[1],hl);

	width(root->left, hl-1, ans);
	width(root->right, hl+1, ans);
}

int widthOfBinaryTree(Node* root){
	vector<int> ans(2,0);
	width(root,0,ans);

	return ans[1] - ans[0] + 1;
}

int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);
	



	return 0;
}