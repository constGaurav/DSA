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

	bool isBipartiteBfs(int node, vector<int> &color, vector<int>adj[]){
		queue<int> q;
		q.push(node);
		color[node] = 1;
		
		while(!q.empty()){
			node = q.front();
			q.pop();
			for(int n: adj[node]){
				if(color[n] == -1){
					color[n] = 1-color[node];
					q.push(n);
				} else if(color[n] == color[node])
					return false;
			}
		}
		return true;
	}

	bool isBipartite(int v, vector<int>adj[]){
		// TC => O(N+E) & SC::: O(N+E) + O(N) + O(N)
		vector<int> color(v,-1);
		for(int i=0;i<v;i++){
			if(color[i] == -1){
				if(!isBipartiteBfs(i,color,adj))
					return false;
			}
		}
		return true;
	}
};


int main() {
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