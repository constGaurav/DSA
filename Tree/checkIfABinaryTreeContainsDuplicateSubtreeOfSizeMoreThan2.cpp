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

unordered_map<string,int> m;
string solve(Node* root){
	if(!root) return "$";
	string s = "";
	if(!root->left and !root->right){
		s = to_string(root->data);
		return s;
	}

	s += to_string(root->data);
	s += solve(root->left);
	s += solve(root->right);

	m[s]++;
	return s;
}

bool dupSub(Node* root){
	solve(root);
	for(auto a: m){
		if(a.second >= 2) return true;
	}
	return false;
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