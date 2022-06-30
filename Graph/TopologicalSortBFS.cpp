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
	
	// Topological Sort (BFS) -> Kahn's Algorithm
	void topologicalSort(){
		queue<int> q;
		vector<int> inDegree(v,0);
		for(int i=0;i<v;i++){
			for(int n: adj[i])
				inDegree[n]++;
		}
		for(int i=0;i<v;i++){
			if(inDegree[i]==0)
				q.push(i);
		}
		vector<int> topo;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for(int n: adj[node]){
				inDegree[n]--;
				if(inDegree[n]==0)
					q.push(n);
			}
		}
		// return topo;
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