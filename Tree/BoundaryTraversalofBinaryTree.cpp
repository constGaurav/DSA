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
void leftTree(Node *root, vector<int> &ans){
 	if(root == NULL) return;
 	if(root->left){
 		ans.push_back(root->data);
 		leftTree(root->left, ans);
 	}
 	else if(root->right){
 		ans.push_back(root->data);
 		leftTree(root->right, ans);
 	}
 }
 
 void leaf(Node* root, vector<int> &ans){
 	if(root == NULL) return;
 	leaf(root->left,ans);
 	if(!root->left && !root->right)
 		ans.push_back(root->data);
 	leaf(root->right, ans);
 }
 
 void rightTree(Node *root, vector<int> &ans){
 	if(root == NULL) return;
 	if(root->right){
 		rightTree(root->right, ans);
 		ans.push_back(root->data);
 	}
 	else if(root->left){
 		rightTree(root->left, ans);
 		ans.push_back(root->data);
 	}
 }
vector <int> printBoundary(Node *root){   
	vector<int> ans;
	ans.push_back(root->data);
   leftTree(root->left, ans);
   leaf(root, ans);
   rightTree(root->right, ans);
   ans.pop_back();
   return ans;
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

