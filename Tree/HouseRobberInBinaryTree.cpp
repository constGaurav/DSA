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

class housePair {
public:
	int withrob = 0;
	int withoutrob = 0;
};

housePair rob_(Node* root){
	if(root == NULL){
		housePair p;
		return p;
	}

	housePair left = rob_(root->left);
	housePair right = rob_(root->right);	

	housePair myAns;
	myAns.withrob = left.withoutrob + root->data + right.withoutrob;

	myAns.withoutrob = max(left.withrob,left.withoutrob) + max(right.withrob, right.withoutrob);

	return myAns;
}

int rob(Node* root) {
	housePair ans = rob_(root);
	return max(ans.withrob, ans.withoutrob);
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