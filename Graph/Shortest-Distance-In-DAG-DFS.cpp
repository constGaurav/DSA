// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

class Graph{
	int v;
	list<pair<int, int>> *adj;
public:
	Graph(int v){
		this->v = v;
		adj = new list<pair<int, int>>[v];
	}
	void addEdge(int x, int y, int w){
		adj[x].push_back({y,w});
	}

	// Find Topological Sort
	void findTopoSort(int node, vector<int> &vis, stack<int> &st){
		vis[node] = 1;
		for(auto n: adj[node]){
			findTopoSort(n.first,vis,st);
		}
		st.push(node);
	}

	// Shortest Distance in Directed Acyclic Graph(DAG) using DFS.
	void shortestDistInDAG(int src){
		vector<int> vis(v,0);
		stack<int> st;
		for(int i=0;i<v;i++){
			if(!vis[i])
				findTopoSort(i,vis,st);
		}

		vector<int> dist(v,INT_MAX);
		dist[src] = 0;
		while(!st.empty()){
			int node = st.top();
			st.pop();
			
			if(dist[node] != INT_MAX){
				for(auto p: adj[node]){
					if(dist[node] + p.second < dist[p.first])
						dist[p.first] = dist[node] + p.second;
				}
			}
		}

		// Our Ans is present in 'Dist'
		for(int i=0;i<v;i++){
			cout<<"Distance of "<<i<<" from "<<src<<" is "<<dist[i]<<endl;
		}
	}

};



int main() {

    return 0;
}

