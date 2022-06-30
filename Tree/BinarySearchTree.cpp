// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(){}
	Node(int n){
		this->data = n;
	}
};

Node* insertInBST(Node* root, int data){
	//Base case
	if(root == NULL){
		return new Node(data);
	}
	//Rec Case
	if(data <= root->data){
		
	}
	return root;
}

Node* buildTree(){
	// Read a list of numbers till -1 and also these numbers will be inserted into BST.
	int d; cin>>d;
	Node* root = NULL;
	while(d!=-1){
		root = insertInBST(root, d);
		cin>>d;
	}
	return root;
}

int main() {


    return 0;
}

