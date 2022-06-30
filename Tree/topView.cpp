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
	Node(int n){
		data = n;
		left = NULL;
		right = NULL;
	}
};

vector<int> topView(Node *root){
    map<int,int> m;
    vector<int> v;
    queue<pair<Node*,int>>q;
    if(!root) return v;
    q.push({root, 0});

    while(!q.empty()){
    	Node* t = q.front().first;
    	int h = q.front().second;
    	q.pop();
    	if(!m[h]) m[h] = t->data;
    	if(t->left) q.push({t->left, h-1});
    	if(t->right) q.push({t->right, h+1});
    }
    for(auto x: m) v.push_back(x.second);
    return v;
}

int main() {


    return 0;
}

