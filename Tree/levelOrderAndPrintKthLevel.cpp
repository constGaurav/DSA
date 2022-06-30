// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
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

int height(Node* root){
	if(root == NULL) return 0;
	int h = max(height(root->left),height(root->right)) + 1;
	return h;
}

void printKthLevel(Node* root, int k){
	if(root == NULL) return;

	if(k==1) {
		cout<<root->data<<" ";
		return;
	}
	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
	return;
}

void levelOrder(Node* root){ 
	// Time Complexity : O(N^2)
	int h = height(root);
	for(int i=1;i<=h;i++){
		printKthLevel(root, i);
		cout<<endl;
	}
}

// Level Order - O(N)
void levelOrderEfficient(Node* root){
	if(root == NULL) return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* node = q.front();
		cout<<node->data<<" ";
		q.pop();
		if(node->left)
			q.push(node->left);
		if(node->right)
			q.push(node->right);
	}
	return;
}

// Level Order - O(N)
void levelOrderEfficientWithNewLine(Node* root){
	if(root == NULL) return;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node* node = q.front();
		if(node == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else {
			cout<<node->data<<" ";
			q.pop();
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
			}
	}
	return;
}



int main() {
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);

	levelOrder(root);
	cout<<endl;
	levelOrderEfficient(root);
	cout<<endl;
	levelOrderEfficientWithNewLine(root);

    return 0;
}

