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
	void topoDfs(int node, vector<int> &vis, stack<int> &s){
		vis[node] = 1;
		for(int n: adj[node]){
			if(!vis[n]){
				topoDfs(n, vis, s);
			}
		}
		s.push(node);
	}

	vector<int> topoSort(){
		vector<int> vis(v,0);
		stack<int> s;
		for(int i=0;i<v;i++){
			if(!vis[i]){
				topoDfs(i,vis,s);
			}
		}
		vector<int> topo;
		while(!s.empty()){
// 			cout<<s.top()<<" ";
			topo.push_back(s.top());
			s.pop();
		}
		return topo;
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