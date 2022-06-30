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

vector<int> diagonal(Node *root){
   vector<int> v;
   if(root == NULL) return v;
   queue<Node*> q;
   q.push(root);

   while(!q.empty()){
   	Node* t = q.front();
 	q.pop();
   	
   	while(t){
   		v.push_back(t->right->data);
   		if(t->left) q.push(t->left);
   		t = t->right;
   	}
   return v;
}

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

