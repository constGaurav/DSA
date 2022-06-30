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

void inorderPrint(Node* root){
	Node* temp = root;
	if(temp == NULL) return;
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}

//Apna College Video - Nodes at Distance K in Binary Tree

//Case 1 : Node's Subtree
void printSubtreeNodes(Node* root, int k){
	if(root == NULL || k<0) return;

	if(k==0){
		cout<<root->data<<" "; return;
	}

	printSubtreeNodes(root->left, k-1);
	printSubtreeNodes(root->right, k-1);
}

//Case 2: Node's Ancestors
int printNodesAtK(Node* root, Node* target, int k){
	if(root == NULL) return -1;
	if(root == target){
		printSubtreeNodes(root, k); return 0;
	}

	int dl = printNodesAtK(root->left, target, k);
	if(dl!=-1){
		if(dl+1 == k){
			cout<<root->data<<" ";
		} else {
			printSubtreeNodes(root->right, k-dl-2);
		}
		return 1+dl;
	}

	int dr = printNodesAtK(root->right, target, k);
	if(dr!=-1){
		if(dr+1 == k){
			cout<<root->data<<" ";
		} else {
			printSubtreeNodes(root->left, k-dr-2);
		}
		return 1+dr;
	}

	return -1;
}



int main() {

	Node* root1 = new Node(1);
	root1->left = new Node(2);
	root1->right = new Node(3);
	root1->left->left = new Node(4);

	printNodesAtK(root1, root1->left, 1);
    return 0;
}