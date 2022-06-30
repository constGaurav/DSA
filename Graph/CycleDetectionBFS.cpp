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

	bool checkCycleUsingBFS(int node, vector<int> &vis){
		vis[node] = 1;
		queue<pair<int,int>> q;
		q.push({node,-1});

		while(!q.empty()){
			node = q.front().first;
			int parent = q.front().second;
			q.pop();

			for(auto n: adj[node]){
				if(!vis[n]){
					vis[n] = 1;
					q.push({n,node});
				}
				else if(n != parent) 
					return true;;
			}
		}
		return false;
	}
	bool isCycle(){
		// TC => O(N+E) 
	    vector<int> vis(v,0);

		for(int i=0;i<v;i++){
			if(!vis[i]){
				if(checkCycleUsingBFS(i,vis))
					return true;
			}
		}
		return false;
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

	cout<<g.isCycle();
    return 0;
}

