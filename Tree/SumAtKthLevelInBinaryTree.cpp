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


int sumAtK(Node* root, int k){
	if(root == NULL) return -1;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int level = 0;
	int sum=0;

	while(!q.empty()){
		Node* node = q.front();
		q.pop();
		if(node!=NULL){
			if(level == k){
				sum+=node->data;
			}
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
		else if(!q.empty()){
			q.push(NULL);
			level++;
		}
	}
	return sum;
}


int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);

	cout<<sumAtK(root, 2);
    return 0;
}