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

class pairs{
public:
	int forwardSlop = -1;
	int backwardSlop = -1;
	int maxLen = 0;
};

pairs longestZigZag_(Node* root) {
	if(root == NULL) {
		pairs p;
		return p;
	}

	pairs left = longestZigZag_(root->left);
	pairs right = longestZigZag_(root->right);

	pairs myAns;
	myAns.maxLen = max(max(left.maxLen,right.maxLen),max(left.backwardSlop, right.forwardSlop)+1);

	myAns.forwardSlop = left.backwardSlop + 1;
	myAns.backwardSlop = right.forwardSlop + 1;
	return myAns; 
}

int longestZigZag(Node* root){
	pairs ans = longestZigZag_(root);
	return ans.maxLen;
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