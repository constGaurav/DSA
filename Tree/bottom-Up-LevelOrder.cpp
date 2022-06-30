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


vector<vector<int>> levelOrderBottom(Node* root) {
	vector<vector<int>> ans;
	if(root == NULL) return ans;
	
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int size = q.size();
		vector<int> level;
		while(size--){
			root = q.front();
			q.pop();
			level.push_back(root->data);
			if(root->left) q.push(root->left);
			if(root->right) q.push(root->right);
		}
		ans.push_back(level);
	}
	reverse(ans.begin(),ans.end());
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

	vector<vector<int>> ans= levelOrderBottom(root);

	for(auto v: ans){
		for(int a: v)
			cout<<a<<" ";
		cout<<endl;
	}

    return 0;
}

