// @MrGaurav
#include <bits/stdc++.h>
#define GAURAV_CHAUDHARY ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

// Node 
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
    Node(){}
};

// Build Tree
Node* createTree(){
    int d; cin>>d;
    if(d == -1) 
        return NULL;
    Node* root = new Node(d);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void inorder(Node* node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void postOrder(Node* node){
    if(node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<" ";
}

void levelOrder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left) 
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    } 
}

vector<int> preOrderIT(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* node = s.top(); s.pop();
        ans.push_back(node->data);
        if(node->right)
            s.push(node->right);
        if(node->left)
            s.push(node->left);
    }
    return ans;
}

vector<int> inorderIT(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node*> s;
    Node* node = root;

    while(true){
        if(node != NULL){
            s.push(node);
            node = node->left;
        } else {
            if(s.empty()) break;
            node = s.top(); s.pop();
            ans.push_back(node->data);
            node=node->right;
        }
    }
    return ans;
}

vector<int> postOrderIT(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node*> s1,s2;
    s1.push(root);

    while(!s1.empty()){
        Node* node = s1.top(); s1.pop();
        s2.push(node);

        if(node->left)
            s1.push(node->left);
        if(node->right)
            s1.push(node->right);
    }
    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}

vector<int> topView(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    
    while(!q.empty()){
        auto p = q.front(); q.pop();
        Node* node = p.first;
        int line = p.second;
        
        if(mp.find(line) == mp.end()) mp[line] = node->data;
        if(node->left) q.push({node->left,line-1});
        if(node->right) q.push({node->right,line+1});
    }
    
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}

vector <int> bottomView(Node *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto p = q.front(); q.pop();
        Node* node = p.first;
        int line = p.second;
        mp[line] = node->data;
        if(node->left) q.push({node->left,line-1});
        if(node->right) q.push({node->right,line+1});
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}

void leftView(Node* root, int level, vector<int> &ans){
    if(root == NULL)
        return;
    if(ans.size() == level){
        ans.push_back(root->data);
    }
    leftView(root->left,level+1,ans);
    leftView(root->right,level+1,ans);
}

void rightView(Node* root, int level, vector<int> &ans){
    if(root == NULL)
        return;
    if(ans.size() == level){
        ans.push_back(root->data);
    }
    rightView(root->right,level+1,ans);
    rightView(root->left,level+1,ans);
}

bool getPath(Node* root, vector<int> &ans, int x){
    if(root == NULL) return false;
    ans.push_back(root->data);
    
    if(root->data == x)
        return true;

    if(getPath(root->left,ans,x) || getPath(root->right,ans,x)){
        return true;
    }

    ans.pop_back();
    return false;
}

Node* lca(Node* root, Node* p, Node* q){
    if(root == NULL || root == p || root == q){
        return root;
    }

    Node* left = lca(root->left,p,q);
    Node* right = lca(root->right,p,q);

    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    else return root;
}

int widthOfBinaryTree(Node* root) {
    if(root == NULL) return 0;
    int maxWidth = 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        int sz = q.size();
        int x = q.front().second;
        int first,last;
        for(int i=0;i<sz;i++){
            int curr = q.front().second-x;
            Node* node = q.front().first;
            q.pop();
            if(i==0) first = curr;
            if(i==sz-1) last = curr;
            if(node->left) 
                q.push({node->left,2*curr+1});
            if(node->right) 
                q.push({node->right,2*curr+2}); 
        }
        maxWidth = max(maxWidth,last-first+1);
    }       
    return maxWidth;
}

void childSumProperty(Node* root) {
   if(root == NULL) return;  
   int child = 0;
   if(root->left) {
       child += root->left->data;  
   }
   if(root->right) {
       child += root->right->data;  
   }
   
   if(child >= root->data) root->data = child;  
   else {
       if(root->left) root->left->data = root->data;  
       else if(root->right) root->right->data = root->data;  
   }
   
   childSumProperty(root->left);  
   childSumProperty(root->right);  
   
   int tot = 0;  
   if(root->left) tot += root->left->data;  
   if(root->right) tot+= root->right->data;  
   if(root->left or root->right) root->data = tot;  
}

void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
    queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()) { 
        TreeNode* current = queue.front(); 
        queue.pop();
        if(current->left) {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if(current->right) {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
    markParents(root, parent_track, target); 
    
    unordered_map<TreeNode*, bool> visited; 
    queue<TreeNode*> queue;
    queue.push(target);
    visited[target] = true;
    int curr_level = 0;
    while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
        int size = queue.size();
        if(curr_level++ == k) break;
        for(int i=0; i<size; i++) {
            TreeNode* current = queue.front(); queue.pop();
            if(current->left && !visited[current->left]) {
                queue.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]) {
                queue.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]) {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while(!queue.empty()) {
        TreeNode* current = queue.front(); queue.pop();
        result.push_back(current->val);
    }
    return result;
}

 
int findMaxDistance(map<Node*, Node*> &mpp, Node* target) {
    queue<Node*> q; 
    q.push(target); 
    map<Node*,int> vis; 
    vis[target] = 1;
    int maxi = 0; 
    while(!q.empty()) {
        int sz = q.size();
        int fl = 0; 
        for(int i = 0;i<sz;i++) {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]) {
                fl = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            if(node->right && !vis[node->right]) {
                fl = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            
            if(mpp[node] && !vis[mpp[node]]) {
                fl = 1; 
                vis[mpp[node]] = 1; 
                q.push(mpp[node]); 
            } 
        }
        if(fl) maxi++; 
    }
    return maxi; 
}
Node* bfsToMapParents(Node* root, 
                                     map<Node*, Node*> &mpp, int start) {
    queue<Node*> q; 
    q.push(root); 
    Node* res; 
    while(!q.empty()) {
        Node* node = q.front(); 
        if(node->data == start) res = node; 
        q.pop(); 
        if(node->left) {
            mpp[node->left] = node; 
            q.push(node->left); 
        }
        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right); 
        }
    }
    return res; 
}
int timeToBurnTree(Node* root, int start)
{
    map<Node*, Node*> mpp; 
    Node* target = bfsToMapParents(root, mpp, start); 
    int maxi = findMaxDistance(mpp, target); 
    return maxi; 
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> inMap; 

    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

vector<int> Morris_Inorder_Traversal(Node* root){
    vector<int> ans; 
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->left;
        }
        else {
            Node* prev = curr->left;
            while(prev->right and prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            } 
            else {
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}
TreeNode* deleteNode(TreeNode* root, int key){
    if(root == NULL) return NULL;
    else if(root->val > key){
        root->left = deleteNode(root->left,key);
        return root;
    }
    else if(root->val == key){
        // Found the Node
        // Case 1. Zero Childs;
        if(root->left == NULL and root->right == NULL){
            delete root;
            return NULL;
        }
        // Case 2. One Child
        else if(root->left != NULL and root->right == NULL){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->right != NULL and root->left == NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        // Case 3. Two Childs
        else {
            TreeNode* replace = root->right;
            while(replace->left){
                replace = replace->left;
            }
            root->val = replace->val;
            root->right = deleteNode(root->right,replace->val);
            return root;
        }
    } 
    else {
        root->right = deleteNode(root->right,key);
        return root;
    }
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
GAURAV_CHAUDHARY

    Node* root;
    root = createTree();
    childSumProperty(root);
    levelOrder(root);

    return 0;
}

