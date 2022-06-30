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

	void shortestDistUsingBFS(int src){
		vector<int> dist(v,INT_MAX);
		queue<int> q;
		q.push(src);
		dist[src] = 0;

		while(!q.empty()){
			int vertex = q.front();
			q.pop();

			for(int v: adj[vertex]){
				if(dist[v] == INT_MAX){
					q.push(v);
					dist[v] = dist[vertex] + 1;
				}
			}
		}

		for(int i=0;i<v;i++){
			cout<<"Shortest Distance of "<<i<<" from "<<src<<": "<<dist[i]<<endl;
		}
	}
};



int main() {
	Graph g(6);
	g.addEdge(1,0);
	g.addEdge(1,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(2,5);
	g.shortestDistUsingBFS(0);
    return 0;
}

