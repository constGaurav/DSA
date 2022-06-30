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

Node* buildTreeFromArray(int *a, int s, int e){
	//Base Case
	if(s>e) return NULL;

	//Recursive Case
	int mid = (s+e)/2;
	Node* root = new Node(a[mid]);
	root->left = buildTreeFromArray(a,s,mid-1);
	root->right = buildTreeFromArray(a,mid+1,e);
	return root; 
}

int main() {

	int a[] = {1,2,3,4,5,6,7};
	int n = 7;
	Node* root = buildTreeFromArray(a,0,n-1);
	preorder(root);
 
    return 0;
}