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

int search(vector<int> inorder, int start, int end, int val){
	for(int i=start;i<=end;i++)
		if(inorder[i] == val) return i;
	return -1;
}

Node* BuildTree(vector<int> postorder, vector<int> inorder, int start, int end){
	static int idx = postorder.size()-1;
	if(start > end) return NULL;

	int val = postorder[idx--];
	Node* node = new Node(val);
	if(start == end) return node;

	int pos = search(inorder, start, end, val);
	node->right = BuildTree(postorder,inorder,pos+1,end);
	node->left = BuildTree(postorder,inorder,start,pos-1);

	return node;
}

void postorderPrint(Node* root){
	if(root == NULL) return;
	postorderPrint(root->left);
	postorderPrint(root->right);
	cout<<root->data<<" ";
}
int main() {
	
	// Node* root = new Node(8);
	// root->left = new Node(4);
	// root->right = new Node(10);
	// root->left->left = new Node(2);
	// root->left->right = new Node(5);
	// root->right->left = new Node(9);
	// root->right->right = new Node(12);

	std::vector<int> postorder = {4,2,5,3,1};
	std::vector<int> inorder = {4,2,1,5,3};
	Node* root = BuildTree(postorder,inorder,0,4);


	postorderPrint(root);
    return 0;
}