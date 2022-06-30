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

vector<int> leftView(Node* root){
	std::vector<int> v;
	if(root == nullptr) return v;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			Node* curr = q.front();
			q.pop();
			if(i==0)
				v.push_back(curr->data);

			if(curr->left != nullptr)
				q.push(curr->left);
			if(curr->right != nullptr)
				q.push(curr->right);
		}
	}
	return v;
}


int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	// root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);

	std::vector<int> v = leftView(root);

	for(int e: v)
		cout<<e<<" ";

    return 0;
}