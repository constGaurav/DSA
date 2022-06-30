// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

class Graph{
							   //vertex weight
	unordered_map<int, vector<pair<int, int>>> adj;
public:
	void addEdge(int x, int y, int w){
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}

	void print(){
		for (auto itr = adj.begin(); itr != adj.end(); ++itr) {
	        cout << itr->first<<" => ";
	        for(auto v: itr->second){
	        	cout<<"("<<v.first<<", "<<v.second<<") ";
	        }
	        cout<<endl;
	    }
	}
};


int main() {
	Graph g;
	g.addEdge(0,2,100);
	g.addEdge(3,1,120);
	g.addEdge(0,3,95);
	g.addEdge(2,3,150);
	g.addEdge(3,4,102);
    
	g.print();
    return 0;
}

