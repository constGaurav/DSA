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

int f;
void solve(Node* root, int h, int &ma){
	if(!root) return;
	if(f == 0) return;
	if(!root->left and !root->right){
		if(ma == -1) ma = h;
		else {
			if(h!=ma)
				f = 0;
		}
		return;
	}
	solve(root->left,h+1,ma);
	solve(root->right,h+1,ma);
}

bool LeafAtSameLevel(Node *root){
    f = 1;
    int ma = -1;
    solve(root, 0, ma);
    return f;
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