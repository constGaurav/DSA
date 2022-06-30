#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

class Heap {
	vector<int> v;
	bool minHeap;
	
	bool compare(int a, int b){
		if(minHeap){
			return a<b;
		} else return a>b;
	}

	void heapify(int indx){
		int left = 2*indx;
		int right = left+1;
		int min_indx = indx;
		int last = v.size()-1;

		if(left	<= last and compare(v[left],v[indx])){
			min_indx = left;
		}
		if(right <= last and compare(v[right], v[min_indx])){
			min_indx = right; 
		}
		if(min_indx != indx){
			swap(v[indx], v[min_indx]);
			heapify(min_indx);
		}
	}

public:
	Heap(int default_size = 10, bool type = true){
		v.reserve(default_size);
		v.push_back(-1);
		minHeap = type;
	}

	void push(int data){
		v.push_back(data);
		int idx = v.size()-1;
		int parent = idx/2;

		while(idx>1 and compare(v[idx],v[parent])){
			swap(v[idx],v[parent]);
			idx = parent;
			parent = parent/2;
		}
	}

	int top(){
		return v[1];
	}

	void pop(){
		int last = v.size()-1;
		swap(v[1],v[last]);
		v.pop_back();
		heapify(1);
	}

	bool empty(){
		return v.size()==1;
	}
};

int main() {

	Heap h(10,false);
	int n; cin>>n;
	for(int i=0;i<n;i++) {
		int k; cin>>k;
		h.push(k);
	}

	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}

    return 0;
}

