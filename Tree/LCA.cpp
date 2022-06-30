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

bool getPath(Node* root, int n, vector<int> &path){
	if(root == NULL) return false;

	path.push_back(root->data);
	if(root->data == n) return true;

	if(getPath(root->left, n, path) || getPath(root->right, n, path))
		return true;

	path.pop_back();
	return false;
}

int LCA(Node* root, int n1, int n2){
	vector<int> path1, path2;

	if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
		return -1;
	}
	int pc = 0;
	for(pc = 0; pc < path1.size() && path2.size(); pc++){
		if(path1[pc]!=path2[pc]) break;
	}

	return path1[pc-1];
}

Node* LCA2(Node* root, int n1, int n2){
	if(root == NULL) return NULL;

	if(root->data == n1 || root->data == n2) return root;

	Node* leftLca = LCA2(root->left, n1, n2);
	Node* rightLca = LCA2(root->right, n1, n2);

	if(leftLca && rightLca) return root;
	if(leftLca) return leftLca;
	return rightLca;
}


int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->left->left = new Node(100);
	root->right->right = new Node(12);

	int lca = LCA(root, 12, 100);
	cout<<lca<<endl;

	Node* lcaNode = LCA2(root, 0, 100);
	if(lcaNode) cout<<lcaNode->data;

    return 0;
}