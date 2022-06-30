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

	void bfs(){
		// TC => O(N+E) & SC::: O(N+E) + O(N) + O(N)
		vector<int> vis(v,0);
		for(int i=1;i<=v;i++){
			if(!vis[i]){
				//Actual BFS Code
				queue<int> q;
				q.push(i);
				vis[i] = 1;
				while(!q.empty()){
					int node = q.front();
					q.pop();
					cout<<node<<" ";

					for(auto j: adj[node]){
						if(!vis[j]){
							q.push(j);
							vis[j] = 1;
						}
					}
				}
			}
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	Graph g(6);
	g.addEdge(1,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(2,5);
	cout<<"GRAPH: ";
	g.bfs();
    return 0;
}

