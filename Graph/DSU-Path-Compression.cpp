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

	// DSU - Path Compression and Rank Union 
	// Find and Union Fucntion ==> TC: O(1)
	
	int findSet(int i, int parent[]){
		if(parent[i] == -1)
			return i;
		return parent[i] = findSet(parent[i],parent);
	}

	void unionSet(int x, int y, int parent[], int rank[]){
		int p1 = findSet(x, parent);
		int p2 = findSet(y, parent);
		if(p1!=p2){
			if(rank[p1] < rank[p2]){
				parent[p1] = p2;
				rank[p2] += rank[p1];
			} else {
				parent[p2] = p1;
				rank[p1] += rank[p2];
			}
		}
	}
};


int main() {
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,1);

	return 0;
}

