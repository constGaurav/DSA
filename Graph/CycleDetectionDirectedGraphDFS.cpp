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

	bool isCycleDfs(int node, vector<int> &vis, vector<int> &dfsVis){
		vis[node] = 1;
		dfsVis[node] = 1;
		for(int n: adj[node]){
			if(!vis[n]){
				if(isCycleDfs(n,vis,dfsVis)) return true;
			} else if(dfsVis[n])
				return true;
		}
		dfsVis[node] = 0;
		return false;
	}

	bool isCyclic(){
		// Directed Graph
		vector<int> vis(v,0),dfsVis(v,0);
		for(int i=0;i<v;i++){
			if(!vis[i]){
				if(isCycleDfs(i,vis,dfsVis)) 
					return true;
			}
		}
		return false;
	}
};


int main() {
	Graph g(6);
	g.addEdge(1,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(2,5);
	
    return 0;
}