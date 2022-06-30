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

int cam = 0;
    
int minCameraCover_(Node* root) {
    if(root == NULL) return 1;
    
    int lchild = minCameraCover_(root->left);
    int rchild = minCameraCover_(root->right);
    
    if(lchild == -1 || rchild == -1){
        cam++;
        return 0;
    }
    
    if(lchild == 0 || rchild == 0)
        return 1;
    
    return -1;
}

int minCameraCover(Node* root){
    int k = minCameraCover_(root);
    if(k == -1) cam++;
    return cam;
}


int main() {
	
	// Node* root = new Node(8);
	// root->left = new Node(4);
	// root->right = new Node(10);
	// root->left->left = new Node(2);
	// root->left->right = new Node(5);
	// root->right->left = new Node(9);
	// root->right->right = new Node(12);
	int preorder[] = {1,2,3,4,5,6};
	int inorder[] = {3,2,4,1,5,6};
	Node* root = buildTree(preorder, inorder, 0, 0);
	inorderPrint(root);
    return 0;
}