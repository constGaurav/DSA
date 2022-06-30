// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

class Graph{
	int v;
	list<int> *adj;
public:
	Graph(int v){
		this->v = v;
		adj = new list<int>[v];
	}
	void addEdge(int x, int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	void print(){
		for(int i=0;i<v;i++){
			cout<<i<<"-> ";
			for(int nbr: adj[i]){
				cout<<nbr<<",";
			}
			cout<<endl;
		}
	}

	void dfs_(int node, vector<int> &vis){
		vis[node] = 1;
		cout<<node<<" ";
		for(auto v: adj[node]){
			if(!vis[v]){
				dfs_(v, vis);
			}
		}
	}

	void dfs(){
		// TC => O(N+E)
		vector<int> vis(v+1,0);
		for(int i=1;i<v;i++){
			if(!vis[i]){
				dfs_(i, vis);
			}
		}
	}
};


int main() {
	Graph g(8);
	g.addEdge(1,2);
	g.addEdge(4,2);
	g.addEdge(4,6);
	g.addEdge(6,7);
	g.addEdge(7,2);
	g.addEdge(3,5);

	g.dfs();
    return 0;
}

