// @MrGaurav - LRU Cache Implementaion.
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

class DLLNode {
public:
	int key,value;
	DLLNode *next, *prev;
	
	DLLNode(int key, int value){
		this->key = key;
		this->value = value;
		this->prev = NULL;
		this->next = NULL;
	}
	
};

unordered_map<int, DLLNode*> cache;
int size;
int capacity;
DLLNode* head = new DLLNode(-1,-1);
DLLNode* tail = new DLLNode(-1,-1);

void addNodeAtHead(DLLNode* node){
	node->prev = head;
	node->next = head->next;
	head->next->prev = node;
	head->next = node;
	return;
}

void removeNode(DLLNode* node){
	DLLNode* tmpPrev = node->prev;
	DLLNode* tmpNext = node->next;
	tmpPrev->next = tmpNext;
	tmpNext->prev = tmpPrev;
}

int removeFromTail(){
	DLLNode* tmpPrev = tail->prev;
	removeNode(tmpPrev);
	return tmpPrev->key;
}

void moveToHead(DLLNode* node){
	cout<<"Accessed the key "<<node->key<<endl;
	removeNode(node);
	addNodeAtHead(node);
}

int get(int k){
	if(cache.count(k) == 0){
		cout<<"Value is not present in the cache.";
		return INT_MIN;
	}
	DLLNode* node = cache[k];
	moveToHead(node);
	return node->value;
}

void put(int k, int v){
	if(cache.count(k) == 0){
		// Key is Not there.
		DLLNode* node = new DLLNode(k,v);
		cache[k] = node;
		cout<<"Added a key "<<k<<endl;
		addNodeAtHead(node);
		capacity++;
		if(capacity>size){
			int removeKey = removeFromTail();
			cout<<"As the cache is Full we need to remove the key "<<removeKey<<endl;
			capacity--;
			cache.erase(removeKey);
		}

	} else {
		// Key is already present.
		DLLNode* node = cache[k];
		cout<<"Key is already present in the cache. So updated the value."<<endl;
		node->value = v;
		moveToHead(node);
	}
}

int main() {
	cout<<"Enter the size of the Cache: ";
	cin>>size;
	cout<<"\nSize of the cache is "<<size<<endl;
	head->next = tail;
	tail->prev = head;
	int q; 
	cout<<"\nEnter the number of Queries: ";
	cin>>q;
	while(q--){
		cout<<"\nEnter 'p' for PUT operation.\nAnd 'g' for GET Operation.\n";
		char ch;
		cin>>ch;
		int k,v;
		if(ch == 'p'){
			cout<<"Enter the key and value: ";
			cin>>k>>v;
			put(k,v);
		} else {
			cout<<"Enter the key: ";
			cin>>k;
			int v = get(k);
			cout<<"Value for key "<<k<<" is "<<v<<endl;
		}
	}

    return 0;
}