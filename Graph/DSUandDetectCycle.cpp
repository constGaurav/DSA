// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

class Graph{
	int v;
	list<pair<int,int>> edgeList;
public:
	Graph(int v){
		this->v = v;
	}

	void addEdge(int x, int y){
		edgeList.push_back({x,y});
	}

	// DSU - Find and Union Fucntion ==>TC: O(N)
	int findSet(int i, int parent[]){
		if(parent[i] == -1)
			return i;
		return findSet(parent[i],parent);
	}

	void unionSet(int x, int y, int parent[]){
		int p1 = findSet(x, parent);
		int p2 = findSet(y, parent);
		if(p1!=p2){
			parent[p1] = p2;
		}
	}

	// Cycle Detection in Graph using DSU
	bool isContainsCycle(){
		int *parent = new int[v];
		for(int i=0;i<v;i++){
			parent[i] = -1;
		}
		for(auto edge: edgeList){
			int a = edge.first;
			int b = edge.second;
			int p1 = findSet(a,parent);
			int p2 = findSet(b,parent);

			if(p1 != p2){
				unionSet(a,b,parent);
			} else {
				cout<<"Cycle is present"<<endl;
				return true;
			}
		}
		delete []parent;
		return false;
	}
};


int main() {
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,1);

	cout<<g.isContainsCycle();
	return 0;
}

