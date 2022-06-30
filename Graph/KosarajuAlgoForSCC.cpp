// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

void dfs(vector<int> graph[], int i, bool *vis, vector<int> &stack){
	vis[i] = true;
	for(auto nbr: graph[i]){
		if(!vis[nbr]){
			dfs(graph, nbr, vis, stack);
		}
	}
	// Function call is complete.
	stack.push_back(i);
}

void dfs2(vector<int> graph[], int i, bool *vis){
	vis[i] = true;
	cout<<i<<" ";
	for(auto nbr: graph[i]){
		if(!vis[nbr]){
			dfs2(graph, nbr, vis);
		}
	}
}

void kosarajuAlgo(vector<int> graph[],vector<int> rev_graph[],int v){
	bool vis[v];
	memset(vis,0,v);

	vector<int> stack;

	// Step1: Need store the vertices acc to dfs finish time.
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(graph,i,vis,stack);
		}
	}

	// Step2: Reverse graph edge direction (Already Done - rev_graph)
	// Step3: Do dfs according to ordering given in the stack.
	
	memset(vis,false,v);

	char component_name = 'A';

	for(int x = stack.size()-1;x>=0;x--){
		int node = stack[x];
		if(!vis[node]){
			cout<<"Component "<<component_name<<"---> ";
			// There is component starting from this node.
			dfs2(rev_graph,node,vis);
			cout<<endl;
			component_name++;
		}
	}	

}

int main() {
	
	int v,m; cin>>v>>m;
	vector<int> graph[v]; 
	vector<int> rev_graph[v];


	while(m--){
		int x,y; cin>>x>>y;
		graph[x].push_back(y);
		rev_graph[y].push_back(x);
	}

	kosarajuAlgo(graph,rev_graph,v);

	return 0;
}

