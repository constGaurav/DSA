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

void preorder(Node* root){
	Node* temp = root;
	if(temp == NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int height(Node* root){
	if(root == NULL) return 0;
	int h = 1 + max(height(root->left),height(root->right));
	return h;
}

int diameter(Node* root){ // Time Compke
	if(root == NULL) return 0;

	int h1 = height(root->left);
	int h2 = height(root->right);
	int d1 = h1+h2;
	int d2 = diameter(root->left);
	int d3 = diameter(root->right);

	return max(d1,max(d2,d3));
}


//Fast-Diameter -- O(n)
pair<int, int> fastDiameter(Node* root){
	pair<int, int> p;
	if(root == NULL){
		p.first = p.second = 0;
		return p;
	}
	pair<int, int> left = fastDiameter(root->left);
	pair<int, int> right = fastDiameter(root->right);
	p.first = max(left.first,right.first) + 1;
	p.second = max(left.first+right.first, max(left.second, right.second));
	return p;
} 


int main() {
	
	Node* root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(10);
	root->left->left = new Node(2);
	root->left->left->left = new Node(1);
	root->left->right = new Node(5);
	root->right->left = new Node(9);
	root->right->right = new Node(12);

	cout<<fastDiameter(root).second;

    return 0;
}